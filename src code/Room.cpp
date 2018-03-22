#include "Room.h"

/*
 Room types:
 0 - Enemy Room
 1 - Room with Trap
 2 - Boss Room
 3 - Empty Room
 
 Default - DONT DO THAT
 */

Room::Room(const int& i, const int& aType, const int& xPoint, const int& yPoint)
{
   xCoord = xPoint;
   yCoord = yPoint;
   areaType = aType;
   rD = new RoomDescription(i, aType);
   enemy = nullptr;
   isDiscovered = false;
   hasEnemy = false;
   setTrap = false;
   hasBoss = false;
   hasTrap = false;
   hasItem = false;
   isEmpty = false;
   trapNotif = "";
   healingRoom = ((rand() % 100) < 25) ? true : false;
   switch (i)
   {
      case 0: //this is an enemy room
         mapSymbol = 'E';
         hasEnemy = true;
         hasItem = true;
         switch (aType)
      {
         case 0://space
            enemy = new SpaceZombie();
            //item = enemy->getInventory()[rand() % 3];
            itemChance = rand() % 101;
            if(itemChance <= 40)
            {
               item = enemy->getInventory()[0];
            }
            else if(itemChance <= 75 && itemChance > 40)
            {
               item = enemy->getInventory()[1];
            }
            else if(itemChance <= 95 && itemChance > 75)
            {
               item = enemy->getInventory()[2];
            }
            else
            {
               item = LIGHT_SABER;
            }
            break;
         case 1://desert
            enemy = new Nomad();
            //item = enemy->getInventory()[rand() % 3];
            itemChance = rand() % 101;
            if(itemChance <= 40)
            {
               item = enemy->getInventory()[0];
            }
            else if(itemChance <= 75 && itemChance > 40)
            {
               item = enemy->getInventory()[1];
            }
            else if(itemChance <= 95 && itemChance > 75)
            {
               item = enemy->getInventory()[2];
            }
            else
            {
               item = MILLENNIUM_PUZZLE;
            }
            break;
         case 2://water
            enemy = new Siren();
            //item = enemy->getInventory()[rand() % 3];
            itemChance = rand() % 101;
            if(itemChance <= 40)
            {
               item = enemy->getInventory()[0];
            }
            else if(itemChance <= 75 && itemChance > 40)
            {
               item = enemy->getInventory()[1];
            }
            else if(itemChance <= 95 && itemChance > 75)
            {
               item = enemy->getInventory()[2];
            }
            else
            {
               item = MERMAIDMANS_BELT;
            }
            break;
         case 3://fort
            enemy = new Goons();
            //item = enemy->getInventory()[rand() % 3];
            itemChance = rand() % 101;
            if(itemChance <= 40)
            {
               item = enemy->getInventory()[0];
            }
            else if(itemChance <= 75 && itemChance > 40)
            {
               item = enemy->getInventory()[1];
            }
            else if(itemChance <= 97 && itemChance > 75)
            {
               item = enemy->getInventory()[2];
            }
            else
            {
               item = REAPER_OF_SOULS;
            }
            break;
         default:
            std::cout << "Invalid area" << std::endl;
      }
         break;
      case 1: //this is a trap room
         mapSymbol = 'T';
         hasTrap = true;
         int b;
         b = rand() % 2;
         switch (aType)
      {
         case 0://space
            if (b)
               trapNotif = "A beeping pulse tweets and sends shrapnel flying into you.\n";
            else
               trapNotif = "You set off a laser trip mine! *KABOOM* The thermal explosion sears your body.\n";
            break;
         case 1://desert
            if (b)
               trapNotif = "*WOOSH* You are flung into a pit of giant Pythons.\nYou managed to fight your way out, but you took a beating.\n";
            else
               trapNotif = "You notice a line of rope connected to a tree snag your feet.\nIt flings you to the sky and back down to the ground. Ouch.\n";
            break;
         case 2://water
            if (b)
               trapNotif = "The shiny object was bait set by a venomous angler fish.\nIt roughed you up, but you managed to kill it.\n";
            else
               trapNotif = "You pulled on a venomous lamprey eel's tail. It smacked you for being rude and swam off.\n";
            break;
         case 3://fort
            if (b)
               trapNotif = "A hammer drops from the ceiling and punts you across the room! Ouch!\n";
            else
               trapNotif = "A hail of arrows fly at you from every direction!\nYou duck and managed to escape with few cuts from the arrowheads.\n";
            break;
         default:
            std::cout << "Invalid trap" << std::endl;
      }
         break;
      case 2: //this is a boss room
         mapSymbol = 'B';
         hasBoss = true;
         switch (aType)
      {
         case 0://space
            enemy = new Alien();
            //item = LASER_GUN;
            break;
         case 1://desert
            enemy = new MetalScorpion();
            //item = SCIMITAR;
            break;
         case 2://water
            enemy = new KillerWhale();
            //item = HAND_CANNON;
            break;
         case 3://fort
            enemy = new Boss();
            //item = HAND_CANNON;
            break;
         default:
            break;
      }
         break;
      default: //this is an empty room
         mapSymbol = '-';
         isEmpty = true;
         
   }
}
void Room::trapDmgPlayer(PlayerCharacter* & pc)
{
   int pHp, dmg, oHp;
   pHp = pc->getHp();
   dmg = int(double(pHp)*.15);
   //cout << dmg << " goes in\n";
   pc->takeDamage(dmg);
   oHp = pc->getHp();
   if (pHp - oHp == 0)
   {
      std::cout << "Phew, close call.\n";
   }
   else
   {
      //cout << pHp << endl;
      //cout << oHp << endl;
      std::cout << pHp - oHp << " damage recieved!\n";
   }
}
Room::~Room()
{
   if (rD)
   {
      delete rD;
      rD = nullptr;
   }
   if (enemy)
   {
      delete enemy;
      enemy = nullptr;
   }
} //cleanup
// Print out every rooms info in detailed
std::ostream& operator << (std::ostream& os, const Room& r) {
   // Make sure the room description only appeared once
   static int intPrevX = 0, intPrevY = 0;      // Save the last room pass to this function
   static bool firstCall = true;
   
   // Compare last room coordinates and current room coordinates.
   // If this is the first call, then print the room info no matter what (for first move to an 1, 1 in an area). //TODO: improve later on
   if (firstCall || intPrevX != r.getXcoord() || intPrevY != r.getYcoord())
   {
      firstCall = false;
      os << r.descRoom() << std::endl;
   }
   
   if (r.enemyRoom())
   {
      os << r.getEnemy()->getInfo();
      os << "The " << r.getEnemy()->name() << " strikes!" << std::endl;
   }
   else if (r.bossRoom()) {
      
      if (r.getEnemy()) // Jaye : the enemy could point to nullptr
         os << r.getEnemy()->getInfo();
      os << "Behold: the " << r.getEnemy()->name();
      
      if (r.itemInRoom())
         os << "who guards the" << r.getItemObj().name();
      os << std::endl;
   }
   else if (r.itemInRoom() == true && r.enemyRoom() == false)
   {
      os << "You found a " << r.getItem().name() << "\n";
   }
   else
      //os << std::endl;
      
      // Save the current room coordinates to compare next room
      intPrevX = r.getXcoord();
   intPrevY = r.getYcoord();
   
   return os;
   //no condition for trap room, its already initialized in roomDesc/descRoom
   //no condition for empty room, same thing
}

