#include "Area.h"

// This founction allow random notFound command error msg to display.
void NotFoundException::displayMsg()
{
   switch (rand() % 3) {
      case 0:
         std::cout << "Hey, what you entered makes no sense to me!\n";
         break;
      case 1:
         std::cout << "Hey, silly commands!\n";
         break;
      case 2:
         std::cout << "Can't you type a right command?\n";
         break;
      default:
         break;
   }
}

////////////////////////////////////////////////////////////////////////////////////

Position::Position(const unsigned& r, const unsigned& c) : row(r), col(c)
{
}

bool Position::move(const unsigned &dir)
{
   Direction d = static_cast<Direction>(dir);
   try {
      switch (d)
      {
         case East:
            if ((col + 1) >= COL) throw (std::string("you have hit the East wall"));
            col++;
            break;
         case South:
            if ((row + 1) >= ROW) throw (std::string("you have hit the South wall"));
            row++;
            break;
         case West:
            if (col == 0) throw (std::string("you have hit the West wall"));
            col--;
            break;
         case North:
            if (row == 0) throw (std::string("you have hit the North wall"));
            row--;
            break;
         default:;
      }
   }
   catch (std::string msg)
   {
      std::cout << "Move failed, " << msg << "\n\n";
   }
   return 1;
}

bool Position::operator==(const Position& arg) const
{
   if (row == arg.row and col == arg.col)
      return 1;
   return 0;
}

bool Position::operator!=(const Position& arg) const
{
   return !(this->operator==(arg));
}

std::ostream& operator<<(std::ostream& os, const Position& pos)
{
   os << " at position (" << pos.row + 1 << ", " << pos.col + 1 << ")";
   return os;
}

////////////////////////////////////////////////////////////////////////////////////

std::string KeyBoard::get1stToken(const std::string& arg, const std::string& delimeter)
{
   size_t pos = arg.find_first_of(delimeter);
   return arg.substr(0, pos);
}

// This function prompts the user to enter an integer number within a given range
// If the input is not valid (not a number or if it is outside of the range) it
// prompts the user to enter a new number, until the input is valid.
int KeyBoard::getValidNum(const int& low, const int& high)
{
   int num;
   do
   {
      std::cout << "Enter your choice, a number (" << low << " to " << high - 1 << "): ";
      std::cin >> num;
      std::cin.clear();          // to clear the error flag
      std::cin.ignore(80, '\n'); // to discard the unwanted input from the input buffer
   } while (std::cin.fail() || num < low || num > high);

   return num;
}

// getRaceMenu
// Prompt kinds of race that the player can choose.
// Return an numeric value to caller indicating what race the player want to choose.
int KeyBoard::getRaceMenu()
{
   int choice;
   // Display the race menu and get the user's choice.
   std::cout << "\nWhat race would you like to choose?\n\t"
   << Golem
   << " - Golem has hp 100, damage 30, and 50 speed\n\t"
   << Sphinx
   << " - Sphinx has hp 25, damage 10, and 80 speed\n\t"
   << Human
   << " - Human has hp 70, damage 20, and 70 speed\n";

   choice = getValidNum(Golem, God);
   return choice;
}

// getActionMenu
// Return an numeric value to caller indicating what the general action is.
// Parameter moreInfo will give more detailed action the user want to perform.
// For example: if move action is returned, moreInfo will specify spefic direction
// for the caller.
int KeyBoard::getActionMenu(int& moreInfo)
{
   std::string     line;   // the entire input from the player
   std::string     action; // first token of the input

   std::cout << "\nEnter your command : ";
   getline(std::cin, line);
   action = get1stToken(line);

   if (action == "help" or action == "h")
      return help;
   else if (action == "quit" or action == "q" or action == "exit")
      return quit;
   else if (action == "map" or action == "m")
      return printMap;
   else if (action == "attack" or action == "a")
      return attack;
   else if (action == "take" or action == "t")
      return take;
   else if (action == "west" or action == "w")
   {
      moreInfo = Position::West;
      return GameConst::move;
   }
   else if (action == "south" or action == "s")
   {
      moreInfo = Position::South;
      return GameConst::move;
   }
   else if (action == "east" or action == "e")
   {
      moreInfo = Position::East;
      return GameConst::move;
   }
   else if (action == "north" or action == "n")
   {
      moreInfo = Position::North;
      return GameConst::move;
   }
   else if (action == "info" or action == "i")
      return info;
   else if (action == "bag" or action == "b")
      return bag;
   // Enable CheatEngine
   else if (action == "42")
      return cheatEngine;
   else if (action == "up" or action =="u")
      return up;
   else if (action == "down" or action =="d")
      return down;
   else
      return notFound;
}

