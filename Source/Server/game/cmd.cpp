
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
ACMD(do_goto_deathmatch);
#endif

// SEARCH:

{ "goto",		do_goto,		0,			POS_DEAD,	GM_LOW_WIZARD	},

// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	{	"goto_deathmatch",				do_goto_deathmatch,				0,						POS_DEAD,			SV_PLAYER	},
#endif