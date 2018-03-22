#pragma once
#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Character.h"
#include "RoomDescription.h"

class Room
{
private:
   Item item; 
   Enemy* enemy;
   bool hasEnemy;
   bool hasTrap;
   bool hasBoss;
   bool setTrap;
   bool hasItem;
   bool isDiscovered;
   bool isEmpty;
   int xCoord, yCoord;
   int areaType;
   int itemChance;
   RoomDescription* rD; //this is for returning the description of the room.
   //^ encapsulated the room desc in an onject for less clutter in the Room class.
   char mapSymbol;
   std::string trapNotif;
   bool healingRoom;

public:
   //   Room(const Room&r)

   //Pre: 1st arg: -0 Enemy, 1 Trap Room, 2 Boss Room, 3 Empty
   //     2nd arg: 0 Space, 1 Desert, 2 Water, 3 Fort, 4 Final Level
   //     3rd arg: x coord in the array
   //     4th: y coord in the array
   //     Values omitted will go to their defaults. Areas 0-3 will have 25 rooms.
   //     Last area will have one room implemented differenly by Area class/Main.
   //Post: Constructs a "default" room that contains its design purpose's objects.
   //  exmaple: an enemy room instantiates an enemy along with a description to read and loot for
   //          player to take.
   Room(const int& i = 3, const int& aType = 4, const int& xPoint = 0, const int& yPoint = 0);

   ~Room();//cleanup

   // Print out every rooms info in detailed
   friend std::ostream& operator << (std::ostream& os, const Room& r);

   // This function will attack the player based on what does the room have, eg, hasTrap or hasEnemy or hasBoss
   //  It is going to change the health of the player. There is the chance that the player can take 0 damage if the speed of player is fast enough.
   void trapDmgPlayer(PlayerCharacter* & pc);

   // This function will give an an item of type int to the player. Do not call without checking other bools if you want them to work for it.
   void giveItem2Player(PlayerCharacter* & player);

   // This function will let character attack enemy, it might change enemy's
   // EHP = EHP - PlayerDamage);
   // EHP <=0 enemy is dead
   //void attack(Character* ptr) {}

   //This function will allow the player log the room symbol in their map
   void setDiscovered();

   //This function will check if the enemy is dead and make adjustments to the map icon
   //and the description
   void changeToRoomStatus(PlayerCharacter* & pc);

   bool isBossDead();//call this when needing boss status and cleanup before changeroomstatus call(before the end of loop in area).
   bool healRoom();
   //getters:
   int getXcoord() const;
   int getYcoord() const;
   char getMapSym() const; // gets the symbol for map printing
   Enemy* getEnemy() const;
   const Item getItemObj() const;
   //this function accesses the roomDesc object and returns the string description of room.
   std::string descRoom() const;
   int getAreaType() const;
   Item getItem() const;
   bool isTrapSet();
   bool empty() const;
   bool trapRoom() const;
   bool enemyRoom() const;
   bool bossRoom() const;
   bool discovered() const;
   bool itemInRoom() const;
};

#endif /* Room_h */
