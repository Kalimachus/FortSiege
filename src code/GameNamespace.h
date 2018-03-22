#ifndef GameNamespace_h
#define GameNamespace_h

namespace GameConst
{
   enum Race { Golem, Sphinx, Human, God }; // to be modified

   const unsigned ROW = 5;  // Row number for Area
   const unsigned COL = 5;  // Col number for Area

   const unsigned NUM_ROOM_TYPES = 4;  // There are four types of room.
   enum RoomType { enemyRoom, trapRoom, bossRoom, emptyRoom };

   const unsigned NUM_AREA_TYPES = 4;  // There are four types of area.
   enum AreaType { spaceArea, desertArea, waterArea, fortArea, victory };

   // Possible action menu.
   enum ActionMenu
   { help, attack, printMap, move, up, down, notFound, take, quit, /*status,*/ info, bag, cheatEngine };
}

#endif /* GameNamespace_h */
