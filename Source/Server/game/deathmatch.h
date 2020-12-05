#define DEATHMATCH_MAP_INDEX 359

enum EDeathMatch
{
	DEATHMATCH_NOT_STARTED 		= 0,
	DEATHMATCH_OPEN_GATES 		= 1,
	DEATHMATCH_BATTLE 			= 2,
	DEATHMATCH_MAX_NUM,
};

class CDeathMatchPvP : public singleton<CDeathMatchPvP>
{
	private :
		std::map<DWORD, DWORD> m_map_char;
	public :
		void		OnKill(LPCHARACTER pkKiller, LPCHARACTER pkDead);
		void		OnLogin(LPCHARACTER ch);
		BYTE		GetEmpire() const { return m_bEmpire; }
		int			GetStatus();
		void		WriteStatus(int key);
		void		DeleteStun();
		void		WarpToHome();
	protected:
		BYTE		m_bEmpire;
};
	