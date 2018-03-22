#include "CheatEngine.h"

void CheatEngine::CheatEngineMain
(PlayerCharacter*& player, Position* position, int& playground, std::ostream& out)
{
	CheatEngineMenu(out);

	char choice;
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice)
	{
	case '1':
		raceModifier(player, out);
		break;
	case '2':
		statsModifier(player, out);
		break;
	case '3':
		teleporter(playground, position, out);
		break;
	case '4':
		wardrobe(player, out);
		break;
	case '5':   // Exit
		break;
	default:
		std::cout << "Invalid input!\n";
	}

	// Flush any input remains in the input stream
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void CheatEngine::CheatEngineMenu(std::ostream& out)
{
	out << " WELCOME TO CHEAT ENGINE 1.0 \n"
		<< " --------------------------------------------\n"
		<< std::setw(4) << ' ' << "1. Race modifier\n"
		<< std::setw(4) << ' ' << "2. Stats modifier\n"
		<< std::setw(4) << ' ' << "3. Teleporter\n"
		<< std::setw(4) << ' ' << "4. Wardrobe\n"
		<< std::setw(4) << ' ' << "5. Exit\n\n";

	out << " Your choice: ";
}

void CheatEngine::raceModifier(PlayerCharacter*& charToMod, std::ostream& out)
{
	// Store the current inventory
	vector<Item> playerInventory = charToMod->getInventory();

	out << "\n Currently you are a " << charToMod->name() << ".\n\n";
	out << " Choose which race you'd like to morph into:\n"
		<< " (This will change the base stats and character description!)\n"
		<< " --------------------------------------------\n"
		<< std::setw(4) << ' ' << "1. Golem\n"
		<< std::setw(4) << ' ' << "2. Sphinx\n"
		<< std::setw(4) << ' ' << "3. Human\n"
		<< std::setw(4) << ' ' << "4. God\n\n";

	out << " Your choice: ";
	char choice;
	std::cin >> choice;

	// Delete the current player
	delete charToMod;

	// Create a new player character dynamically based on choice
	switch (choice)
	{
		// Golem
	case '1':
		charToMod = new PlayerCharacter(50, 30, 10, "Golem");
		out << " Character has morphed to be a " << charToMod->name() << ".\n\n";
		break;
		// Sphinx
	case '2':
		charToMod = new PlayerCharacter(25, 15, 30, "Sphinx");
		out << " Character has morphed to be a " << charToMod->name() << ".\n\n";
		break;
		// Human
	case '3':
		charToMod = new PlayerCharacter(35, 20, 20, "Human");
		out << " Character has morphed to be a " << charToMod->name() << ".\n\n";
		break;
		// God
	case '4':
		charToMod = new PlayerCharacter(9999, 9999, 9999, "God");
		out << " Character has morphed to be a " << charToMod->name() << ".\n\n";
		break;
	default:
		out << " Invalid input!\n\n";
	}

	// Copy the original inventory back
	charToMod->setInventory(playerInventory);
}

void CheatEngine::statsModifier(PlayerCharacter* charToMod, std::ostream& out)
{
	out << " Choose which stat you'd like to modify:\n"
		<< " --------------------------------------------\n"
		<< std::setw(4) << ' ' << "1. Base damage\n"
		<< std::setw(4) << ' ' << "2. Speed\n\n";

	out << " Your choice: ";
	char choice;
	std::cin >> choice;

	out << " Amount: ";
	int tempVal = 0;
	std::cin >> tempVal;

	switch (choice)
	{
		// Base damage
	case '1':
		charToMod->setDamage(tempVal);
		out << " Character strength has been modified to " << charToMod->getDamage() << ".\n\n";
		break;

		// Speed
	case '2':
		charToMod->setSpeed(tempVal);
		out << " Character speed has been modified to " << charToMod->getSpeed() << ".\n\n";
		break;
	default:
		out << " Invalid input!\n";
	}
}

