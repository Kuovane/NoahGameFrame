// -------------------------------------------------------------------------
//    @FileName			:    NFCLoginNet_ServerModule.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-01-02
//    @Module           :    NFCLoginNet_ServerModule
//    @Desc             :
// -------------------------------------------------------------------------

#include "NFCLoginNet_ServerModule.h"
#include "NFLoginNet_ServerPlugin.h"
#include "NFComm/NFMessageDefine/NFProtocolDefine.hpp"
#include "Dependencies/RapidXML/rapidxml.hpp"
#include "Dependencies/RapidXML/rapidxml_iterators.hpp"
#include "Dependencies/RapidXML/rapidxml_print.hpp"
#include "Dependencies/RapidXML/rapidxml_utils.hpp"
#include "NFComm/NFPluginLoader/NFCPluginManager.h"

bool NFCLoginNet_ServerModule::Init()
{
	m_pNetModule = pPluginManager->FindModule<NFINetModule>();
	m_pKernelModule = pPluginManager->FindModule<NFIKernelModule>();
	m_pLogModule = pPluginManager->FindModule<NFILogModule>();
	m_pClassModule = pPluginManager->FindModule<NFIClassModule>();
	m_pElementModule = pPluginManager->FindModule<NFIElementModule>();
	m_pNetClientModule = pPluginManager->FindModule<NFINetClientModule>();
	m_pLoginToMasterModule = pPluginManager->FindModule<NFILoginToMasterModule>();


	//m_sUpdateZipUrl = "http://127.0.0.1:9527/update.zip";
	//m_nCurVersion = 2;
	m_sConfigName = "UpdateConfig.xml";

#ifdef NF_DEBUG_MODE
	m_sConfigName = "NFDataCfg/Debug/" + m_sConfigName;
#else
	m_sConfigName = "NFDataCfg/Release/" + m_sConfigName;
#endif

	return true;
}

bool NFCLoginNet_ServerModule::Shut()
{
	return true;
}

bool NFCLoginNet_ServerModule::BeforeShut()
{
	return true;
}

bool NFCLoginNet_ServerModule::AfterInit()
{
	m_pNetModule->AddReceiveCallBack(NFMsg::EGMI_STS_HEART_BEAT, this, &NFCLoginNet_ServerModule::OnHeartBeat);
	m_pNetModule->AddReceiveCallBack(NFMsg::EGMI_REQ_VERSION, this, &NFCLoginNet_ServerModule::OnVersionCheck);
	m_pNetModule->AddReceiveCallBack(NFMsg::EGMI_REQ_LOGIN, this, &NFCLoginNet_ServerModule::OnLoginProcess);
	m_pNetModule->AddReceiveCallBack(NFMsg::EGMI_REQ_LOGOUT, this, &NFCLoginNet_ServerModule::OnLogOut);
	m_pNetModule->AddReceiveCallBack(NFMsg::EGMI_REQ_CONNECT_WORLD, this, &NFCLoginNet_ServerModule::OnSelectWorldProcess);
	m_pNetModule->AddReceiveCallBack(NFMsg::EGMI_REQ_WORLD_LIST, this, &NFCLoginNet_ServerModule::OnViewWorldProcess);
	m_pNetModule->AddReceiveCallBack(this, &NFCLoginNet_ServerModule::InvalidMessage);

	m_pNetModule->AddEventCallBack(this, &NFCLoginNet_ServerModule::OnSocketClientEvent);
	m_pNetModule->ExpandBufferSize();

	NF_SHARE_PTR<NFIClass> xLogicClass = m_pClassModule->GetElement(NFrame::Server::ThisName());
	if (xLogicClass)
	{
		const std::vector<std::string>& strIdList = xLogicClass->GetIDList();
		for (int i = 0; i < strIdList.size(); ++i)
		{
			const std::string& strId = strIdList[i];

			const int nServerType = m_pElementModule->GetPropertyInt32(strId, NFrame::Server::Type());
			const int nServerID = m_pElementModule->GetPropertyInt32(strId, NFrame::Server::ServerID());
			if (nServerType == NF_SERVER_TYPES::NF_ST_LOGIN && pPluginManager->GetAppID() == nServerID)
			{
				const int nPort = m_pElementModule->GetPropertyInt32(strId, NFrame::Server::Port());
				const int nMaxConnect = m_pElementModule->GetPropertyInt32(strId, NFrame::Server::MaxOnline());
				const int nCpus = m_pElementModule->GetPropertyInt32(strId, NFrame::Server::CpuCount());

				int nRet = m_pNetModule->Initialization(nMaxConnect, nPort, nCpus);
				if (nRet < 0)
				{
					std::ostringstream strLog;
					strLog << "Cannot init server net, Port = " << nPort;
					m_pLogModule->LogNormal(NFILogModule::NLL_ERROR_NORMAL, NULL_OBJECT, strLog, __FUNCTION__, __LINE__);
					NFASSERT(nRet, "Cannot init server net", __FILE__, __FUNCTION__);
					exit(0);
				}
			}
		}
	}

	return true;
}

