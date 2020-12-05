// SEARCH::

PyObject * playerSetGameWindow(PyObject* poSelf, PyObject* poArgs)
{
	PyObject * pyHandle;
	if (!PyTuple_GetObject(poArgs, 0, &pyHandle))
		return Py_BadArgument();

	CPythonPlayer & rkPlayer = CPythonPlayer::Instance();
	rkPlayer.SetGameWindow(pyHandle);
	return Py_BuildNone();
}


// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
PyObject * playerIsDeathMatchMap(PyObject* poSelf, PyObject* poArgs)
{
	CInstanceBase * pInstance = CPythonPlayer::Instance().NEW_GetMainActorPtr();
	return Py_BuildValue("i", pInstance->IsDeathMatchMap());
}
#endif


// SEARCH:

{ "SetAutoPotionInfo",			playerSetAutoPotionInfo,			METH_VARARGS },


// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
		{ "IsDeathMatchMap", 				playerIsDeathMatchMap, 				METH_VARARGS},	
#endif