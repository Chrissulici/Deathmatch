// ADD :

#ifdef ENABLE_DEATHMATCH_SYSTEM
#include "deathmatch.h"
#endif
 
// SEARCH : 

BYTE SECTREE_MANAGER::GetEmpireFromMapIndex(long lMapIndex)
{

// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM  
	if (lMapIndex == DEATHMATCH_MAP_INDEX)
		return 0;
#endif

