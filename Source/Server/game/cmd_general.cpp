// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
#include "deathmatch.h"
#endif

// SEARCH: ( DO_PVP )

	if (pkVictim->IsNPC())
		return;

// ADD:


#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (ch->GetMapIndex() == DEATHMATCH_MAP_INDEX)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't duel with %s because you are in deathmatch map."), pkVictim->GetName());
		return;
	}
#endif

// SEARCH: ( DO_PKMODE )

	if (mode == PK_MODE_PROTECT)
		return;
	
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (ch->GetMapIndex() == DEATHMATCH_MAP_INDEX)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't change pk mode in deathmatch map"));
		return;
	}
#endif

// SEARCH : ( DO_PARTY_REQUEST )

	if (ch->GetArena())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("대련장에서 사용하실 수 없습니다."));
		return;
	}
	
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (ch->GetMapIndex() == DEATHMATCH_MAP_INDEX)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't invite in deathmatch map"));
		return;
	}
#endif