int NFCLoginNet_ServerModule::OnSelectWorldResultsProcess(const int nWorldID, const NFGUID xSenderID, const int nLoginID, const std::string& strAccount, const std::string& strWorldIP, const int nWorldPort, const std::string& strWorldKey)
{
	NF_SHARE_PTR<NFSOCK> xFD = mxClientIdent.GetElement(xSenderID);
	if (xFD)
	{
		NFMsg::AckConnectWorldResult xMsg;
		xMsg.set_world_id(nWorldID);
		xMsg.mutable_sender()->CopyFrom(NFINetModule::NFToPB(xSenderID));
		xMsg.set_login_id(nLoginID);
		xMsg.set_account(strAccount);
		xMsg.set_world_ip(strWorldIP);
		xMsg.set_world_port(nWorldPort);
		xMsg.set_world_key(strWorldKey);

		m_pNetModule->SendMsgPB(NFMsg::EGameMsgID::EGMI_ACK_CONNECT_WORLD, xMsg, *xFD);
	}

	return 0;
}

bool NFCLoginNet_ServerModule::Execute()
{
	return true;
}

void NFCLoginNet_ServerModule::OnClientConnected(const NFSOCK nAddress)
{
	NetObject* pObject = m_pNetModule->GetNet()->GetNetObject(nAddress);
	if (pObject)
	{
		NFGUID xIdent = m_pKernelModule->CreateGUID();
		pObject->SetClientID(xIdent);
		mxClientIdent.AddElement(xIdent, NF_SHARE_PTR<NFSOCK>(NF_NEW NFSOCK(nAddress)));
	}
}

void NFCLoginNet_ServerModule::OnClientDisconnect(const NFSOCK nAddress)
{
	NetObject* pObject = m_pNetModule->GetNet()->GetNetObject(nAddress);
	if (pObject)
	{
		NFGUID xIdent = pObject->GetClientID();
		mxClientIdent.RemoveElement(xIdent);
	}
}

static bool removeFile(const char* pFileName)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	return 0 == _unlink(pFileName);
#else
	return 0 == unlink(pFileName);
#endif
}

static void  getVersionInfo(int versionCode, int &mainVersion, int &subVersion, int &bugVersion)
{
	mainVersion = versionCode / 1000000;
	subVersion = (versionCode - mainVersion * 1000000) / 1000;
	bugVersion = versionCode - mainVersion * 1000000 - subVersion * 1000;
}

void NFCLoginNet_ServerModule::ReadUpdateConfig()
{
	std::string strContent;
	std::string strFilePath = pPluginManager->GetConfigPath() + m_sConfigName;

#ifdef NF_DEBUG_MODE
	std::string sTempFile = "NFDataCfg/Debug/NeedUpdate" ;
#else
	std::string sTempFile = "NFDataCfg/Release/NeedUpdate";
#endif

	std::string strNeedUpdate = pPluginManager->GetConfigPath() + sTempFile;

	bool ret = pPluginManager->GetFileContent(strNeedUpdate, strContent);
	if (ret)
	{
		pPluginManager->GetFileContent(strFilePath, strContent);

		rapidxml::xml_document<> xDoc;
		xDoc.parse<0>((char*)strContent.c_str());

		rapidxml::xml_node<>* pRoot = xDoc.first_node();
		m_sUpdatePackage.clear();
		if (pRoot)
		{
			for (rapidxml::xml_node<>* _var = (pRoot)->first_node("package"); _var; _var = _var->next_sibling("package"))
			{
				NFCUpdatePackage sPackage;
				rapidxml::xml_node<>* pAppVaersionNode = _var->first_node("vertion");


				char* strTemp = pAppVaersionNode->first_attribute("value")->value();
				sPackage.m_nVersionCode = atoi(strTemp);

				getVersionInfo(sPackage.m_nVersionCode, sPackage.m_mainVersion, sPackage.m_subVersion, sPackage.m_bugVersion);

				rapidxml::xml_node<>* pUrlNode = pAppVaersionNode->next_sibling("update_url");
				sPackage.m_sUpdateZipUrl = pUrlNode->first_attribute("value")->value();

				rapidxml::xml_node<>* pSpecialNode = pAppVaersionNode->next_sibling("specialIps");



				m_sUpdatePackage[sPackage.m_nVersionCode] = sPackage;
			 }
			
			

		}

		removeFile(strNeedUpdate.c_str());
	}
}




