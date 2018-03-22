#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <limits>
using namespace std;

enum itemType { WEAPON, ARMOR, SPOILS };

class Thing
{
public:
   Thing() {}
   virtual ~Thing() {}
   virtual string name() const = 0;
};

struct Item : public Thing
{
   string ItemName;
   int value, hp, dmg, speed;
   itemType type;
   int count;
   string description;
   Item() {}
   Item(string n, int val, itemType t, string d) : ItemName(n), value(val), type(t), description(d) {}
   Item(string n, int hp, int dmg, int speed, itemType t, string d) : ItemName(n), hp(hp), dmg(dmg), speed(speed), type(t), description(d) {}
   string name() const {return ItemName; }
   int getValue() const {return value;}
   int getHp() const {return hp;}
   int getDmg() const {return dmg;}
   int getSpeed() const {return speed;}
   string getDescription() const {return description;}
};

const Item BAREHANDED("Fists (+0 dmg)", 0, WEAPON, "Its time to engage in some fisticups.");
const Item PAJAMAS("Pajamas (+0 def)", 0, ARMOR, "Pajamas you wore to sleep.");
const Item NOTHING("Nothing", 0, 0, 0, SPOILS, "You haven't yet beaten any boss for any spoils.");

/*Spaceship Items*/
const Item WRENCH("Wrench (+3 dmg)", 3, WEAPON, "A wrench from the engineering department. Hey, Better than nothing!");
const Item LASER_GUN("Laser Gun (+7 dmg)", 7, WEAPON, "The official firearm of the space federation.\n\t\t  Not the most powerful gun...");
const Item ELITE_PATROL_ARMOR("Elite Patrol Armor (+4 def)", 4, ARMOR, "The official gear of the Elite soldiers of the space federation.");
const Item LIGHT_SABER("Lightsaber (+20 dmg)", 20, WEAPON, "The secret weapon of the space federation, stolen from a galaxy far far away...");

/*Desert items*/
const Item SCIMITAR("Scimitar (+8 dmg)", 8, WEAPON, "A trusty scimitar taken from a Nomad.");
const Item HAND_CANNON("Hand Cannon (+15 dmg)", 15, WEAPON, "The hand cannon ripped off a metal scorpion's tail. Some might say it's a tail cannon...");
const Item DESERT_RANGER_ARMOR("Desert Ranger Armor (+15 def)", 15, ARMOR, "A piece of armor that not only protects you from attacks but also protects you from the hot sun.");
const Item MILLENNIUM_PUZZLE("Millennium Puzzle (+35 dmg)", 35, WEAPON, "A puzzle once owned by a spiky haired boy who loved card games. Grants you the power of mind crush.");

/*Water items*/
const Item TRIDENT("Trident (+16 dmg)", 16, WEAPON, "a trident based off of Poseidon's cherished weapon.");
const Item SONAR_BLASTER("Sonar Blaster (+30 dmg)", 30, WEAPON, "the weapon of the Royal Sirens of the Sea.");
const Item AQUA_SHROUD("Aqua Shroud (+50 def)", 50, ARMOR, "an aqua blue shroud that allows you to more easily swim through the water as well as protect you from attacks.");
const Item MERMAIDMANS_BELT("Mermaid Man's Belt (+60 dmg)", 60, WEAPON, "Mermaid Man and Barnacle Boy UNITE! The belt grants you the power of WUMBO.");

/*Fortress items*/
const Item PHOTON_BLADE("Photon Blade (+31 dmg)", 31, WEAPON, "A photon blade created by the Jentley army, the glow of the blade strikes fear into all who oppose them.");
const Item HELIOS_FLAMETHROWER("Helios' Flamethrower (+50 dmg)", 50, WEAPON, "the most powerful weapon of the Jentley army.");
const Item POWER_ARMOR("Power Armor (+100 def)", 100, ARMOR, "a feat of engineering, this armor is capable of protected you from the most powerful attacks.");
const Item REAPER_OF_SOULS("Reaper of Souls (+120 dmg)", 120, WEAPON, "The ancient artifact from the Jentley family stash. ");

