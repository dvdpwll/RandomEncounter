#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include "Unit.h"
using namespace std;

class Character : public Unit {
protected:
	string name;
	int health;	//health points, life, vitality (determined by race)
	int mana;	//magic, stamina, ether (determined by race)
	int gender;	//1-male, 2-female
	int race;	//1-Human, 2-Elf, 3-Dwarf

public:
	Character() {
		//cout << "Making default character... " << endl;
		setName("Hero");
		setHealth(1);
		setMana(1);
		setGender(1);
		setRace(1);
	}

	Character(string n, int g, int r) {
		//cout << "Creating character... " << endl;
		setName(n);
		setHealth(r);
		setMana(r);
		setGender(g);
		setRace(r);
	}
	~Character();

	//setters
	void setName(string);
	void setGender(int);
	void setRace(int);
	void setHealth(int);
	void setMana(int);
	void setBattleHP(int);
	void setBattleMP(int);

	//getters
	string getName() const { return name; }
	int getGender() const { return gender; }
	int getRace() const { return race; }
	int getHealth() const { return health; }
	int getMana() const { return mana; }

	//other
	friend istream &operator >> (istream &, Character &);	//overload cin
	void printStats();	//prints current stats of the character
	string convertGender(int);
	string convertRace(int);
	void attackOptions();	//show attack options
	int attackSelection(int);	//calculate dmg from attack option
	int attack();
};

#endif