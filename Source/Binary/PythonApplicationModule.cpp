// SEARCH:

#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif


// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_DEATHMATCH_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_DEATHMATCH_SYSTEM",	0);
#endif