/*Boss Spoils*/
const Item MEMENTO_OF_THE_CAPTAIN("Memento of the Captain", 75, 25, 5, SPOILS, "The memento of the captain. You hold it to your chest and you feel power welling up inside of you.");
const Item EYES_OF_ANUBIS("Eye of Anubis", 125, 25, 5, SPOILS, "the ancient artifacts said to be the eyes belonging to Anubis, the Egyptian god of death.\nGripping it in your hand, you feel great power flowing through you.");
const Item CROWN_OF_POSEIDON("Crown of Poseidon", 150, 25, 5, SPOILS, "the crown belonging to the god of the seas. You place it upon your head and power surges through you.");
const Item JEWEL_OF_JENTLEY("Jewel of Jentley", 1000, 1000, 1000, SPOILS, "Great power emanates from this almighty jewel belonging to the Jentley Dynasty. With it nothing can stop you.");

/*God/Special items*/
const Item GOD_HAND("God's Hand", 10001, WEAPON, "the hand of god smites all who oppose its user.");

class Narration : public Thing
{
private:
   string CharName;
public:
   Narration(string n) : CharName(n) {}
   string name() const {return CharName;}
   void intro() const;
   void EnterSpaceship() const;
   void SpaceEscapeRoom() const;
   void EnterDesert() const;
   void DesertEscapeRoom() const;
   void EnterFortress() const;
   void Ending() const;
};

class Character : public Thing
{
protected:
   int hp;
   int damage;
   vector<Item> inventory;
   Character(int h, int d) : Thing(), hp(h), damage(d) {}
   virtual ~Character() {}
   virtual bool takeDamage(int damage) = 0;
   virtual string name() const = 0;
   virtual int attack() const = 0;
public:
   int getHp() const {return hp;}
   int getDamage() const {return damage;}
   void setDamage(int inDamage) {damage = inDamage;}
   vector<Item> getInventory() const {return inventory;}
   void setInventory(vector<Item> inBag) {inventory = inBag;}
};

class PlayerCharacter : public Character
{
protected:
   int speed;
   int max_hp;
   string race;
public:
   PlayerCharacter() = default; // C++11 force compiler to create a default constructor for us even if we write a non-default one
   PlayerCharacter(int, int, int, string);
   ~PlayerCharacter() {}
   void getInfo() const { cout << race << endl; }
   void receiveItem(Item item) {inventory[item.type] = item;}
   void evolve();
   void restore_hp() { hp = max_hp; }
   void setSpeed(int inSpeed) { speed = inSpeed; }
   int getSpeed() const { return speed; }
   int getMax_hp() const { return max_hp; }
   string name() const override { return race; }
   int attack() const override; //C++11 Keyword override, to avoid inadvertently create new function in derived class
   bool takeDamage(int) override;
   PlayerCharacter& operator=(PlayerCharacter&);
};

class Enemy : public Character
{
protected:
   string info;
public:
   Enemy(int hp, int damage, string i)
   : Character(hp, damage), info(i) {}
   virtual ~Enemy() {}
   bool takeDamage(int);
   int attack() const { return damage; }
   void dropItems();
   virtual string name() const = 0;
   string getInfo() { return info; }
   bool isDead() const { return hp <= 0 ? true : false; }
};

class SpaceZombie : public Enemy
{
public:
   SpaceZombie();
   ~SpaceZombie() {};
   string name() const { return "Space Zombie"; }
};

class Alien : public Enemy
{
public:
   Alien();
   ~Alien() {};
   string name() const { return "Abhorrent Alien!"; }
};

class Nomad : public Enemy
{
public:
   Nomad();
   ~Nomad() {};
   string name() const { return "Nomad"; }
};

class MetalScorpion : public Enemy
{
public:
   MetalScorpion();
   ~MetalScorpion() {};
   string name() const { return "Menacing Metal Scorpion!"; }
};

class KillerWhale : public Enemy
{
public:
   KillerWhale();
   ~KillerWhale() {};
   string name() const { return "Knackish \"Killer\" Whale!"; }
};

class Siren : public Enemy
{
public:
   Siren();
   ~Siren() {};
   string name() const { return "Siren"; }
};

class Goons : public Enemy
{
public:
   Goons();
   ~Goons() {};
   string name() const { return "Goons"; }
};

class Boss : public Enemy
{
public:
   Boss();
   ~Boss() {};
   string name() const { return "Baleful Bot, B03 J3NT-1Y!!"; }
};

#endif // CHARACTER_H
