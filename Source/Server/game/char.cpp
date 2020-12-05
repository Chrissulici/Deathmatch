// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
#include "deathmatch.h"
#endif

// SEARCH: ( DISCONNECT )

	if (GetShop())
	{
		GetShop()->RemoveGuest(this);
		SetShop(NULL);
	}
	
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (IsPC() && GetMapIndex() == DEATHMATCH_MAP_INDEX)
	{
		WarpSet(EMPIRE_START_X(GetEmpire()), EMPIRE_START_Y(GetEmpire()));
		
		if (FindAffect(STUN_DEATHMATCH))
			RemoveAffect(STUN_DEATHMATCH);
	}
#endif


// SEARCH : ( SETLEVEL )

	m_points.level = level;
	
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (IsPC() && GetMapIndex() == DEATHMATCH_MAP_INDEX)
		return;
#endif

// SEARCH:

void CHARACTER::PartyInvite(LPCHARACTER pchInvitee)
{
	
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (GetMapIndex() == DEATHMATCH_MAP_INDEX)
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<Group> You can't invite someone."));
		return;
	}
#endif




