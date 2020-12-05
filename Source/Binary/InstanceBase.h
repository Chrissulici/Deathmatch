// SEARCH:

NAMECOLOR_WAYPOINT,

// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
			NAMECOLOR_DEATHMATCH,
#endif

// SEARCH:

bool					IsPartyMember();

// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
		bool					IsDeathMatchMap();
#endif

