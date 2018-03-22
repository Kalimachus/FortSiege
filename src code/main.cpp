//=============================================================================
// Authors: Quan Bui
//			Chris Tran                                                                                     
//			Kyle Gomez                                            
//			Carolyn Yen                                           
//			Jaye Wang 
// Version: 03/22/2018
// OS: Windows, Mac
// Compilers: Microsoft Visual Studio, CodeBlocks, g++, Xcode
// File: main.cpp
//								Final Project
//
// A game developed as the Winter 2018 CIS 29 final project.
//=============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <deque>
#include "Room.h"
#include "Area.h"
#include "CheatEngine.h"

void release(PlayerCharacter*&, deque<Area*>& obj);
PlayerCharacter* getPlayer();
void displayStartMenu();

int main()
{
   srand(static_cast<unsigned int>(time(NULL)));
   displayStartMenu();
   string name;
   cout << "Enter a name for your character: " << endl;
   getline(cin, name);
   
   PlayerCharacter* playerPtr = getPlayer();
   Narration        narration(name);
   Room             finalBossRoom{2, 4, 0, 0}; // C++11 extended scope of curly brace initialization, Uniform initialization
   int              areaLevel = spaceArea; // used to advance area level when boss dead
   Position         position(0, 0); // keep track of the position of the player
   ActionMenu       action = help; // intial value is help, so that it print out all command list when the game get started.
   int              actionDetail; // used to describe more info about an action, for example move south, move east
   int              levelMax = spaceArea; // denote the max level the player has entered
   Position         intialPos(0,0);
   Position         finalPos(GameConst::ROW-1, GameConst::COL-1);
   deque<Area*>     areaPtrs{new Area(spaceArea),new Area(desertArea),new Area(waterArea),new Area(fortArea)};// C++11 initializer list constructor
   Area*            areaPtr = areaPtrs[spaceArea]; // areaPtr starting with the firat level, space area
   
   cout << "\n" << playerPtr->name() << ", you have hp " << playerPtr->getHp()
   << " and damage " << playerPtr->getDamage() << " and speed "
   << playerPtr->getSpeed() << "\n";
   
   narration.intro();
   narration.EnterSpaceship();
   KeyBoard::displayHelpMenu();         // Display the first menu first to tell the player what are the available commands
   areaPtr->displayRoom(position);      // Display this once for the beginning scene/1st room
   
   auto playerAlive = [](PlayerCharacter* pc)
   {
      return (pc->getHp() > 0) ? true : false;
   };
   
   while (playerAlive(playerPtr) && (action != GameConst::quit))
   {
      areaPtr->updateCurrentRoom(position, playerPtr);
      action = static_cast<ActionMenu>(KeyBoard::getActionMenu(actionDetail));
      try
      {
         switch (action)
         {
            case GameConst::help:
               KeyBoard::displayHelpMenu();
               break;
            case GameConst::move:
               areaPtr->tryMovePosition(playerPtr, position, actionDetail);
               areaPtr->displayRoom(position);   // Display info of the room after FIRST move into the room
               areaPtr->checkHealPlayer(position, playerPtr);
               break;
            case GameConst::printMap:
               areaPtr->displayMap(position);
               break;
            case GameConst::up:
               areaLevel--;
               if (position == intialPos && spaceArea <= areaLevel && areaLevel <= fortArea)
               {
                  areaPtr = areaPtrs[areaLevel];
                  position = finalPos;
                  areaPtr->displayMap(position);
               }
               else
               {
                  areaLevel++;
                  cout << "Failed, you can go to previous area if you are at intial position 0,0"
                  << "\nand not in the first area.\n";
               }
               break;
            case GameConst::down:
               areaLevel ++;
               if (position == finalPos && spaceArea <= areaLevel && areaLevel <= levelMax)
               {
                  areaPtr = areaPtrs[areaLevel];
                  position = intialPos;
                  areaPtr->displayMap(position);
               }
               else
               {
                  areaLevel--;
                  cout << "Failed, you can go to next area if you are at final position "
                  <<  ROW << "," << COL << "\n"
                  << "and kill the boss of the current area level.\n";
               }
               break;
            case GameConst::attack:
               areaPtr->tryPerformAttack(playerPtr, position);
               
               // Check if enemy is dead (enemy ptr is null or not). If dead display the room description again
               if (((*areaPtr)[position]).getEnemy() == nullptr)
                  areaPtr->displayRoom(position);
               
               if (position == areaPtr->getBossPos() && areaPtr->isBossDead())
               {
                  // If the boss of first three areas dead, go to the next level, delete the current level
                  // If the final boss in the last level dead, announce the winner
                  areaLevel++; // advance the area level
                  levelMax = areaLevel;
                  AreaType areaType = static_cast<AreaType>(areaLevel);
                  if (areaType == victory)
                  {
                     playerPtr->receiveItem(JEWEL_OF_JENTLEY);
                     playerPtr->evolve();
                     cout << "You received the " << playerPtr->getInventory()[SPOILS].name() << endl
                     << playerPtr->getInventory()[SPOILS].getDescription() << endl;
                     cout << endl << "'Press enter to continue...'" << endl;
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     narration.Ending();
                     release(playerPtr, areaPtrs);
                     return EXIT_SUCCESS;
                  }
                  
                  if(areaLevel == 1)
                  {
                     playerPtr->receiveItem(MEMENTO_OF_THE_CAPTAIN);
                     playerPtr->evolve();
                     cout << "You received the " << playerPtr->getInventory()[SPOILS].name() << ", granting you newfound powers." << endl
                     << "Your stats have increased: " << endl
                     << "HP: " << playerPtr->getHp() << "/" << playerPtr->getMax_hp() << endl
                     << "Damage: " << playerPtr->getDamage() << endl
                     << "Speed: "
                     << playerPtr->getSpeed() << endl;
                     cout << endl << "'Press enter to continue...'" << endl;
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     narration.SpaceEscapeRoom();
                     narration.EnterDesert();
                  }
                  else if(areaLevel == 2)
                  {
                     playerPtr->receiveItem(EYES_OF_ANUBIS);
                     playerPtr->evolve();
                     cout << "You received the " << playerPtr->getInventory()[SPOILS].name() << ", granting you newfound powers." << endl
                     << "Your stats have increased: " << endl
                     << "HP: " << playerPtr->getHp() << "/" << playerPtr->getMax_hp() << endl
                     << "Damage: " << playerPtr->getDamage() << endl
                     << "Speed: "
                     << playerPtr->getSpeed() << endl;
                     cout << endl << "'Press enter to continue...'" << endl;
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     narration.DesertEscapeRoom();
                  }
                  else if(areaLevel == 3)
                  {
                     playerPtr->receiveItem(CROWN_OF_POSEIDON);
                     playerPtr->evolve();
                     cout << "You received the " << playerPtr->getInventory()[SPOILS].name() << ", granting you newfound powers." << endl
                     << "Your stats have increased: " << endl
                     << "HP: " << playerPtr->getHp() << "/" << playerPtr->getMax_hp() << endl
                     << "Damage: " << playerPtr->getDamage() << endl
                     << "Speed: "
                     << playerPtr->getSpeed() << endl;
                     cout << endl << "'Press enter to continue...'" << endl;
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     narration.EnterFortress();
                  }
                  
                  areaPtr = areaPtrs[areaLevel];
                  position = Position(); // Reintialize position
                  areaPtr->displayMap(position);
                  
               }
               break;
            case GameConst::bag:
            {
               vector<Item> playerBag(playerPtr->getInventory());
               cout << "\n You are currently equipped with:\n"
               << std::setw(4) << ' ' << " Weapon: " << playerBag[WEAPON].name() << endl
               << std::setw(4) << ' ' << " Description: " << playerBag[WEAPON].getDescription() << endl << endl
               << std::setw(4) << ' ' << " Armor: " << playerBag[ARMOR].name() << endl
               << std::setw(4) << ' ' << " Description: " << playerBag[ARMOR].getDescription() << endl << endl
               << std::setw(4) << ' ' << " Spoils of war: " << playerBag[SPOILS].name() << ". (+" << playerBag[SPOILS].getHp() <<" HP,"
               << " +" << playerBag[SPOILS].getDmg() <<" dmg, +" << playerBag[SPOILS].getSpeed() << " speed)" << endl
               << std::setw(4) << ' ' << " Description: " << playerBag[SPOILS].getDescription() << endl;
               break;
            }
            case GameConst::info:
               cout << "\n--- Name: " << narration.name() << " ---\n"
               << std::setw(4) << ' ' << "You are a " << playerPtr->name() << endl
               << std::setw(4) << ' ' << "HP: " << playerPtr->getHp() << "/" << playerPtr->getMax_hp() << endl
               << std::setw(4) << ' ' << "Damage: " << playerPtr->getDamage() << endl
               << std::setw(4) << ' ' << "Speed (affects your weapon precision and dodge chance): "
               << playerPtr->getSpeed() << endl;
               break;
            case GameConst::cheatEngine:
               cout << "\n You got the secret code; you are, therefore, the chosen one. "
               << "I shall grant you the power to modify anything in this Universe at will.\n\n";
               CheatEngine::CheatEngineMain(playerPtr, &position, areaLevel, cout);
               break;
            case GameConst::quit:
               cout << "Game over, you have quit!\n";
               return EXIT_SUCCESS;
               break;
            case GameConst::take:
               if(((*areaPtr)[position]).getEnemy() == nullptr)
                  areaPtr->tryTakeItem(playerPtr, position);
               else
                  cout << "Can not take.\n";
               break;
            case GameConst::notFound:
               throw NotFoundException();
               break;
         }
      }
      catch (const NotFoundException& ne)
      {
         ne.displayMsg();
      }
      areaPtr->updateCurrentRoom(position, playerPtr); //update room status before it loads, sets traps if appropriate room.
   }
   if(playerPtr->getHp() <= 0)
   {
      cout << "\nThe universe will never know the name of " << narration.name() << ", for they have died...\n\n";
   }
   release(playerPtr, areaPtrs);
   system("pause");
   return EXIT_SUCCESS;
}