void CheatEngine::teleporter(int& areaToPort, Position* positionToPort, std::ostream& out)
{
	std::string areaName[4] = { "space", "desert", "water", "fortress" };

	// Area first
	out << " Teleporter online! Indicate which area you'd like to teleport to:\n"
		<< " --------------------------------------------\n"
		<< std::setw(4) << ' ' << "1. Spaceship\n"
		<< std::setw(4) << ' ' << "2. Desert\n"
		<< std::setw(4) << ' ' << "3. Water\n"
		<< std::setw(4) << ' ' << "4. Fortress\n\n";

	out << " Your choice: ";
	char choice;
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice)
	{
	case '1':
		areaToPort = spaceArea;
		break;
	case '2':
		areaToPort = desertArea;
		break;
	case '3':
		areaToPort = waterArea;
		break;
	case '4':
		areaToPort = fortArea;
		break;
	default:
		out << " Invalid input!\n";
	}

	// Specific position (which room) in an area
	out << " Indicate which room you'd like to teleport to:\n"
		<< " (Input using the following format: [row] [column])\n\n";

	out << " Coordinate: ";
	int xCoord = 0, yCoord = 0;
	std::cin >> xCoord >> yCoord;
	std::cout << std::endl;

	if (xCoord - 1 < 0 || yCoord - 1 < 0 ||
		xCoord - 1 > 4 || yCoord - 1 > 4)
		std::cout << " Invalid inputs!\n\n";
	else
	{
		positionToPort->setCol(yCoord - 1);
		positionToPort->setRow(xCoord - 1);
	}
	std::cout << " Choice is: " << choice << std::endl;
	std::cout << " You are being teleported to " << areaName[(choice - '0') - 1] << " area, at ("
      << positionToPort->getRow() + 1 << ", " << positionToPort->getCol() + 1
		<< "). Hold tight...\n"
		<< " Teleportation completed!\n\n";
}

void CheatEngine::wardrobe(PlayerCharacter* charToMod, std::ostream& out)
{
	vector<Item> playerInventory = charToMod->getInventory();

	Item weaponList[] =
	{ WRENCH, LASER_GUN, SCIMITAR, HAND_CANNON, TRIDENT, SONAR_BLASTER,
		REAPER_OF_SOULS, HELIOS_FLAMETHROWER, GOD_HAND };

	Item armorList[] =
	{ ELITE_PATROL_ARMOR, DESERT_RANGER_ARMOR, AQUA_SHROUD, POWER_ARMOR };

	Item spoilsList[] =
	{ MEMENTO_OF_THE_CAPTAIN, EYES_OF_ANUBIS, CROWN_OF_POSEIDON };

	out << " Choose which inventory slot you'd like to modify:\n"
		<< " --------------------------------------------\n"
		<< std::setw(4) << ' ' << "1. Weapon\n"
		<< std::setw(4) << ' ' << "2. Armor\n"
		<< std::setw(4) << ' ' << "3. Spoils of War\n\n";

	out << " Your choice: ";
	char choice;
	std::cin >> choice;

	switch (choice)
	{
		// Weapon
	case '1':
		int weaponChoice;

		out << " Which weapon you'd like to get:\n"
			<< " --------------------------------------------\n"
			<< std::setw(4) << ' ' << "1. Wrench\n"
			<< std::setw(4) << ' ' << "2. Laser Gun\n"
			<< std::setw(4) << ' ' << "3. Scimitar\n"
			<< std::setw(4) << ' ' << "4. Hand Cannon\n"
			<< std::setw(4) << ' ' << "5. Trident\n"
			<< std::setw(4) << ' ' << "6. Sonar Blaster\n"
			<< std::setw(4) << ' ' << "7. Reaper of Souls\n"
			<< std::setw(4) << ' ' << "8. Helios' flamethrower\n"
			<< std::setw(4) << ' ' << "9. God's Hand\n\n";

		out << " Your choice: ";
		std::cin >> weaponChoice;
		playerInventory[WEAPON] = weaponList[weaponChoice - 1];
		out << " You are now armed with " << (weaponList[weaponChoice - 1]).ItemName << ".\n\n";
		break;
		// Armor
	case '2':
		int armorChoice;

		out << " Which armor you'd like to get:\n"
			<< " --------------------------------------------\n"
			<< std::setw(4) << ' ' << "1. Elite Patrol Armor\n"
			<< std::setw(4) << ' ' << "2. Desert Ranger Armor\n"
			<< std::setw(4) << ' ' << "3. Aqua Shroud\n"
			<< std::setw(4) << ' ' << "4. Power Armor\n\n";

		out << " Your choice: ";
		std::cin >> armorChoice;
		playerInventory[ARMOR] = armorList[armorChoice - 1];
		out << " You are now wearing the " << (armorList[armorChoice - 1]).ItemName << ".\n\n";
		break;
		// Spoils of war
	case '3':
		int spoilsChoice;

		out << " Which spoils you'd like to get:\n"
			<< " --------------------------------------------\n"
			<< std::setw(4) << ' ' << "1. Memento of the Captain\n"
			<< std::setw(4) << ' ' << "2. Eye of Anubis\n"
			<< std::setw(4) << ' ' << "3. Crown of Poseidon\n\n";

		out << " Your choice: ";
		std::cin >> spoilsChoice;
		playerInventory[SPOILS] = spoilsList[spoilsChoice - 1];
		out << " You are now wearing the " << (spoilsList[spoilsChoice - 1]).ItemName << ".\n\n";
		break;
	default:
		out << " Invalid input!\n";
	}

	charToMod->setInventory(playerInventory);
}
