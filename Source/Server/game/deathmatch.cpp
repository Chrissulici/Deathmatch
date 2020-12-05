#include "stdafx.h"
#include "utils.h"
#include "char.h"
#include "char_manager.h"
#include "affect.h"
#include "sectree_manager.h"
#include "packet.h"
#include "deathmatch.h"
#include "locale_service.h"
#include <fstream>

void CDeathMatchPvP::OnLogin(LPCHARACTER ch)
{
	if (ch->GetMapIndex() == DEATHMATCH_MAP_INDEX && !ch->IsGM())
	{
		if (GetStatus() == DEATHMATCH_OPEN_GATES)
		{	
			ch->AddAffect(STUN_DEATHMATCH, 0, 0, AFF_STUN, 60*60*60*365, 0, 1, 0);
			ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You were blocked until the event started."));
		}
		
		if (GetStatus() == DEATHMATCH_NOT_STARTED)
			ch->GoHome();
		
		ch->SetPKMode(PK_MODE_DEATHMATCH);
	}
}

struct FDeleteStun
{
	void operator() (LPENTITY ent)
	{
		if (ent->IsType(ENTITY_CHARACTER))
		{
			LPCHARACTER ch = static_cast<LPCHARACTER>(ent);

			if (!ch->IsPC())
				return;
			
			if (ch->IsPC())
			{
				if (ch->FindAffect(STUN_DEATHMATCH))
					ch->RemoveAffect(STUN_DEATHMATCH);
			}
		}
	}
};

struct FWarpToHome
{
	void operator() (LPENTITY ent)
	{
		if (ent->IsType(ENTITY_CHARACTER))
		{
			LPCHARACTER ch = static_cast<LPCHARACTER>(ent);
			
			if (!ch->IsPC())
				return;

			if (ch->IsPC() && !ch->IsGM() )
				ch->GoHome();
		}
	}
};


void CDeathMatchPvP::WarpToHome()
{
	LPSECTREE_MAP sectree = SECTREE_MANAGER::instance().GetMap(DEATHMATCH_MAP_INDEX);

	if ( sectree != NULL )
	{
		struct FWarpToHome f;
		sectree->for_each( f );
	}
}

void CDeathMatchPvP::DeleteStun()
{
	LPSECTREE_MAP sectree = SECTREE_MANAGER::instance().GetMap(DEATHMATCH_MAP_INDEX);

	if ( sectree != NULL )
	{
		struct FDeleteStun f;
		sectree->for_each( f );
	}
}

void CDeathMatchPvP::OnKill(LPCHARACTER pkKiller, LPCHARACTER pkDead)
{
	if (!pkKiller->IsPC())
		return;
	
	if (!pkDead->IsPC())
		return;
		
	if (pkKiller->GetMapIndex() != DEATHMATCH_MAP_INDEX)
		return;
	
	if (GetStatus() != DEATHMATCH_BATTLE)
		return;
	
	pkKiller->AutoGiveItem(300120, 1);
}

int CDeathMatchPvP::GetStatus()
{
	int key = 0;
	char szFileName[256];
	snprintf(szFileName, sizeof(szFileName), "%s/%s", LocaleService_GetBasePath().c_str(), "deathmatch_status.txt");
	std::ifstream file(szFileName);

	if (!file.is_open())
	{
		sys_err("Error %s", szFileName);
		return false;
	}

	file >> key;
	file.close();
	return key;
}

void CDeathMatchPvP::WriteStatus(int key)
{
	char szFileName[256];
	snprintf(szFileName, sizeof(szFileName), "%s/%s", LocaleService_GetBasePath().c_str(), "deathmatch_status.txt");
	FILE* file = NULL;	
	file = fopen(szFileName, "w+");

	if (!file)
	{
		sys_err("Error %s", szFileName);
		return;
	}
	
	fprintf(file, "");
	fprintf(file, "%d", key);	
	fclose(file);
}

