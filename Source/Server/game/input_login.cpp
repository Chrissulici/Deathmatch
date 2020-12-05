// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
#include "deathmatch.h"
#endif

// SEARCH: ( ENTERGAME )

marriage::CManager::instance().Login(ch);

// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	CDeathMatchPvP::instance().OnLogin(ch);
#endif