// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM   
#include "deathmatch.h"
#endif


// SEARCH: ( DEATH PENALTY )

	if (CBattleArena::instance().IsBattleArenaMap(GetMapIndex()) == true)
	{
		return;
	}
	
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (GetMapIndex() == DEATHMATCH_MAP_INDEX)
		return;
#endif

// SEARCH: ( ItemDropPenalty )


	if (CBattleArena::instance().IsBattleArenaMap(GetMapIndex()) == true)
	{
		return;
	}

// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (GetMapIndex() == DEATHMATCH_MAP_INDEX)
		return;
#endif


// SEARCH: ( DEAD )

isDuel = CArenaManager::instance().OnDead(pkKiller, this);


// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
		CDeathMatchPvP::instance().OnKill(pkKiller, this);	
#endif


// SEARCH:

void CHARACTER::UpdateAlignment(int iAmount)
{
	
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (GetMapIndex() == DEATHMATCH_MAP_INDEX)
		return;
#endif