void KeyBoard::displayHelpMenu()
{
   std::cout
   << " \n\tHere are the valid commands\n"
   << "\t+------------------------------------------------------+\n"
   << "\t|    [h]elp    -- " << " print the commands menu             |\n"
   << "\t|    [q]uit    -- " << " quit/exit the game                  |\n"
   << "\t|    [m]ap     -- " << " show the map and current area       |\n"
   << "\t|    [a]ttack  -- " << " attack enemy                        |\n"
   << "\t|    [w]est    -- " << " move one spot towards the west      |\n"
   << "\t|    [s]outh   -- " << " move one spot towards the south     |\n"
   << "\t|    [e]ast    -- " << " move one spot towards the east      |\n"
   << "\t|    [n]orth   -- " << " move one spot towards the north     |\n"
   << "\t|    [t]ake    -- " << " take the item in the current room   |\n"
   << "\t|    [i]nfo    -- " << " show your stats and their meanings  |\n"
   << "\t|    [b]ag     -- " << " show your inventory                 |\n"
   << "\t|    [u]p      -- " << " go to the previous area.            |\n"
   << "\t|    [d]own    -- " << " go to the next area.                |\n"
   << "\t+------------------------------------------------------+\n\n";
}

////////////////////////////////////////////////////////////////////////////////////

Area::Area(const int& at) : areaType(at)
{
   int         randRoomType;
   Position    currPos;
   Position    randBossPos(rand() % ROW , rand() % COL);
   Position    firstRoomPos(0,0);

   while(randBossPos == firstRoomPos) // force the first room to not be boss room
      randBossPos = Position(rand() % ROW , rand() % COL );
   bossPos = randBossPos;

   for (auto i = 0u; i < ROW; i++)
      for (auto j = 0u; j < COL; j++)
      {
         currPos = Position(i, j);
         if(currPos == firstRoomPos)
         {
            rooms[i][j] = new Room(emptyRoom, areaType, i, j);
            continue;
         }
         else if (currPos == randBossPos)
         {
            rooms[i][j] = new Room(bossRoom, areaType, i, j);
            continue;
         }
         randRoomType = rand() % (NUM_ROOM_TYPES);
         while (randRoomType == bossRoom)
            randRoomType = rand() % (NUM_ROOM_TYPES); // Disallow bossRoom get intialized here
         rooms[i][j] = new Room(randRoomType, areaType, i, j);
      }
   rooms[0][0]->setDiscovered();// set the intial room as discovered flag
}

Area::~Area()
{
   for (auto i = 0u; i < ROW; i++)
      for (auto j = 0u; j < COL; j++)
         if (rooms[i][j])
         {
            delete rooms[i][j];
            rooms[i][j] = nullptr;
         }
}

void Area::tryMovePosition(PlayerCharacter * player, Position& pos, const unsigned& dir)
{
   Enemy* enemy = (*this)[pos].getEnemy();
   bool moved;
   if (enemy)
   {
      if (player->getSpeed() > (rand() % 91))
      {
         moved = pos.move(dir);
         std::cout << "You were quick on your feet and escaped!\n\n";
      }
      else
      {
         moved = 0;
         std::cout << "Move failed because you are not fast enough!\n\n";
      }
   }
   else
      moved = pos.move(dir);
   // If move() success. set the new room as discoverd
   if (moved == true)
      (*this)[pos].setDiscovered();
}

// Return false if and only if the player try to take item while there is no item in
// the room.
bool Area::tryTakeItem(PlayerCharacter* player, const Position& pos)
{
   bool itemExist = (*this)[pos].itemInRoom();
   if (itemExist)
   {
      (*this)[pos].giveItem2Player(player);
      return true;
   }
   return 0;
}

