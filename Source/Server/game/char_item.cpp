// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
#include "deathmatch.h"
#endif

// SEARCH: ( ITEM_MARRIAGE_RING )

											if (CArenaManager::instance().IsArenaMap(pMarriage->ch1->GetMapIndex()) == true)
											{
												ChatPacket(CHAT_TYPE_INFO, LC_TEXT("��� �߿��� �̿��� �� ���� ��ǰ�Դϴ�."));
												break;
											}
							
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
											if (GetMapIndex() == DEATHMATCH_MAP_INDEX)
											{
												ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't use Wedding Ring in this map."));
												return false;
											}
#endif

// SEARCH: ( ITEM_MARRIAGE_RING)

											if (CArenaManager::instance().IsArenaMap(pMarriage->ch2->GetMapIndex()) == true)
											{
												ChatPacket(CHAT_TYPE_INFO, LC_TEXT("��� �߿��� �̿��� �� ���� ��ǰ�Դϴ�."));
												break;
											}
											
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
											if (GetMapIndex() == DEATHMATCH_MAP_INDEX)
											{
												ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't use Wedding Ring in this map."));
												return false;
											}
#endif

// SEARCH : ( ITEMPROCESS_POLYMORPH ) 

	if (IsPolymorphed())
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("�̹� �а����� �����Դϴ�."));
		return false;
	}
	
// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
	if (GetMapIndex() == DEATHMATCH_MAP_INDEX)	
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't polymorph here."));
		return false;
	}
#endif