// This function will give an an item of type int to the player. Do not call without checking other bools if you want them to work for it.
void Room::giveItem2Player(PlayerCharacter* & player)
{
   player->receiveItem(item);
   cout << "You took the " << item.name() << ".\n";
   hasItem = false;
}

// This function will let character attack enemy, it might change enemy's
// EHP = EHP - PlayerDamage);
// EHP <=0 enemy is dead
//void attack(Character* ptr) {}

//This function will allow the player log the room symbol in their map
void Room::setDiscovered() { isDiscovered = true; }

//This function will check if the enemy is dead and make adjustments to the map icon
//and the description
void Room::changeToRoomStatus(PlayerCharacter* & pc)
{
   if (hasEnemy)
   {
      if (enemy->isDead())
      {
         hasEnemy = false;
         delete enemy;
         enemy = nullptr;
         delete rD;
         rD = new RoomDescription(3, areaType);
         if (hasItem)
         {
            if(item.name() == LIGHT_SABER.name() || item.name() == MILLENNIUM_PUZZLE.name() || item.name() == MERMAIDMANS_BELT.name() || item.name() == REAPER_OF_SOULS.name())
            {
               cout << "What is this?! The enemy dropped a " << item.name() << "! Lucky!" << endl;
            }
            else
            {
               cout << "The enemy dropped a " << item.name() << endl;
            }
         }
      }
   }
   else if (hasBoss && enemy->isDead())//boss death event
   {
      if (enemy) {
         delete enemy;
         enemy = nullptr;
         delete rD;
         rD = new RoomDescription(3, areaType);
         hasBoss = false;
         if (hasItem)
         {
            //std::cout << "You found a " << item.name() << "\n";
            mapSymbol = 'I';
         }
         else
            mapSymbol = 'X';
      }
   }
   else if (hasTrap)
   {
      if (setTrap == false)
      {
         setTrap = true;
         mapSymbol = 'T';
      }
      else
      {
         std::cout << trapNotif;
         trapDmgPlayer(pc);
         hasTrap = false;
         mapSymbol = '-';
         delete rD;
         rD = new RoomDescription(3, areaType);
      }
   }
   else if (hasItem)
   {
      //std::cout << "You found a " << item.name() << "\n";
      mapSymbol = 'I';
      delete rD;
      rD = new RoomDescription(3, areaType);
   }
   else if (hasBoss)
   {
      mapSymbol = 'B';
   }
   else
   {
      mapSymbol = '-';
   }
}

//getters:
int Room::getXcoord() const { return xCoord; }
int Room::getYcoord() const { return yCoord; }
char Room::getMapSym() const { return mapSymbol; } // gets the symbol for map printing
Enemy* Room::getEnemy() const { return enemy; }
const Item Room::getItemObj() const { return item; }
//this function accesses the roomDesc object and returns the string description of room.
std::string Room::descRoom() const { return rD->getRoomDesc(); }
int Room::getAreaType() const { return areaType; }
Item Room::getItem() const { return item; }

bool Room::empty() const { return isEmpty; }
bool Room::trapRoom() const { return hasTrap; }
bool Room::enemyRoom() const { return hasEnemy; }
bool Room::bossRoom() const { return hasBoss; }
bool Room::discovered() const { return isDiscovered; }
bool Room::itemInRoom() const { return hasItem; }
bool Room::healRoom()
{
   if (healingRoom && isEmpty)
   {
      healingRoom = false;
      return true;
   }
   else
      return false;
}
bool Room::isBossDead()
{
   if (hasBoss == true)
   {
      if (enemy->isDead())
      {
         delete enemy;
         enemy = nullptr;
         delete rD;
         rD = new RoomDescription(3, areaType);
         hasBoss = false;
         if (hasItem)
         {
            std::cout << "You found a " << item.name() << "\n";
            mapSymbol = 'I';
         }
         else
            mapSymbol = 'X';
         return true;
      }
      return false;
   }
   else
      return false;
}

