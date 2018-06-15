// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: NFDefine.proto

#ifndef PROTOBUF_NFDefine_2eproto__INCLUDED
#define PROTOBUF_NFDefine_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace NFMsg {

// Internal implementation detail -- do not call these.
void LIBPROTOC_EXPORT protobuf_AddDesc_NFDefine_2eproto();
void protobuf_AssignDesc_NFDefine_2eproto();
void protobuf_ShutdownFile_NFDefine_2eproto();


enum EGameEventCode {
  EGEC_SUCCESS = 0,
  EGEC_UNKOWN_ERROR = 1,
  EGEC_ACCOUNT_EXIST = 2,
  EGEC_ACCOUNTPWD_INVALID = 3,
  EGEC_ACCOUNT_USING = 4,
  EGEC_ACCOUNT_LOCKED = 5,
  EGEC_ACCOUNT_SUCCESS = 6,
  EGEC_VERIFY_KEY_SUCCESS = 7,
  EGEC_VERIFY_KEY_FAIL = 8,
  EGEC_SELECTSERVER_SUCCESS = 9,
  EGEC_SELECTSERVER_FAIL = 10,
  EGEC_CHARACTER_EXIST = 110,
  EGEC_SVRZONEID_INVALID = 111,
  EGEC_CHARACTER_NUMOUT = 112,
  EGEC_CHARACTER_INVALID = 113,
  EGEC_CHARACTER_NOTEXIST = 114,
  EGEC_CHARACTER_USING = 115,
  EGEC_CHARACTER_LOCKED = 116,
  EGEC_ZONE_OVERLOAD = 117,
  EGEC_NOT_ONLINE = 118,
  EGEC_ALREAY_IN_TEAM = 119,
  EGEC_INVALID_TEAM_INVITE = 120,
  EGEC_TEAM_FULL = 121,
  EGEC_MAIL_UPDATE_ERROR = 122,
  EGEC_MAIL_TONAME_INVALID = 123,
  EGEC_MAIL_DELETE_ERROR = 124,
  EGEC_MAIL_TOWNAME_EQUAL = 125,
  EGEC_LACK_MONEY = 126,
  EGEC_FULL_PACKAGE = 127,
  EGEC_INVALID_ITEM = 128,
  EGEC_INVALID_CONSIGNMENT = 129,
  EGEC_NOT_ENOUGH_VIP = 130,
  EGEC_NEED_LEVEL = 131,
  EGEC_MAX_FRIEND_LIST = 132,
  EGEC_MAX_ENEMY_LIST = 133,
  EGEC_MAX_GANGS_LSIT = 134,
  EGEC_LIMITS_TO_RIGHTS = 135,
  EGEC_INVALID_GANGS_NAME = 136,
  EGEC_REPEAT_ENTER_GANGS = 137,
  EGEC_INVALID_GANGSMEMBER = 138,
  EGEC_MASTER_LEAVE_GANGS = 139,
  EGEC_GANGS_TITLE_OUTOF = 140,
  EGEC_ENTER_GATEWAY_FAILD = 141,
  EGEC_NO_SERVER4ZONE = 142,
  EGEC_INVALID_SKILL = 143,
  EGEC_CREATE_GUILD_SUCCESS = 200,
  EGEC_JOIN_GUILD_SUCCESS = 201,
  EGEC_LEAVE_GUILD_SUCCESS = 202
};
LIBPROTOC_EXPORT bool EGameEventCode_IsValid(int value);
const EGameEventCode EGameEventCode_MIN = EGEC_SUCCESS;
const EGameEventCode EGameEventCode_MAX = EGEC_LEAVE_GUILD_SUCCESS;
const int EGameEventCode_ARRAYSIZE = EGameEventCode_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGameEventCode_descriptor();
inline const ::std::string& EGameEventCode_Name(EGameEventCode value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameEventCode_descriptor(), value);
}
inline bool EGameEventCode_Parse(
    const ::std::string& name, EGameEventCode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameEventCode>(
    EGameEventCode_descriptor(), name, value);
}
enum ESynMsgID {
  ESMI_UNKNOW = 0
};
LIBPROTOC_EXPORT bool ESynMsgID_IsValid(int value);
const ESynMsgID ESynMsgID_MIN = ESMI_UNKNOW;
const ESynMsgID ESynMsgID_MAX = ESMI_UNKNOW;
const int ESynMsgID_ARRAYSIZE = ESynMsgID_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* ESynMsgID_descriptor();
inline const ::std::string& ESynMsgID_Name(ESynMsgID value) {
  return ::google::protobuf::internal::NameOfEnum(
    ESynMsgID_descriptor(), value);
}
inline bool ESynMsgID_Parse(
    const ::std::string& name, ESynMsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ESynMsgID>(
    ESynMsgID_descriptor(), name, value);
}
enum EGameMsgID {
  EGMI_UNKNOW = 0,
  EGMI_EVENT_RESULT = 1,
  EGMI_EVENT_TRANSPOND = 2,
  EGMI_CLOSE_SOCKET = 3,
  EGMI_WTM_WORLD_REGISTERED = 10,
  EGMI_WTM_WORLD_UNREGISTERED = 11,
  EGMI_WTM_WORLD_REFRESH = 12,
  EGMI_LTM_LOGIN_REGISTERED = 20,
  EGMI_LTM_LOGIN_UNREGISTERED = 21,
  EGMI_LTM_LOGIN_REFRESH = 22,
  EGMI_PTWG_PROXY_REGISTERED = 30,
  EGMI_PTWG_PROXY_UNREGISTERED = 31,
  EGMI_PTWG_PROXY_REFRESH = 32,
  EGMI_GTW_GAME_REGISTERED = 40,
  EGMI_GTW_GAME_UNREGISTERED = 41,
  EGMI_GTW_GAME_REFRESH = 42,
  EGMI_GTW_AI_REGISTERED = 60,
  EGMI_GTW_AI_UNREGISTERED = 61,
  EGMI_GTW_AI_REFRESH = 62,
  EGMI_STS_NET_INFO = 50,
  EGMI_STS_SERVER_REPORT = 90,
  EGMI_STS_HEART_BEAT = 100,
  EGMI_REQ_LOGIN = 101,
  EGMI_ACK_LOGIN = 102,
  EGMI_REQ_LOGOUT = 103,
  EGMI_REQ_VERSION = 106,
  EGMI_ACK_VERSION = 107,
  EGMI_REQ_WORLD_LIST = 110,
  EGMI_ACK_WORLD_LIST = 111,
  EGMI_REQ_CONNECT_WORLD = 112,
  EGMI_ACK_CONNECT_WORLD = 113,
  EGMI_REQ_KICK_CLIENT_INWORLD = 114,
  EGMI_REQ_CONNECT_KEY = 120,
  EGMI_ACK_CONNECT_KEY = 122,
  EGMI_REQ_SELECT_SERVER = 130,
  EGMI_ACK_SELECT_SERVER = 131,
  EGMI_REQ_ROLE_LIST = 132,
  EGMI_ACK_ROLE_LIST = 133,
  EGMI_REQ_CREATE_ROLE = 134,
  EGMI_REQ_DELETE_ROLE = 135,
  EGMI_REQ_RECOVER_ROLE = 136,
  EGMI_REQ_ENTER_GAME = 150,
  EGMI_ACK_ENTER_GAME = 151,
  EGMI_REQ_LEAVE_GAME = 152,
  EGMI_ACK_LEAVE_GAME = 153,
  EGMI_REQ_SWAP_GAME = 154,
  EGMI_REQ_SWAP_SCENE = 155,
  EGMI_ACK_SWAP_SCENE = 156,
  EGMI_REQ_SWAP_HOME_SCENE = 157,
  EGMI_ACK_SWAP_HOME_SCENE = 158,
  EGMI_REQ_ENTER_GAME_FINISH = 159,
  EGMI_ACK_ENTER_GAME_FINISH = 160,
  EGMI_REQ_ACK_RELIVE = 180,
  EGMI_ACK_OBJECT_ENTRY = 200,
  EGMI_ACK_OBJECT_LEAVE = 201,
  EGMI_ACK_OBJECT_PROPERTY_ENTRY = 202,
  EGMI_ACK_OBJECT_RECORD_ENTRY = 203,
  EGMI_ACK_PROPERTY_INT = 210,
  EGMI_ACK_PROPERTY_FLOAT = 211,
  EGMI_ACK_PROPERTY_STRING = 212,
  EGMI_ACK_PROPERTY_OBJECT = 214,
  EGMI_ACK_PROPERTY_VECTOR2 = 215,
  EGMI_ACK_PROPERTY_VECTOR3 = 216,
  EGMI_ACK_ADD_ROW = 220,
  EGMI_ACK_REMOVE_ROW = 221,
  EGMI_ACK_SWAP_ROW = 222,
  EGMI_ACK_RECORD_INT = 223,
  EGMI_ACK_RECORD_FLOAT = 224,
  EGMI_ACK_RECORD_STRING = 226,
  EGMI_ACK_RECORD_OBJECT = 227,
  EGMI_ACK_RECORD_VECTOR2 = 228,
  EGMI_ACK_RECORD_VECTOR3 = 229,
  EGMI_ACK_RECORD_CLEAR = 250,
  EGMI_ACK_RECORD_SORT = 251,
  EGMI_ACK_DATA_FINISHED = 260,
  EGMI_REQ_START_OPPNENT = 1220,
  EGMI_ACK_START_OPPNENT = 1221,
  EGMI_REQ_END_OPPNENT = 1222,
  EGMI_ACK_END_OPPNENT = 1223,
  EGMI_REQ_SEARCH_OPPNENT = 1224,
  EGMI_ACK_SEARCH_OPPNENT = 1225,
  EGMI_REQ_ADJUST_GAMBLE = 1226,
  EGMI_REQ_MOVE = 1230,
  EGMI_ACK_MOVE = 1231,
  EGMI_REQ_MOVE_IMMUNE = 1232,
  EGMI_ACK_MOVE_IMMUNE = 1233,
  EGMI_REQ_STATE_SYNC = 1234,
  EGMI_ACK_STATE_SYNC = 1235,
  EGMI_REQ_SKILL_OBJECTX = 1240,
  EGMI_ACK_SKILL_OBJECTX = 1241,
  EGMI_REQ_SKILL_POS = 1242,
  EGMI_ACK_SKILL_POS = 1243,
  EGMI_REQ_ITEM_OBJECT = 1244,
  EGMI_ACK_ITEM_OBJECT = 1245,
  EGMI_REQ_ITEM_POS = 1246,
  EGMI_ACK_ITEM_POS = 1247,
  EGMI_REQ_CHAT = 1250,
  EGMI_ACK_CHAT = 1251,
  EGMI_REQ_SALE_ITEM = 1252,
  EGMI_REQ_SPLIT_ITEM = 1253,
  EGMI_REQ_PRODUCE_ITEM = 1254,
  EGMI_REQ_PICK_ITEM = 1255,
  EGMI_REQ_ACCEPT_TASK = 1256,
  EGMI_REQ_COMPELETE_TASK = 1257,
  EGMI_ACK_ONLINE_NOTIFY = 1290,
  EGMI_ACK_OFFLINE_NOTIFY = 1291,
  EGMI_REQ_CREATE_GUILD = 1300,
  EGMI_ACK_CREATE_GUILD = 1301,
  EGMI_REQ_JOIN_GUILD = 1302,
  EGMI_ACK_JOIN_GUILD = 1303,
  EGMI_REQ_LEAVE_GUILD = 1304,
  EGMI_ACK_LEAVE_GUILD = 1305,
  EGMI_REQ_OPR_GUILD = 1306,
  EGMI_ACK_OPR_GUILD = 1307,
  EGMI_REQ_SEARCH_GUILD = 1308,
  EGMI_ACK_SEARCH_GUILD = 1309,
  EGMI_REQ_OPR_GUILDINFO = 1310,
  EGMI_ACK_OPR_GUILDINFO = 1311,
  EGMI_REQ_GUILDECTYPEINFO = 1312,
  EGMI_ACK_GUILDECTYPEINFO = 1313,
  EGMI_SET_GUILDECTYPEINFO = 1314,
  EGMI_ReqEnterGuildEctype = 1315,
  EGEC_REQ_CREATE_CHATGROUP = 1400,
  EGEC_ACK_CREATE_CHATGROUP = 1401,
  EGEC_REQ_JOIN_CHATGROUP = 1402,
  EGEC_ACK_JOIN_CHATGROUP = 1403,
  EGEC_REQ_LEAVE_CHATGROUP = 1404,
  EGEC_ACK_LEAVE_CHATGROUP = 1405,
  EGEC_REQ_SUBSCRIPTION_CHATGROUP = 1406,
  EGEC_REQ_CANCELSUBSCRIPTION_CHATGROUP = 1407,
  EGEC_REQ_INVITE_CHATGROUP = 1408,
  EGEC_ACK_INVITE_CHATGROUP = 1409,
  EGEC_REQ_KICK_CHATGROUP = 1410,
  EGEC_ACK_KICK_CHATGROUP = 1411,
  EGEC_REQ_CHATGROUP_TO_TEAM = 1450,
  EGEC_ACK_CHATGROUP_TO_TEAM = 1451,
  EGEC_REQ_INTENSIFYLEVEL_TO_EQUIP = 1500,
  EGEC_ACK_INTENSIFYLEVEL_TO_EQUIP = 1501,
  EGEC_REQ_HOLE_TO_EQUIP = 1502,
  EGEC_ACK_HOLE_TO_EQUIP = 1503,
  EGEC_REQ_INLAYSTONE_TO_EQUIP = 1504,
  EGEC_ACK_INLAYSTONE_TO_EQUIP = 1505,
  EGEC_REQ_ELEMENTLEVEL_TO_EQUIP = 1506,
  EGEC_ACK_ELEMENTLEVEL_TO_EQUIP = 1507,
  EGEC_WEAR_EQUIP = 1508,
  EGEC_TAKEOFF_EQUIP = 1509,
  EGEC_REQ_SET_FIGHT_HERO = 1520,
  EGEC_REQ_SWITCH_FIGHT_HERO = 1521,
  EGEC_REQ_MINING_TITLE = 1600,
  EGEC_ACK_MINING_TITLE = 1601,
  EGEC_REQ_SEND_MAIL = 1700,
  EGEC_REQ_DRAW_MAIL = 1701,
  EGEC_REQ_DELETE_MAIL = 1702,
  EGMI_ACK_CLONE_OBJECT_ENTRY = 1800,
  EGMI_ACK_CLONE_OBJECT_LEAVE = 1801,
  EGMI_ACK_CLONE_OBJECT_PROPERTY_ENTRY = 1802,
  EGMI_ACK_CLONE_OBJECT_RECORD_ENTRY = 1803,
  EGMI_ACK_CLONE_PROPERTY_INT = 1810,
  EGMI_ACK_CLONE_PROPERTY_FLOAT = 1811,
  EGMI_ACK_CLONE_PROPERTY_STRING = 1812,
  EGMI_ACK_CLONE_PROPERTY_OBJECT = 1814,
  EGMI_REQSWICHSERVER = 1840,
  EGMI_ACKSWICHSERVER = 1841,
  EGMI_REQ_CREATE_TEAM = 1860,
  EGMI_ACK_CREATE_TEAM = 1861,
  EGMI_REQ_JOIN_TEAM = 1862,
  EGMI_ACK_JOIN_TEAM = 1863,
  EGMI_REQ_LEAVE_TEAM = 1864,
  EGMI_ACK_LEAVE_TEAM = 1865,
  EGMI_REQ_INVITE_TEAM = 1866,
  EGMI_REQ_OPRMEMBER_TEAM = 1867,
  EGMI_ACK_OPRMEMBER_TEAM = 1868,
  EGMI_REQ_TEAM_ENTER_ECTYPE = 1869,
  EGMI_ACK_TEAM_ENTER_ECTYPE = 1870,
  EGMI_REQ_MAP_GRID_INFO = 1900,
  EGMI_ACK_MAP_GRID_INFO = 1901,
  EGMI_REQ_BIG_MAP_INFO = 1902,
  EGMI_ACK_BIG_MAP_INFO = 1903,
  EGMI_REQ_HOLD_MAP_GRID = 1910,
  EGMI_ACK_HOLD_MAP_GRID = 1911,
  EGMI_REQ_LEAVE_MSG_MAP_GRID = 1912,
  EGMI_ACK_LEAVE_MSG_MAP_GRID = 1913,
  EGMI_REQ_GET_MAP_GRID_AWARD = 1914,
  EGMI_ACK_GET_MAP_GRID_AWARD = 1915,
  EGMI_REQ_MAP_GRID_HUNTING = 1916,
  EGMI_ACK_MAP_GRID_HUNTING = 1917,
  EGMI_REQ_MAP_GRID_KING_WAR = 1918,
  EGMI_ACK_MAP_GRID_KING_WAR = 1919,
  EGMI_REQ_CMD_PROPERTY_INT = 10000,
  EGMI_REQ_CMD_PROPERTY_STR = 10001,
  EGMI_REQ_CMD_PROPERTY_OBJECT = 10002,
  EGMI_REQ_CMD_PROPERTY_FLOAT = 10003,
  EGMI_REQ_CMD_RECORD_INT = 10004,
  EGMI_REQ_CMD_RECORD_STR = 10005,
  EGMI_REQ_CMD_RECORD_OBJECT = 10006,
  EGMI_REQ_CMD_RECORD_FLOAT = 10007,
  EGMI_REQ_CMD_NORMAL = 10008,
  EGMI_REQ_QUERY_SERVER_STATUS = 10200,
  EGMI_REQ_BUY_FORM_SHOP = 20000,
  EGMI_ACK_BUY_FORM_SHOP = 20001,
  EGMI_REQ_MOVE_BUILD_OBJECT = 20002,
  EGMI_ACK_MOVE_BUILD_OBJECT = 20003,
  EGMI_REQ_UP_BUILD_LVL = 20101,
  EGMI_REQ_CREATE_ITEM = 20102,
  EGMI_REQ_BUILD_OPERATE = 20103,
  EGMI_REQ_SEARCH_TO_SHARE = 30000,
  EGMI_ACK_SEARCH_TO_SHARE = 30001,
  EGMI_REQ_SHARE_TO_ATART = 30002,
  EGMI_ACK_SHARE_TO_ATART = 30003
};
LIBPROTOC_EXPORT bool EGameMsgID_IsValid(int value);
const EGameMsgID EGameMsgID_MIN = EGMI_UNKNOW;
const EGameMsgID EGameMsgID_MAX = EGMI_ACK_SHARE_TO_ATART;
const int EGameMsgID_ARRAYSIZE = EGameMsgID_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGameMsgID_descriptor();
inline const ::std::string& EGameMsgID_Name(EGameMsgID value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameMsgID_descriptor(), value);
}
inline bool EGameMsgID_Parse(
    const ::std::string& name, EGameMsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameMsgID>(
    EGameMsgID_descriptor(), name, value);
}
enum ESkillType {
  EST_BRIEF_SINGLE = 0,
  EST_BRIEF_GROUP = 1,
  EST_BULLET_SINGLE = 2,
  EST_BULLET_REBOUND = 3,
  EST_BULLET_BOMB = 4,
  EST_TARGET_SINGLE = 5,
  EST_TARGET_GROUP = 6,
  EST_POSITION_GROUP = 7
};
LIBPROTOC_EXPORT bool ESkillType_IsValid(int value);
const ESkillType ESkillType_MIN = EST_BRIEF_SINGLE;
const ESkillType ESkillType_MAX = EST_POSITION_GROUP;
const int ESkillType_ARRAYSIZE = ESkillType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* ESkillType_descriptor();
inline const ::std::string& ESkillType_Name(ESkillType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ESkillType_descriptor(), value);
}
inline bool ESkillType_Parse(
    const ::std::string& name, ESkillType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ESkillType>(
    ESkillType_descriptor(), name, value);
}
enum EItemType {
  EIT_EQUIP = 0,
  EIT_GEM = 1,
  EIT_ITEM = 2,
  EIT_CARD = 3,
  EIT_TOKEN = 4
};
LIBPROTOC_EXPORT bool EItemType_IsValid(int value);
const EItemType EItemType_MIN = EIT_EQUIP;
const EItemType EItemType_MAX = EIT_TOKEN;
const int EItemType_ARRAYSIZE = EItemType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EItemType_descriptor();
inline const ::std::string& EItemType_Name(EItemType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EItemType_descriptor(), value);
}
inline bool EItemType_Parse(
    const ::std::string& name, EItemType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EItemType>(
    EItemType_descriptor(), name, value);
}
enum EGameEquipSubType {
  EQUIPTYPE_WEAPON = 0,
  EQUIPTYPE_HELMET = 1,
  EQUIPTYPE_ARMOR = 2,
  EQUIPTYPE_WRIST = 3,
  EQUIPTYPE_PANT = 4,
  EQUIPTYPE_BOOT = 5
};
LIBPROTOC_EXPORT bool EGameEquipSubType_IsValid(int value);
const EGameEquipSubType EGameEquipSubType_MIN = EQUIPTYPE_WEAPON;
const EGameEquipSubType EGameEquipSubType_MAX = EQUIPTYPE_BOOT;
const int EGameEquipSubType_ARRAYSIZE = EGameEquipSubType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGameEquipSubType_descriptor();
inline const ::std::string& EGameEquipSubType_Name(EGameEquipSubType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameEquipSubType_descriptor(), value);
}
inline bool EGameEquipSubType_Parse(
    const ::std::string& name, EGameEquipSubType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameEquipSubType>(
    EGameEquipSubType_descriptor(), name, value);
}
enum EGameGemSubType {
  EGGSTYPE_GEM_ATK = 0,
  EGGSTYPE_GEM_DEF = 1,
  EGGSTYPE_GEM_FIRE = 3,
  EGGSTYPE_GEM_LIGHT = 4,
  EGGSTYPE_GEM_WIND = 5,
  EGGSTYPE_GEM_ICE = 6,
  EGGSTYPE_GEM_POISON = 7
};
LIBPROTOC_EXPORT bool EGameGemSubType_IsValid(int value);
const EGameGemSubType EGameGemSubType_MIN = EGGSTYPE_GEM_ATK;
const EGameGemSubType EGameGemSubType_MAX = EGGSTYPE_GEM_POISON;
const int EGameGemSubType_ARRAYSIZE = EGameGemSubType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGameGemSubType_descriptor();
inline const ::std::string& EGameGemSubType_Name(EGameGemSubType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameGemSubType_descriptor(), value);
}
inline bool EGameGemSubType_Parse(
    const ::std::string& name, EGameGemSubType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameGemSubType>(
    EGameGemSubType_descriptor(), name, value);
}
enum EGameItemSubType {
  EGIT_ITEM_WATER = 0,
  EGIT_ITEM_DIAMOND = 1,
  EGIT_ITEM_CURRENCY = 2,
  EGIT_ITEM_EXP = 3,
  EGIT_ITEM_HP = 4,
  EGIT_ITEM_MP = 5,
  EGIT_ITEM_SP = 6,
  EGIT_ITEM_PACK = 7,
  EGIT_ITEM_MEMORY_POS = 8
};
LIBPROTOC_EXPORT bool EGameItemSubType_IsValid(int value);
const EGameItemSubType EGameItemSubType_MIN = EGIT_ITEM_WATER;
const EGameItemSubType EGameItemSubType_MAX = EGIT_ITEM_MEMORY_POS;
const int EGameItemSubType_ARRAYSIZE = EGameItemSubType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGameItemSubType_descriptor();
inline const ::std::string& EGameItemSubType_Name(EGameItemSubType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameItemSubType_descriptor(), value);
}
inline bool EGameItemSubType_Parse(
    const ::std::string& name, EGameItemSubType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameItemSubType>(
    EGameItemSubType_descriptor(), name, value);
}
enum EGameCardSubType {
  EGCST_STRENGTH = 1,
  EGCST_AGILITY = 2,
  EGCST_INTELLIGENCE = 3
};
LIBPROTOC_EXPORT bool EGameCardSubType_IsValid(int value);
const EGameCardSubType EGameCardSubType_MIN = EGCST_STRENGTH;
const EGameCardSubType EGameCardSubType_MAX = EGCST_INTELLIGENCE;
const int EGameCardSubType_ARRAYSIZE = EGameCardSubType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGameCardSubType_descriptor();
inline const ::std::string& EGameCardSubType_Name(EGameCardSubType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameCardSubType_descriptor(), value);
}
inline bool EGameCardSubType_Parse(
    const ::std::string& name, EGameCardSubType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameCardSubType>(
    EGameCardSubType_descriptor(), name, value);
}
enum EGameTokenSubType {
  EGTST_TOKEN_REBORN = 0,
  EGTST_TOKEN_POSITION = 1,
  EGTST_TOKEN_BOUNTY = 2,
  EGTST_TOKEN_ACTIVITY = 3,
  EGTST_TOKEN_BUILD = 4
};
LIBPROTOC_EXPORT bool EGameTokenSubType_IsValid(int value);
const EGameTokenSubType EGameTokenSubType_MIN = EGTST_TOKEN_REBORN;
const EGameTokenSubType EGameTokenSubType_MAX = EGTST_TOKEN_BUILD;
const int EGameTokenSubType_ARRAYSIZE = EGameTokenSubType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGameTokenSubType_descriptor();
inline const ::std::string& EGameTokenSubType_Name(EGameTokenSubType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameTokenSubType_descriptor(), value);
}
inline bool EGameTokenSubType_Parse(
    const ::std::string& name, EGameTokenSubType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameTokenSubType>(
    EGameTokenSubType_descriptor(), name, value);
}
enum EGameItemExpiredType {
  EGIET_NONE = 0,
  EGIET_USE_TIMES = 1,
  EGIET_REAL_TIME = 2,
  EGIET_END_INDEX = 3
};
LIBPROTOC_EXPORT bool EGameItemExpiredType_IsValid(int value);
const EGameItemExpiredType EGameItemExpiredType_MIN = EGIET_NONE;
const EGameItemExpiredType EGameItemExpiredType_MAX = EGIET_END_INDEX;
const int EGameItemExpiredType_ARRAYSIZE = EGameItemExpiredType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGameItemExpiredType_descriptor();
inline const ::std::string& EGameItemExpiredType_Name(EGameItemExpiredType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameItemExpiredType_descriptor(), value);
}
inline bool EGameItemExpiredType_Parse(
    const ::std::string& name, EGameItemExpiredType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameItemExpiredType>(
    EGameItemExpiredType_descriptor(), name, value);
}
enum EDrawDropItemState {
  E_DRAW_STATE_NONE = 0,
  E_DRAW_STATE_GAIN = 1,
  E_DRAW_STATE_RECV = 2
};
LIBPROTOC_EXPORT bool EDrawDropItemState_IsValid(int value);
const EDrawDropItemState EDrawDropItemState_MIN = E_DRAW_STATE_NONE;
const EDrawDropItemState EDrawDropItemState_MAX = E_DRAW_STATE_RECV;
const int EDrawDropItemState_ARRAYSIZE = EDrawDropItemState_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EDrawDropItemState_descriptor();
inline const ::std::string& EDrawDropItemState_Name(EDrawDropItemState value) {
  return ::google::protobuf::internal::NameOfEnum(
    EDrawDropItemState_descriptor(), value);
}
inline bool EDrawDropItemState_Parse(
    const ::std::string& name, EDrawDropItemState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EDrawDropItemState>(
    EDrawDropItemState_descriptor(), name, value);
}
enum EGuildPowerType {
  GUILD_POWER_TYPE_NORMAL = 0,
  GUILD_POWER_TYPE_VICE_PRESIDENT = 1,
  GUILD_POWER_TYPE_PRESIDENT = 2
};
LIBPROTOC_EXPORT bool EGuildPowerType_IsValid(int value);
const EGuildPowerType EGuildPowerType_MIN = GUILD_POWER_TYPE_NORMAL;
const EGuildPowerType EGuildPowerType_MAX = GUILD_POWER_TYPE_PRESIDENT;
const int EGuildPowerType_ARRAYSIZE = EGuildPowerType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGuildPowerType_descriptor();
inline const ::std::string& EGuildPowerType_Name(EGuildPowerType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGuildPowerType_descriptor(), value);
}
inline bool EGuildPowerType_Parse(
    const ::std::string& name, EGuildPowerType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGuildPowerType>(
    EGuildPowerType_descriptor(), name, value);
}
enum ETaskState {
  TASK_IN_PROCESS = 0,
  TASK_DONE = 1,
  TASK_DRAW_AWARD = 2,
  TASK_FINISH = 3
};
LIBPROTOC_EXPORT bool ETaskState_IsValid(int value);
const ETaskState ETaskState_MIN = TASK_IN_PROCESS;
const ETaskState ETaskState_MAX = TASK_FINISH;
const int ETaskState_ARRAYSIZE = ETaskState_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* ETaskState_descriptor();
inline const ::std::string& ETaskState_Name(ETaskState value) {
  return ::google::protobuf::internal::NameOfEnum(
    ETaskState_descriptor(), value);
}
inline bool ETaskState_Parse(
    const ::std::string& name, ETaskState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ETaskState>(
    ETaskState_descriptor(), name, value);
}
enum ETaskType {
  TASK_LEVEL_UPDATE_SOME_LEVEL = 0,
  TASK_PASS_ECTYPE = 1,
  TASK_PASS_ECTYPE_COUNT = 2,
  TASK_PASS_SOME_TYPE_ECTYPE_COUNT = 3,
  TASK_UPDATE_SKILL_COUNT = 4,
  TASK_CONSUME_MONEY = 5,
  TASK_CONSUME_DIAMOND = 6,
  TASK_ARENA_COUNT = 7,
  TASK_KILL_MONSTER_COUNT = 8,
  TASK_KILL_SOME_MONSTER_COUNT = 9
};
LIBPROTOC_EXPORT bool ETaskType_IsValid(int value);
const ETaskType ETaskType_MIN = TASK_LEVEL_UPDATE_SOME_LEVEL;
const ETaskType ETaskType_MAX = TASK_KILL_SOME_MONSTER_COUNT;
const int ETaskType_ARRAYSIZE = ETaskType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* ETaskType_descriptor();
inline const ::std::string& ETaskType_Name(ETaskType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ETaskType_descriptor(), value);
}
inline bool ETaskType_Parse(
    const ::std::string& name, ETaskType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ETaskType>(
    ETaskType_descriptor(), name, value);
}
enum EPVPType {
  PVP_HOME = 0,
  PVP_INDIVIDUAL = 1,
  PVP_DOTA = 2,
  PVP_SURVIVAL = 3,
  PVP_GUILD_WAR = 4,
  PVP_GUILD_DUNGEON = 5
};
LIBPROTOC_EXPORT bool EPVPType_IsValid(int value);
const EPVPType EPVPType_MIN = PVP_HOME;
const EPVPType EPVPType_MAX = PVP_GUILD_DUNGEON;
const int EPVPType_ARRAYSIZE = EPVPType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EPVPType_descriptor();
inline const ::std::string& EPVPType_Name(EPVPType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EPVPType_descriptor(), value);
}
inline bool EPVPType_Parse(
    const ::std::string& name, EPVPType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EPVPType>(
    EPVPType_descriptor(), name, value);
}
enum EShopType {
  EST_BUILDING = 1,
  EST_GOLD = 2,
  EST_ITEM = 3,
  EST_EQUIP = 5,
  EST_GEM = 6,
  EST_CARD = 7
};
LIBPROTOC_EXPORT bool EShopType_IsValid(int value);
const EShopType EShopType_MIN = EST_BUILDING;
const EShopType EShopType_MAX = EST_CARD;
const int EShopType_ARRAYSIZE = EShopType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EShopType_descriptor();
inline const ::std::string& EShopType_Name(EShopType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EShopType_descriptor(), value);
}
inline bool EShopType_Parse(
    const ::std::string& name, EShopType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EShopType>(
    EShopType_descriptor(), name, value);
}
enum ERankType {
  ERT_PLAYER_LEVEL = 1,
  ERT_FIGHT_VALUE = 2,
  ERT_PLAYER_MONEY = 3,
  ERT_GUILD_LEVEL = 4,
  ERT_GUILD_KINGSOURCE = 5
};
LIBPROTOC_EXPORT bool ERankType_IsValid(int value);
const ERankType ERankType_MIN = ERT_PLAYER_LEVEL;
const ERankType ERankType_MAX = ERT_GUILD_KINGSOURCE;
const int ERankType_ARRAYSIZE = ERankType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* ERankType_descriptor();
inline const ::std::string& ERankType_Name(ERankType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ERankType_descriptor(), value);
}
inline bool ERankType_Parse(
    const ::std::string& name, ERankType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ERankType>(
    ERankType_descriptor(), name, value);
}
enum ENPCType {
  ENPCTYPE_NORMAL = 0,
  ENPCTYPE_HERO = 1,
  ENPCTYPE_TURRET = 2
};
LIBPROTOC_EXPORT bool ENPCType_IsValid(int value);
const ENPCType ENPCType_MIN = ENPCTYPE_NORMAL;
const ENPCType ENPCType_MAX = ENPCTYPE_TURRET;
const int ENPCType_ARRAYSIZE = ENPCType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* ENPCType_descriptor();
inline const ::std::string& ENPCType_Name(ENPCType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ENPCType_descriptor(), value);
}
inline bool ENPCType_Parse(
    const ::std::string& name, ENPCType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ENPCType>(
    ENPCType_descriptor(), name, value);
}
enum ETARGETType {
  ETARGETTYPE_ENEMY = 0,
  ETARGETTYPE_SELF = 1,
  ETARGETTYPE_FRIEND = 2
};
LIBPROTOC_EXPORT bool ETARGETType_IsValid(int value);
const ETARGETType ETARGETType_MIN = ETARGETTYPE_ENEMY;
const ETARGETType ETARGETType_MAX = ETARGETTYPE_FRIEND;
const int ETARGETType_ARRAYSIZE = ETARGETType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* ETARGETType_descriptor();
inline const ::std::string& ETARGETType_Name(ETARGETType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ETARGETType_descriptor(), value);
}
inline bool ETARGETType_Parse(
    const ::std::string& name, ETARGETType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ETARGETType>(
    ETARGETType_descriptor(), name, value);
}
enum EPropertyType {
  EPT_STRENGTH = 1,
  EPT_AGILITY = 2,
  EPT_INTELLIGENCE = 3
};
LIBPROTOC_EXPORT bool EPropertyType_IsValid(int value);
const EPropertyType EPropertyType_MIN = EPT_STRENGTH;
const EPropertyType EPropertyType_MAX = EPT_INTELLIGENCE;
const int EPropertyType_ARRAYSIZE = EPropertyType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EPropertyType_descriptor();
inline const ::std::string& EPropertyType_Name(EPropertyType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EPropertyType_descriptor(), value);
}
inline bool EPropertyType_Parse(
    const ::std::string& name, EPropertyType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EPropertyType>(
    EPropertyType_descriptor(), name, value);
}
enum EGameElementType {
  EELEMENTTYPE_FIRE = 0,
  EELEMENTTYPE_LIGHT = 1,
  EELEMENTTYPE_WIND = 2,
  EELEMENTTYPE_ICE = 3,
  EELEMENTTYPE_POISON = 4,
  EELEMENTTYPE_DARK = 5
};
LIBPROTOC_EXPORT bool EGameElementType_IsValid(int value);
const EGameElementType EGameElementType_MIN = EELEMENTTYPE_FIRE;
const EGameElementType EGameElementType_MAX = EELEMENTTYPE_DARK;
const int EGameElementType_ARRAYSIZE = EGameElementType_MAX + 1;

