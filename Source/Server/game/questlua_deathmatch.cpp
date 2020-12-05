#include "stdafx.h"
#include "questlua.h"
#include "questmanager.h"
#include "desc_client.h"
#include "char.h"
#include "item_manager.h"
#include "item.h"
#include "cmd.h"
#include "packet.h"

#undef sys_err
#ifndef __WIN32__
#define sys_err(fmt, args...) quest::CQuestManager::instance().QuestError(__FUNCTION__, __LINE__, fmt, ##args)
#else
#define sys_err(fmt, ...) quest::CQuestManager::instance().QuestError(__FUNCTION__, __LINE__, fmt, __VA_ARGS__)
#endif

#ifdef ENABLE_DEATHMATCH_SYSTEM
#include "deathmatch.h"

namespace quest
{
	ALUA(deathmatch_start_battle)
	{
		if (CDeathMatchPvP::instance().GetStatus() == DEATHMATCH_OPEN_GATES)
		{
			CDeathMatchPvP::instance().WriteStatus(2);
			CDeathMatchPvP::instance().DeleteStun();
		}
		
		return 1;
	}
	
	ALUA(deathmatch_close_battle)
	{
		if (CDeathMatchPvP::instance().GetStatus() >= DEATHMATCH_NOT_STARTED && CDeathMatchPvP::instance().GetStatus() <= DEATHMATCH_MAX_NUM)
		{
			CDeathMatchPvP::instance().WriteStatus(0);
			CDeathMatchPvP::instance().WarpToHome();
		}
		
		return 1;
	}
	
	ALUA(deathmatch_is_map)
	{
		LPCHARACTER pkChar = CQuestManager::instance().GetCurrentCharacterPtr();
		
		if (pkChar && pkChar->GetMapIndex() == DEATHMATCH_MAP_INDEX)
			lua_pushboolean(L, true);
		else
			lua_pushboolean(L, false);
		
		return 1;
	}
	
	ALUA(deathmatch_regen)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		ch->PointChange(POINT_HP, ch->GetMaxHP() - ch->GetHP());
		ch->Save();
		return 1;
	}
	
	ALUA(deathmatch_is_status)
	{
		if (CDeathMatchPvP::instance().GetStatus() == DEATHMATCH_OPEN_GATES)
			lua_pushnumber(L, 1);
		else if (CDeathMatchPvP::instance().GetStatus() == DEATHMATCH_BATTLE)
			lua_pushnumber(L, 2);
		else
			lua_pushnumber(L, 0);
		
		return 1;
	}
	
	ALUA(deathmatch_open_gates)
	{
		if (CDeathMatchPvP::instance().GetStatus() == DEATHMATCH_NOT_STARTED)
			CDeathMatchPvP::instance().WriteStatus(1);
		
		return 1;
	}

	void RegisterDeathmatchFunctionTable()
	{
		luaL_reg deathmatch_functions[] = 
		{
			{ "start",				deathmatch_start_battle			},
			{ "close",				deathmatch_close_battle			},
			{ "is_map",				deathmatch_is_map				},
			{ "regen", 				deathmatch_regen 				},
			{ "is_status", 			deathmatch_is_status			},
			{ "open_gates", 		deathmatch_open_gates			},
			{ NULL,					NULL							}
		};

		CQuestManager::instance().AddLuaFunctionTable("deathmatch", deathmatch_functions);
	}
}
#endif