// Return false if and only if the room specified by pos has neither enemy nor boss.
bool Area::tryPerformAttack(PlayerCharacter* player, const Position& pos)
{
   Enemy* enemy = (*this)[pos].getEnemy();
   bool enemyRoom = (*this)[pos].enemyRoom();
   bool bossRoom = (*this)[pos].bossRoom();
   int damage = player->attack();

   // If this is a boss room, the player can attack
   if (enemyRoom or bossRoom)
   {
      // Check to see if enemy is dead, if dead prints out message and update map icon. Player won't be able to attack it
      if (enemy->isDead()){
         if(!bossRoom)
         {
            if(player->getInventory()[WEAPON].name() == "Millennium Puzzle (+30 dmg)")
            {
               cout << "MIND CRUSH! ";
            }
            std::cout << "Enemy is dead!\n";
         }
      }
      // Else, player will attack, and enemy will take damage (zero or non-zero)
      else
      {
         enemy->takeDamage(damage);

         // If damage is zero, that means player missed
         if (damage == 0)
            std::cout << "You missed... \n";
         // Else enemy should take damage
         else
            std::cout << "You dealt : " << damage << " damage\n";

         // Again, check if the enemy is dead after the attack. If dead, print confirmation and update map icon
         if (enemy->isDead())
         {
            if(!bossRoom)
            {
               if(player->getInventory()[WEAPON].name() == MILLENNIUM_PUZZLE.name())
               {
                  cout << "MIND CRUSH! ";
               }
               else if(player->getInventory()[WEAPON].name() == MERMAIDMANS_BELT.name())
               {
                  cout << "WUMBO'D! ";
               }
               else if(player->getInventory()[WEAPON].name() == REAPER_OF_SOULS.name())
               {
                   cout << "Your soul is mine... ";
               }
               else if(player->getInventory()[WEAPON].name() == LIGHT_SABER.name())
               {
                   cout << "The force is not with you. ";
               }
               std::cout << "Enemy is dead!\n\n";
            }
            else
            {
                cout << "You have slain the " << enemy->name() << endl << endl;
            }
         }
         // If not, enemy will attack player
         else
         {
            if(player->takeDamage(enemy->attack()) == true)
            {
               std::cout << "You take " << ((enemy->attack()-player->getInventory()[ARMOR].getValue()) > 0 ? (enemy->attack()-player->getInventory()[ARMOR].getValue()) : 0 )
               << " damage from the " << enemy->name() << "\n";
               std::cout << "Your current health is: " << player->getHp() << std::endl;
            }
            else
            {
               std::cout << "Your current health is: " << player->getHp() << std::endl;
            }
         }
      }
   }
   else
      return 0;
   return 1;
}

void Area::displayAreaInfo() const
{
   AreaType a = static_cast<AreaType>(areaType);
   std::cout << " You are standing in ";
   switch (a)
   {
      case spaceArea:
         std::cout << "the space area!";
         break;
      case desertArea:
         std::cout << "the desert area!";
         break;
      case waterArea:
         std::cout << "the water area!";
         break;
      case fortArea:
         std::cout << "the fort area!";
         break;
      default:;
   }
}

void Area::displayMap(const Position& pos) const
{
   for (auto j = 0u; j < COL; j++)
      std::cout << ((j == 0) ? "\nR\\C" : "") << "   " << j + 1 << "   ";
   std::cout << "\n\n";

   for (auto i = 0u; i < ROW; i++)
   {
      for (auto j = 0u; j < COL; j++)
      {
         if (j == 0)
            std::cout << " " << i + 1 << " "; // display row number
         std::cout << " ( ";

         if (Position(i, j) == pos)
            std::cout << "O"; // O means the position the player is currently at
         else if (rooms[i][j]->discovered())
            std::cout << rooms[i][j]->getMapSym();
         else
            std::cout << rooms[i][j]->getMapSym();
         //                     std::cout << "*"; // * means the room is now seeable to the player at this moment
         std::cout << " ) ";
      }
      std::cout << "\n";

      for (auto j = 0u; j < COL; j++)
         std::cout << ((j == 0) ? "   " : "") << "  ___  ";
      std::cout << "\n\n";
   }
   this->displayAreaInfo();
   std::cout << pos << ": ( "
   << rooms[pos.getRow()][pos.getCol()]->getMapSym() << " )\n";
   //   this->displayRoom(pos);

   // Displays a legend of all the symbols
   std::cout << "+------------------------------------------+\n";
   std::cout << "|Legend: T = Trap, E = Enemy, B = Boss     |\n";
   std::cout << "|        - = Empty Room, O = Your Position |\n";
   std::cout << "+------------------------------------------+\n";
   std::cout << std::endl;
}

void Area::displayRoom(const Position& p) const
{
   std::cout << *rooms[p.getRow()][p.getCol()];
}
//kyle: added this.
void Area::updateCurrentRoom(const Position& c, PlayerCharacter* &pc)
{
   (*this)[c].changeToRoomStatus(pc);
}

Room& Area::operator[](const Position& pos)
{
   return *rooms[pos.getRow()][pos.getCol()];
}

ostream& operator<< (ostream& os, const Area& area)
{
   area.displayAreaInfo();
   return os;
}

bool Area::isBossDead()
{
   return (*this)[bossPos].isBossDead();
}

void Area::checkHealPlayer(const Position & p, PlayerCharacter* &pc)
{
   if ((*this)[p].healRoom())
   {
      pc->restore_hp();
      std::cout << "\n*--------------------------------------------*\n";
      std::cout << "How convenient, you found a healing fountain!\n";
      std::cout << "Health restored to "<< pc->getHp() <<"!\n";
      std::cout << "*--------------------------------------------*\n\n";
   }
}

Position Area::getBossPos() const
{
   return bossPos;
}

int Area::getAreaType() const
{
   return areaType;
}
