// SEARCH: ( GET NAME COLOR INDEX )

		if (m_isKiller)
		{
			return NAMECOLOR_PK;
		}
		
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
		if (GetPKMode() == PK_MODE_DEATHMATCH && IsDeathMatchMap())
			return NAMECOLOR_DEATHMATCH;
#endif