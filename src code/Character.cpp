#include "Character.h"

void Narration::intro() const
{
   cout << "\nIn the year 27xx the Earth along with the other planets in the Solar System\nbecame victims to a foreign virus.";
   cout << " As an attempt to stop the spread, the people\nof Earth tried relentlessly to create a cure, but the virus spread too fast.\n";
   cout << "As a last ditch effort the few remaining humans proposed a plan to escape the\nSolar System and found a new colony in another ";
   cout << "planetary system.\nTo their luck, the few remaining humans were able to make contact with another\ncivilization. ";
   cout << "This new civilization consisted of Sphinx's who are cat\npeople, Golems, and now humans. ";
   cout << "\nThe time now is 28xx and all seemed well in this new planetary system.\nYou, " << CharName;
   cout << ", have been assigned to the Galactic Space Federations\nnew patrol ship, the 'SP_932 Alpha', the Space Federations flagship vessel.\n";
   cout << "What you believed to be a simple patrol through space turns into something much much worse...\n";
   cout << endl << "'Press enter to continue...'" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Narration::EnterSpaceship() const
{
   cout << "You awaken to the sounds of an alarm, red lights flashing all around you. \nA distressing message plays over the intercom on repeat,\n";
   cout << "\"Warning, the vessel has been compromised. Entering emergency lockdown. \nPlease make your way to the escape pods.\"\n";
   cout << endl << "'Press enter to continue...'" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Narration::SpaceEscapeRoom() const
{
   cout << "After defeating the Alien you notice that you are standing in the escape room.\nYou see a blood trail";
   cout << " leading into one of the two escape pods before you.\nYou follow the blood trail into the escape pod ";
   cout << "and find a deceased Sphinx\ncrew member and with him a notebook. ";
   cout << "You open the notebook and within it a\nbunch of notes are scribbled, one of which catches your eye.";
   cout << endl;
   cout << " \n\"I knew it! The federation has been keeping the secret from us, but I knew.\nThe virus from 100 years ago";
   cout << " it was carried over by the humans. We should\nnever have let them into our civilization!";
   cout << " Now look at us, everyone on board\nis succumbing to the virus. But I will not! I am taking these two keys";
   cout << " and I\nwill escape. Hopefully, by preventing anyone else from getting off this ship\nI will save another civilization ";
   cout << "from the horrors that befell this crew.\"\n";
   cout << endl << "'Press enter to continue...'" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cout << "Putting two and two together, you realise that the space zombies and the\nAlien you defeated on the ship are the other crew members";
   cout << " who have been\ninfected by the virus. No one ever talked about what the virus did, you\nonly knew that there was once ";
   cout << "a highly contagious and deadly virus forcing\nhumans to come to this planetary system. After a bit more searching,\nyou head";
   cout << " to the other escape pod and eject yourself from the ship.\n";
   cout << endl << "'Press enter to continue...'" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void Narration::EnterDesert() const
{
   cout << "You have successfully escaped the spaceship before it crashed down onto the\nplanet below.";
   cout << "From within the escape pod you see the burning spaceship falling.\nYou think to yourself,\"";
   cout << "Man, " << CharName << " what did I get myself into.\" As you gaze\nout the window of the escape ";
   cout << "pod, you notice that you are getting pulled down\nonto the planet along with the spaceship.";
   cout << " You start pressing every button in\nthe escape pod in hopes that one of them will help you ";
   cout << "escape the pull of the\nspaceship. But the only thing you accomplished was causing the ";
   cout << "escape pod to\nfall faster.\n";
   cout << endl << "'Press enter to continue...'" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cout << "The escape pod crashes and slides across the surface of the planet. ";
   cout << "After a few moments\nof banging yourself against the inside of the escape ";
   cout << "pod, the pod comes to a stop.\n";
   cout << "After regaining your bearings, you push open the door to the escape pod.";
   cout << " You try to scope\nout the environment but the harsh sun blinds you.";
   cout << " As you wait for your eyes to adjust you\nstart to sweat profusely.";
   cout << " Your feet burns from the sand at your feet. You only know of\none";
   cout << " planet with a desert and luckily it is inhabitable.";
   cout << " Once your vision returns you look\naround and see sand dunes as far as the eye can see.";
   cout << " You know that if you do not find\na way out of the desert you will not last long.";
   cout << " Thus, you begin your journey to find\nan escape from this harsh environment.\n";
   cout << endl << "'Press enter to continue...'" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Narration::DesertEscapeRoom() const
{
   cout << "After defeating the metal scorpion you go to drink from the pond. ";
   cout << "After drinking\nfrom the pond you notice that at the bottom ";
   cout << "it just becomes darker as if\nthe pond is much deeper than it seems. ";
   cout << "You dip your head in trying to get a closer look\nwhen suddenly ";
   cout << "the sand and water mix and you are blinded as you feel yourself\nbeing pulled";
   cout << " deeper into the water. Once your sight returns you notice yourself falling\ninto a large chasm.";
   cout << " The chasm below you looks to be a large body of water stretching out\nin all directions.";
   cout << " You take a deep breath and dive into the water and proceed to swim back\n";
   cout << "to the surface. You look around and notice there is water as far as your eyes can see but\n";
   cout << "off in the distance you notice some bright light.";
   cout << " With no where else to go, you start\nheading in the direction of the light.\n";
   cout << endl << "'Press enter to continue...'" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Narration::EnterFortress() const
{
   cout << "After defeating the \"Killer\" Whale you climb out of the water and up the steps towards the metal doors.\n"
        << "The heavy doors open and shakes the ground below you, it seems as if you were an expected guest.\n"
        << "Above the door is a large flag and on the flag the words \"JENTLEY FORTRESS\" is written in blood.\n"
        << "You proceed into the fortress and find yourself in an extravagant hall. Golden pillars hold up\n"
        << "the immense fortress, along the walls are many busts of what you can only assume is the ruler of\n"
        << "the fortress. From the ceiling hangs a large chandelier made from diamonds and on the floor is a\n"
        << "long red velvet carpet leading further inside. You follow the carpet through a set of doors but on\n"
        << "the other side the fortress was not so gaudy. Beyond the door was a dark dank hallway that split\n"
        << "into several other repugnant paths. Each one not looking any better than the rest. You know that\n"
        << "somewhere in this fortress is someone who may be able to help you off this planet, or help you into\n"
        << "an early grave. You gather your strength and proceed forward into what looks to be your most arduous\n"
        << "ordeal yet...\n";
   cout << endl << "'Press enter to continue...'" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Narration::Ending() const
{
    cout << "After defeating the robot it falls to the ground and explodes leaving a heap of scrap metal on the ground.\n"
         << "You look to the other side of the room where the ruler of the fortress stands. Finally, he turns around to\n"
         << "address you. \"So... you even defeated my friend, my only companion in this cold and unforgiving world.\"\n"
         << "The man slowly walks towards you and he is noticeably furious. \"What makes you think you can come to my\n"
         << "kingdom, MY PLANET, and waltz into my fortress? What are you trying to do, what is it you want to accomplish?\n"
         << "Do you want my riches? Do you want my status? Do you want to steal my research? Well, too bad, you can't have\n"
         << "any of it! I, BOE JENTLEY THE THIRD, WILL DESTROY YOU WHERE YOU STAND!\" Suddenly the man before you pulls\n"
         << "out from a compartment below him a mysterious orb. \"This here is one of my inventions, The Matter Destroyer,\n"
         << "it will wipe out your entire existence!\" Before you can even react, he fires a beam at you striking you.\n";
    cout << endl << "'Press enter to continue...'" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "A great beam of light blinds you, you believe all is lost. All the work you have gone through to get here, wasted.\n"
         << "But then you hear someone yelling, \"WHAT?! What is happening?! Why isn't it working!\" It was Jentley who was\n"
         << "stunned by the fact that you were not dematerialized. You look down at your body and notice a red glow all around\n"
         << "you. You notice that in your bag something was glowing intensely. You take a look and see that it was the Jewel\n"
         << "of Jentley. The great power of the jewel protected you from the Matter Destroyer. Quickly, you snatch the Matter\n"
         << "Destroyer from Jentleys' hands while he was still stunned by the fact that you are still alive. \"Wait, what are\n"
         << "you--\" Before he could finish his sentence, you aim the Matter Destroyer at Jentley and fire it at him. Within an\n"
         << "instant Jentley transforms into tiny particles and disappears into thin air, and with that ends his reign.\n";
    cout << endl << "'Press enter to continue...'" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "With the ruler of the fortress out of the way you begin to look around the room for documents on a spaceship or\n"
         << "anything that can get you off this planet. While searching you notice research papers about a crippling virus\n"
         << "you read through them and realise this virus is the same one that destroyed Earth and the Solar System 100 years ago.\n"
         << "You continue reading the document and learn that deep under this fortress is the facility that creates the virus.\n"
         << "Knowing the dangers the virus poses to the universe, you look for some way to stop it. The only thing that you could\n"
         << "find is that using the Matter Destroyer on the Jewel of Jentley would create a rift in the universe that would\n"
         << "quickly absorb the planet and everything on it, including the virus. With that, you continue to search for a way off\n"
         << "the planet. After a bit more searching you found a map that shows a secret door within this room that leads to a\n"
         << "rocket. You go to the other side of the room and look around for a way to open the door. While searching you feel\n"
         << "a tile on the ground depress. The wall before you retreats into the ground and before you stands the escape rocket.\n"
         << "You enter the rocket and familiarize yourself with the controls and prepare to escape.\n";
    cout << endl << "'Press enter to continue...'" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Knowing that this planet is a host of all sorts of evil, especially the deadly planet destroying virus, you take\n"
         << "the Jewel of Jentley and place it on the ground. You then proceed to place the Matter Destroyer down as well, aiming\n"
         << "it at the jewel. Without hesitation, you fire the Matter Destroyer at the jewel causing a great red glow to emanate\n"
         << "out of it. Knowing full well you do not want to be caught in the red glow, you rush into the rocket and initiate the\n"
         << "launch sequence. Within moments, the rocket takes off into space. As you look out the window you see that the glow has\n"
         << "engulfed the planet and that the planet was dematerializing from where you left the jewel outwards to the rest of the\n"
         << "planet. After a few more moments, the entire planet disappears and all that is left is a great dark void where it\n"
         << "used to be. With a sigh of relief, you set the rocket on a course back home knowing that you have stopped\n"
         << "the menace unleashing the world destroying virus. Thus ends your simple patrol through space.\n\n"
         << "\t\tBe proud Galactic Trooper " <<  CharName << " for you are victorious!\n";
}

PlayerCharacter::PlayerCharacter(int hp, int damage, int speed, string race)
: Character(hp, damage), speed(speed), max_hp(hp), race(race)
{
   inventory.push_back(BAREHANDED);
   inventory.push_back(PAJAMAS);
   inventory.push_back(NOTHING);
}

//A function to determine how much damage the player takes
bool PlayerCharacter::takeDamage(int damage)
{
   int rand_num = rand() % 100 + 1;
   //cout << "the rand num is " << rand_num << endl;
   if (speed > rand_num)
   {
      cout << "Luckily, you take no damage!" << endl;
      return false;
   }
   hp -= ((damage-inventory[ARMOR].getValue())>0 ? (damage-inventory[ARMOR].getValue()) : 0);
   if (hp <= 0)
   {
      hp = 0;
   }
   return true;
}

//A function to determine how much damage the player deals out
int PlayerCharacter::attack() const
{
   int rand_num = rand() % 100 + 1;
   //cout << "the rand num is " << rand_num << endl;
   //If statement to determine if the player misses or not
   if (speed < rand_num)
   {
      //cout << "You missed the enemy!" << endl;
      return 0;
   }
   return damage + inventory[0].value;
}

void PlayerCharacter::evolve()
{
   max_hp += inventory[SPOILS].getHp();
   hp = max_hp;
   damage += inventory[SPOILS].getDmg();
   speed += inventory[SPOILS].getSpeed();
}

PlayerCharacter& PlayerCharacter::operator=(PlayerCharacter& other)
{
   (*this).race = other.race;
   (*this).hp = other.hp;
   (*this).damage = other.damage;
   (*this).speed = other.speed;
   return (*this);
}

//A function for when the enemy takes damage and to determine when it dies
bool Enemy::takeDamage(int damage)
{
   hp -= damage;
   if (hp <= 0)
   {
      hp = 0;
   }
   return true;
}

SpaceZombie::SpaceZombie() : Enemy(20, 10, "You hear a faint growl nearby, as you turn your head you see before you\na grotesque figure with flesh falling off its face.\nBoth your eyes meet and it starts to limp towards you.\n")
{
   inventory.push_back(WRENCH);
   inventory.push_back(LASER_GUN);
   inventory.push_back(ELITE_PATROL_ARMOR);
}

Alien::Alien() : Enemy(75, 20, "A vent creaks behind you, and when you swing around, a misshapen,\nmutated figure prepares to bound toward you! It may have once been human...?\n")
{
   inventory.push_back(MEMENTO_OF_THE_CAPTAIN);
}

Nomad::Nomad() : Enemy(80, 45, "A Nomad slinks towards you, swathed in dark cloth.\nNomads live in packs and will eat anything to survive.\nHint: You're not an exception.\n")
{
   inventory.push_back(SCIMITAR);
   inventory.push_back(DESERT_RANGER_ARMOR);
   inventory.push_back(HAND_CANNON);
}

MetalScorpion::MetalScorpion() : Enemy(150, 50, "The sand ripples and the ground shakes as you see a Metal Scorpion approach from over the horizon.\n")
{
   inventory.push_back(EYES_OF_ANUBIS);
}

Siren::Siren() : Enemy(180, 70, "You hear a sweet lullaby and follow a sleek form through the mist.\nSuddenly, a reptilian face surfaces from the depths!\nSirens are cunning and strong, but have little health. \n")
{
   inventory.push_back(SONAR_BLASTER);
   inventory.push_back(TRIDENT);
   inventory.push_back(AQUA_SHROUD);
}

KillerWhale::KillerWhale() : Enemy(300, 100, "Out of the water comes a strange creature, something like a whale but with arms\nand legs like a man. Its eyes are fixated on you, its teeth covered in blood.\nYou know the only way into the fortress is by defeating this creature...\n")
{
   inventory.push_back(CROWN_OF_POSEIDON);
}

Goons::Goons() : Enemy(330, 150, "Prepare for trouble!\nThese two Goons don't question their leader's orders.\nThey only have one skill: Bowing gently to Big Boss Jentley. \n")
{
   inventory.push_back(PHOTON_BLADE);
   inventory.push_back(POWER_ARMOR);
   inventory.push_back(HELIOS_FLAMETHROWER);
}

Boss::Boss() : Enemy(800, 200, "At the top of the staircase you see a man mixing some sort of substance. Without turning around the man\naddresses you, \"I see you've made it this far. I can't allow you to disturb my research. I'll just have\nmy robotic friend play with you, haha... haha... HA!\"\nFrom the dark corner of the room emerges a colossal robot. You ready your weapons...\n")
{
   inventory.push_back(JEWEL_OF_JENTLEY);
}

