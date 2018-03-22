#pragma once
#include <iostream>
#include <limits>
#include <iomanip>
#include "Character.h"
#include "Area.h"
#include "GameNamespace.h"

namespace CheatEngine
{
	void CheatEngineMain(PlayerCharacter*&, Position*, int&, std::ostream&);
	void CheatEngineMenu(std::ostream&);
	void raceModifier(PlayerCharacter*&, std::ostream&);
	void statsModifier(PlayerCharacter*, std::ostream&);
	void teleporter(int&, Position*, std::ostream&);
	void wardrobe(PlayerCharacter*, std::ostream&);
}


