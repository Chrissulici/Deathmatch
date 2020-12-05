// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM   
#include "deathmatch.h"
#endif

// SEARCH: ( CAN ATTACK )

if (pkChr->GetEmpire() != pkVictim->GetEmpire())
	
// REPLACE:

#ifdef ENABLE_DEATHMATCH_SYSTEM   
	if (pkChr->GetEmpire() != pkVictim->GetEmpire() && pkChr->GetMapIndex() != DEATHMATCH_MAP_INDEX)
#else
	if (pkChr->GetEmpire() != pkVictim->GetEmpire())
#endif


// SEARCH:

case PK_MODE_FREE:
				if (pkVictim->GetAlignment() >= 0)
					pkChr->SetKillerMode(true);
				else if (pkChr->GetAlignment() < 0 && pkVictim->GetAlignment() < 0)
					pkChr->SetKillerMode(true);
				return true;
				break;
				
				
// ADD:


#ifdef ENABLE_DEATHMATCH_SYSTEM
			case PK_MODE_DEATHMATCH:
				return true;
				break;
#endif


// SEARCH:

CPVP * pkPVP = Find(kPVP.m_dwCRC);

// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (pkChr->GetMapIndex() == DEATHMATCH_MAP_INDEX && pkVictim->GetMapIndex() == DEATHMATCH_MAP_INDEX)
	{
		if (pkChr->GetPKMode() == pkVictim->GetPKMode())
			return true;
	}
#endif