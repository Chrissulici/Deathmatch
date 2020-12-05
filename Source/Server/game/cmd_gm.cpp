// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
#include "deathmatch.h"
#endif

// SEARCH: 

ACMD(do_goto)


// ADD:

#ifdef ENABLE_DEATHMATCH_SYSTEM
ACMD(do_goto_deathmatch)
{
	char arg1[256], arg2[256];
	int x = 0, y = 0, z = 0;

	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));
	
	if (ch->GetMapIndex() != DEATHMATCH_MAP_INDEX)
		return;

	if (!*arg1 && !*arg2)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Usage: goto <x meter> <y meter>");
		return;
	}
	

	if (isnhdigit(*arg1) && isnhdigit(*arg2))
	{
		str_to_number(x, arg1);
		str_to_number(y, arg2);

		PIXEL_POSITION p;

		if (SECTREE_MANAGER::instance().GetMapBasePosition(ch->GetX(), ch->GetY(), p))
		{
			x += p.x / 100;
			y += p.y / 100;
		}

		ch->ChatPacket(CHAT_TYPE_INFO, "You goto ( %d, %d )", x, y);
	}
	else
	{
		int mapIndex = 0;
		BYTE empire = 0;

		if (*arg1 == '#')
			str_to_number(mapIndex,  (arg1 + 1));

		if (*arg2 && isnhdigit(*arg2))
		{
			str_to_number(empire, arg2);
			empire = MINMAX(1, empire, 3);
		}
		else
			empire = ch->GetEmpire();

		if (CHARACTER_GoToName(ch, empire, mapIndex, arg1))
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "Cannot find map command syntax: /goto <mapname> [empire]");
			return;
		}

		return;

	}

	x *= 100;
	y *= 100;

	ch->Show(ch->GetMapIndex(), x, y, z);
	ch->Stop();
}
#endif