void NFCLoginNet_ServerModule::OnVersionCheck(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen)
{
	NFGUID nPlayerID;
	NFMsg::ReqCheckVersion xMsg;
	if (!m_pNetModule->ReceivePB(nMsgID, msg, nLen, xMsg, nPlayerID))
	{
		return;
	}

	ReadUpdateConfig();

	NFMsg::AckVersionCheck xData;
	int mainVersion, subVersion, bugVersion;
	getVersionInfo(xMsg.verioncode(), mainVersion, subVersion, bugVersion);

	for (auto it = m_sUpdatePackage.begin(); it != m_sUpdatePackage.end(); it++)
	{
		if (mainVersion == it->second.m_mainVersion && subVersion == it->second.m_subVersion && bugVersion < it->second.m_bugVersion)
		{
			xData.set_returncode(NFMsg::AckVersionCheck::UpdateLua);
			xData.set_pageurl("");
			xData.set_downloadurl(it->second.m_sUpdateZipUrl);
			break;
		}
		else
		{
			xData.set_returncode(NFMsg::AckVersionCheck::DisUpdate);
		}
	}
	
	
	

	m_pNetModule->SendMsgPB(NFMsg::EGameMsgID::EGMI_ACK_VERSION, xData, nSockIndex);
}

void NFCLoginNet_ServerModule::OnLoginProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen)
{
	NFGUID nPlayerID;
	NFMsg::ReqAccountLogin xMsg;
	if (!m_pNetModule->ReceivePB( nMsgID, msg, nLen, xMsg, nPlayerID))
	{
		return;
	}

	NetObject* pNetObject = m_pNetModule->GetNet()->GetNetObject(nSockIndex);
	if (pNetObject)
	{
		if (pNetObject->GetConnectKeyState() == 0)
		{
			int nState = 0;//successful
			if (0 != nState)
			{
				std::ostringstream strLog;
				strLog << "Check password failed, Account = " << xMsg.account() << " Password = " << xMsg.password();
				m_pLogModule->LogNormal(NFILogModule::NLL_ERROR_NORMAL, NFGUID(0, nSockIndex), strLog, __FUNCTION__, __LINE__);

				NFMsg::AckEventResult xMsg;
				xMsg.set_event_code(NFMsg::EGEC_ACCOUNTPWD_INVALID);

				m_pNetModule->SendMsgPB(NFMsg::EGameMsgID::EGMI_ACK_LOGIN, xMsg, nSockIndex);
				return;
			}

			pNetObject->SetConnectKeyState(1);
			pNetObject->SetAccount(xMsg.account());

			NFMsg::AckEventResult xData;
			xData.set_event_code(NFMsg::EGEC_ACCOUNT_SUCCESS);

			m_pNetModule->SendMsgPB(NFMsg::EGameMsgID::EGMI_ACK_LOGIN, xData, nSockIndex);

			m_pLogModule->LogNormal(NFILogModule::NLL_INFO_NORMAL, NFGUID(0, nSockIndex), "Login successed :", xMsg.account().c_str());
		}
	}
}