LIBPROTOC_EXPORT const ::google::protobuf::EnumDescriptor* EGameElementType_descriptor();
inline const ::std::string& EGameElementType_Name(EGameElementType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EGameElementType_descriptor(), value);
}
inline bool EGameElementType_Parse(
    const ::std::string& name, EGameElementType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EGameElementType>(
    EGameElementType_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace NFMsg

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameEventCode>() {
  return ::NFMsg::EGameEventCode_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::ESynMsgID>() {
  return ::NFMsg::ESynMsgID_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameMsgID>() {
  return ::NFMsg::EGameMsgID_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::ESkillType>() {
  return ::NFMsg::ESkillType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EItemType>() {
  return ::NFMsg::EItemType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameEquipSubType>() {
  return ::NFMsg::EGameEquipSubType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameGemSubType>() {
  return ::NFMsg::EGameGemSubType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameItemSubType>() {
  return ::NFMsg::EGameItemSubType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameCardSubType>() {
  return ::NFMsg::EGameCardSubType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameTokenSubType>() {
  return ::NFMsg::EGameTokenSubType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameItemExpiredType>() {
  return ::NFMsg::EGameItemExpiredType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EDrawDropItemState>() {
  return ::NFMsg::EDrawDropItemState_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGuildPowerType>() {
  return ::NFMsg::EGuildPowerType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::ETaskState>() {
  return ::NFMsg::ETaskState_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::ETaskType>() {
  return ::NFMsg::ETaskType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EPVPType>() {
  return ::NFMsg::EPVPType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EShopType>() {
  return ::NFMsg::EShopType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::ERankType>() {
  return ::NFMsg::ERankType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::ENPCType>() {
  return ::NFMsg::ENPCType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::ETARGETType>() {
  return ::NFMsg::ETARGETType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EPropertyType>() {
  return ::NFMsg::EPropertyType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NFMsg::EGameElementType>() {
  return ::NFMsg::EGameElementType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_NFDefine_2eproto__INCLUDED