void release(PlayerCharacter* & playerPtr,  deque<Area*>& obj)
{
   if (playerPtr)
   {
      delete playerPtr;
      playerPtr = nullptr;
   }
   for (auto deqIt = obj.begin(); deqIt != obj.end(); ++deqIt)  // C++11 using auto type, saving type time
   {
      if (*deqIt)
      {
         delete *deqIt;
         *deqIt = nullptr;
      }
   }
}

PlayerCharacter* getPlayer()
{
   Race race = static_cast<Race>(KeyBoard::getRaceMenu());
   
   switch (race)
   {
      case GameConst::Golem:
         return new PlayerCharacter(100, 30, 50, "Golem");
         break;
      case GameConst::Sphinx:
         return new PlayerCharacter(25, 10, 75, "Sphinx");
         break;
      case GameConst::Human:
         return new PlayerCharacter(70, 20, 65, "Human");
         break;
      default:
         return new PlayerCharacter(9999, 9999, 999, "God");
   }
}

void displayStartMenu()
{
	cout
		<< "\n\n\n"
		<< "\t ########::'#######::'########::'########:\n"
		<< "\t ##.....::'##.... ##: ##.... ##:... ##..::\n"
		<< "\t ##::::::: ##:::: ##: ##:::: ##:::: ##::::\n"
		<< "\t ######::: ##:::: ##: ########::::: ##::::\n"
		<< "\t ##...:::: ##:::: ##: ##.. ##:::::: ##::::\n"
		<< "\t ##::::::: ##:::: ##: ##::. ##::::: ##::::\n"
		<< "\t ##:::::::. #######:: ##:::. ##:::: ##::::\n"
		<< "\t ..:::::::::.......:::..:::::..:::::..::::\n"
		<< endl;
	cout
		<< "\t:'######::'####:'########::'######:::'########:\n"
		<< "\t'##... ##:. ##:: ##.....::'##... ##:: ##.....::\n"
		<< "\t'##:::..::: ##:: ##::::::: ##:::..::: ##:::::::\n"
		<< "\t. ######::: ##:: ######::: ##::'####: ######:::\n"
		<< "\t:..... ##:: ##:: ##...:::: ##::: ##:: ##...::::\n"
		<< "\t'##::: ##:: ##:: ##::::::: ##::: ##:: ##:::::::\n"
		<< "\t. ######::'####: ########:. ######::: ########:\n"
		<< "\t:......:::....::........:::......::::........::\n";
	cout
		<< "\t+----------------------------------------------------------+\n"
		<< "\t|    WRITTEN BY:                                           |\n"
		<< "\t|                                                          |\n"
		<< "\t|    Chris Tran                                            |\n"
		<< "\t|    Quan Bui                                              |\n"
		<< "\t|    Kyle Gomez                                            |\n"
		<< "\t|    Carolyn Yen                                           |\n"
		<< "\t|    Jaye Wang                                             |\n"
		<< "\t|                                                          |\n"
		<< "\t|    SPECIAL THANKS: Joe Bentley                           |\n"
		<< "\t+----------------------------------------------------------+\n\n";
	cout << "\tPRESS ANY KEY TO START" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}