void NFCLoginNet_ServerModule::OnSelectWorldProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen)
{
	NFGUID nPlayerID;
	NFMsg::ReqConnectWorld xMsg;
	if (!m_pNetModule->ReceivePB( nMsgID, msg, nLen, xMsg, nPlayerID))
	{
		return;
	}

	NetObject* pNetObject = m_pNetModule->GetNet()->GetNetObject(nSockIndex);
	if (!pNetObject)
	{
		return;
	}

	
	if (pNetObject->GetConnectKeyState() <= 0)
	{
		return;
	}

	NFMsg::ReqConnectWorld xData;
	xData.set_world_id(xMsg.world_id());
	xData.set_login_id(pPluginManager->GetAppID());
	xData.mutable_sender()->CopyFrom(NFINetModule::NFToPB(pNetObject->GetClientID()));
	xData.set_account(pNetObject->GetAccount());

	m_pNetClientModule->SendSuitByPB(NF_SERVER_TYPES::NF_ST_MASTER, pNetObject->GetAccount(), NFMsg::EGameMsgID::EGMI_REQ_CONNECT_WORLD, xData);//here has a problem to be solve
}

void NFCLoginNet_ServerModule::OnSocketClientEvent(const NFSOCK nSockIndex, const NF_NET_EVENT eEvent, NFINet* pNet)
{
	if (eEvent & NF_NET_EVENT_EOF)
	{
		m_pLogModule->LogNormal(NFILogModule::NLL_INFO_NORMAL, NFGUID(0, nSockIndex), "NF_NET_EVENT_EOF", "Connection closed", __FUNCTION__, __LINE__);
		OnClientDisconnect(nSockIndex);
	}
	else if (eEvent & NF_NET_EVENT_ERROR)
	{
		m_pLogModule->LogNormal(NFILogModule::NLL_INFO_NORMAL, NFGUID(0, nSockIndex), "NF_NET_EVENT_ERROR", "Got an error on the connection", __FUNCTION__, __LINE__);
		OnClientDisconnect(nSockIndex);
	}
	else if (eEvent & NF_NET_EVENT_TIMEOUT)
	{
		m_pLogModule->LogNormal(NFILogModule::NLL_INFO_NORMAL, NFGUID(0, nSockIndex), "NF_NET_EVENT_TIMEOUT", "read timeout", __FUNCTION__, __LINE__);
		OnClientDisconnect(nSockIndex);
	}
	else  if (eEvent == NF_NET_EVENT_CONNECTED)
	{
		m_pLogModule->LogNormal(NFILogModule::NLL_INFO_NORMAL, NFGUID(0, nSockIndex), "NF_NET_EVENT_CONNECTED", "connectioned success", __FUNCTION__, __LINE__);
		OnClientConnected(nSockIndex);
	}
}

void NFCLoginNet_ServerModule::SynWorldToClient(const NFSOCK nFD)
{
	NFMsg::AckServerList xData;
	xData.set_type(NFMsg::RSLT_WORLD_SERVER);

	NFMapEx<int, NFMsg::ServerInfoReport>& xWorldMap = m_pLoginToMasterModule->GetWorldMap();
	NFMsg::ServerInfoReport* pWorldData = xWorldMap.FirstNude();
	while (pWorldData)
	{
		NFMsg::ServerInfo* pServerInfo = xData.add_info();

		pServerInfo->set_name(pWorldData->server_name());
		pServerInfo->set_status(pWorldData->server_state());
		pServerInfo->set_server_id(pWorldData->server_id());
		pServerInfo->set_wait_count(0);

		pWorldData = xWorldMap.NextNude();
	}


	m_pNetModule->SendMsgPB(NFMsg::EGameMsgID::EGMI_ACK_WORLD_LIST, xData, nFD);
}

void NFCLoginNet_ServerModule::OnViewWorldProcess(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen)
{
	NFGUID nPlayerID;
	NFMsg::ReqServerList xMsg;
	if (!m_pNetModule->ReceivePB( nMsgID, msg, nLen, xMsg, nPlayerID))
	{
		return;
	}

	if (xMsg.type() == NFMsg::RSLT_WORLD_SERVER)
	{
		SynWorldToClient(nSockIndex);
	}
}

void NFCLoginNet_ServerModule::OnHeartBeat(const NFSOCK nSockIndex, const int nMsgID, const char * msg, const uint32_t nLen)
{
}

void NFCLoginNet_ServerModule::OnLogOut(const NFSOCK nSockIndex, const int nMsgID, const char * msg, const uint32_t nLen)
{
}

void NFCLoginNet_ServerModule::InvalidMessage(const NFSOCK nSockIndex, const int nMsgID, const char * msg, const uint32_t nLen)
{
	printf("NFNet || unMsgID=%d\n", nMsgID);
}
