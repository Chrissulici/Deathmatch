// SEARCH:

DWORD CInstanceBase::GetDuelMode()
{
	return m_dwDuelMode;
}

// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
bool CInstanceBase::IsDeathMatchMap()
{
	const std::string& c_rstrMapFileName = CPythonBackground::Instance().GetWarpMapName();
	return c_rstrMapFileName == "rinnegan_mapa_coliseo";
}
#endif

// SEARCH: ( IS ATACKABLE INSTANCE )

				if (PK_MODE_GUILD == GetPKMode())
				{
					if (PK_MODE_PROTECT != rkInstVictim.GetPKMode())
						if (!IAbstractPlayer::GetSingleton().IsSamePartyMember(GetVirtualID(), rkInstVictim.GetVirtualID()))
							if (GetGuildID() != rkInstVictim.GetGuildID())
								return true;
				}

// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
				if (PK_MODE_DEATHMATCH == GetPKMode())
				{
					if (PK_MODE_PROTECT != rkInstVictim.GetPKMode() && rkInstVictim.GetPKMode() == PK_MODE_DEATHMATCH)
						return true;
				}
#endif


// SEARCH : 

if (IsSameEmpire(rkInstVictim))	
	
// REPLACE:

#ifdef ENABLE_DEATHMATCH_SYSTEM
			if (IsSameEmpire(rkInstVictim) && !IsDeathMatchMap())
#else
			if (IsSameEmpire(rkInstVictim))	
#endif
