#include "RoomDescription.h"

RoomDescription::RoomDescription(const int& intRoomType, const int& intAreaType)
{
	int intArea = 0;
	intArea = rand() % 2;
	switch (intRoomType)
	{
	case 0://enemy room
		switch (intAreaType)
		{
		case 0: //space
			if (intArea)
				strRoomDesc = "The metal hull creaks as the fires burn the damaged ship.";
			else
				strRoomDesc = "You hear footsteps and a faint snarl in the distance.";
			break;
		case 1: //desert
			if (intArea)
				strRoomDesc = "The dry and hot winds howl across the dunes.";
			else
				strRoomDesc = "An unrelenting desert sun looms over as you cross the desert.";
			break;
		case 2://water
			if (intArea)
				strRoomDesc = "The light from the hole you fell through shines onto the stygian waters.";
			else
				strRoomDesc = "A cold current surrounds you and you hear a deep ominous groan. Something big is in the water.";
			break;
		case 3://Fort
			if (intArea)
				strRoomDesc = "Your surroundings are dark and dank from the thousands of years of mold covering the fortress walls.";
			else
				strRoomDesc = "The sound of footsteps can be heard down the corridors. Jentley's goons are on the hunt for you.";
			break;
			//default:
			//break;
		}
		break;
	case 1://trap room, note: case 4 (boss level) does not exist
		switch (intAreaType)
		{
		case 0: //space
			if (intArea)
				strRoomDesc = "You pass through a room, but you notice your heel pass through a laser as you enter.";
			else
				strRoomDesc = "You have your weapon at the ready as you enter, but you hear a click. Suddenly there is a beeping noise.";
			break;
		case 1: //desert
			if (intArea)
				strRoomDesc = "You find a glass of water encircled by a rope... you feel tempted to grab it.";
			else
				strRoomDesc = "You step over something that feels different than sand, but before taking another step you...";
			break;
		case 2://water
			if (intArea)
				strRoomDesc = "It's pretty dark in the water but you see something shiny floating around. You are tempted to grab it.";
			else
				strRoomDesc = "Oh, a golden piece of jewelry floating in the water. I should grab it before other things attracted to shiny things take it.";
			break;
		case 3://Fort
			if (intArea)
				strRoomDesc = "You walk across the stone tiles and notice one of them press down when you stepped on it.";
			else
				strRoomDesc = "You cut a wire on accident walking into the room and hear a bunch of gears turning. What could it be...";
			break;
		default:
			strRoomDesc = "The developers gave this room a trap desc even though it was a boss room.";
		}
		break;
	case 2://boss room
		switch (intAreaType)
		{
		case 0:
			strRoomDesc = "You enter the room before you and hear something clawing at flesh.\nYou go to investigate the sound but all you notice is a blood trail\non the floor. Suddenly you hear something...";
			break;
		case 1:
			strRoomDesc = "You finally arrive at an oasis. At the center you see a few palm trees surrounded by grass.\nBelow the palm trees is a pond, you rush towards the pond when suddenly...";
			break;
		case 2:
			strRoomDesc = "You see the great metal doors to a brightly illuminated fortress before you but\nsuddenly water swirls violently and throws you around. You see a dark shadow\nswimming below you, suddenly it surfaces and...";
			break;
		case 3:
			strRoomDesc = "You see before you a twisting staircase leading to the top of the fortress.\nFlashes of lightning and the sound of thunder can be heard from above.\nYou take the risk and proceed up.";
			break;
		case 4:
			if (intArea)
				strRoomDesc = "The skies turn black and it begins to storm.\nThe heavens begin to fall as you confront the most evil of all.";
			else
				strRoomDesc = "The entire planet's lifeforms begin their march upon you.\nSoon the horizons are filled with his mind controlled slaves.";
			strRoomDesc += "Thousands of possessed beings try to stop your from killing their master.";
		}
		break;
	case 3://empty room
		switch (intAreaType)
		{
		case 0: //space
			if (intArea)
				strRoomDesc = "Bent metal, sparks from broken circuits, and smoke from the fire surrounds you. You keep on moving.";
			else
				strRoomDesc = "The hull is damaged severely, you need to get out of this ship before the reactor implodes.";
			break;
		case 1: //desert
			if (intArea)
				strRoomDesc = "You see nothing but sand dunes for miles around.";
			else
				strRoomDesc = "The wind blows sand in different directions. You begin to wonder if you're traveling in circles...";
			break;
		case 2://water
			if (intArea)
				strRoomDesc = "You continue to swim further into the cavern. Your oxygen levels seem nominal.";
			else
				strRoomDesc = "It's pretty deep down here. You wonder if something big can be lurking in these waters.";
			break;
		case 3://Fort
			if (intArea)
				strRoomDesc = "Cold walls of stone, the smell of rotted flesh, rusted chains -- how could anyone live here?";
			else
				strRoomDesc = "You pass hallways displaying the once proud history of the Jentley family descend into dissent and chaos.\nWhat could have turned this once benevolent dynasty?";
			break;
		default:
			strRoomDesc = "The developers gave this room a empty desc even though it was a boss room.";
			break;
		}
		break;
	default:
		std::cout << "In appropriate type of room initialized, use values 0 - 3";
	}
	//end giant switch statement
}

RoomDescription::~RoomDescription()
{
}

std::string RoomDescription::getRoomDesc() const
{
    return strRoomDesc;
}

void RoomDescription::setRoomDesc(const std::string& desc)
{
     strRoomDesc = desc;
}
