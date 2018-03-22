#pragma once
#ifndef Area_h
#define Area_h
#include "Room.h"
#include "GameNamespace.h"
#include <ciso646>

using namespace GameConst;

////////////////////////////////////////////////////////////////////////////////////

class NotFoundException
{

public:
   static void displayMsg(); // prompt msg player enter not found command
};

////////////////////////////////////////////////////////////////////////////////////

class Position
{
private:
   unsigned row;
   unsigned col;

public:
   enum Direction { East, South, West, North };
   Position(const unsigned& r = 0, const unsigned& c = 0);
   bool move(const unsigned& dir);

   unsigned getRow() const { return row; }
   unsigned getCol() const { return col; }

   void setRow(unsigned inRow) { row = inRow; }
   void setCol(unsigned inCol) { col = inCol; }

   bool operator==(const Position& arg) const;
   bool operator!=(const Position& arg) const;
   friend std::ostream& operator<< (std::ostream& os, const Position&);
};


////////////////////////////////////////////////////////////////////////////////////

class KeyBoard
{
public:

   static std::string get1stToken(const std::string& arg, const std::string& delimeter = " ");
   static int getValidNum(const int& low, const int& high);// Return a valid number ranging from low to high. Value include low or high.
   static int getRaceMenu(); // Get a valid race from getRaceMenu.
   static int getActionMenu(int&);
   static void displayHelpMenu();
};

////////////////////////////////////////////////////////////////////////////////////

class Area
{
private:
   Room*    rooms[ROW][COL];
   int      areaType;
   Position bossPos;
public:
   Area(const int&);
   ~Area();
   Area(const Area&) = delete; // C++11 disallow copy constructor

   Area& operator= (const Area&) = delete; // C++11 disallow compiler generated overloaded assignment operator
   Room& operator[] (const Position& pos); // Return the room specified in pos.
   friend ostream& operator<< (ostream& os, const Area& area);
   
   void tryMovePosition(PlayerCharacter *, Position& , const unsigned& );
   bool tryTakeItem(PlayerCharacter*, const Position& );
   bool tryPerformAttack(PlayerCharacter*, const Position&); // Player could Potentially attack enemy or boss
   void displayAreaInfo() const; // Display the area information.
   void displayMap(const Position&) const;  //  Display the grid of the map
   void displayRoom(const Position&) const; // Display room with position specified by the row and col parameter.
   void updateCurrentRoom(const Position&, PlayerCharacter* &);// added: kyle
   bool isBossDead();
   void checkHealPlayer(const Position &, PlayerCharacter* &);
   
   Position getBossPos() const;
   int getAreaType() const;
};

#endif /* Area_h */
