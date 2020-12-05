// SEARCH:

	PyModule_AddIntConstant(poModule, "NAMECOLOR_EXTRA", CInstanceBase::NAMECOLOR_EXTRA);
	
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	PyModule_AddIntConstant(poModule, "NAMECOLOR_DEATHMATCH", CInstanceBase::NAMECOLOR_DEATHMATCH);
#endif