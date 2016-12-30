#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <string>
using namespace std;

class Unit {
protected:
	string name;
	int health;	//health points, life, vitality (determined by type)
	int mana;	//magic, stamina, ether (determined by race)
public:

public:
	Unit() {
		setName("Unit");
		setHealth(10);
		setMana(10);
	}
	~Unit();

	//setters
	void setName(string);
	void setHealth(int);
	void setMana(int);

	//getters
	string getName() const { return name; }
	int getHealth() const { return health; }
	int getMana() const { return mana; }

	//other
	virtual int attack() = 0;
};

#endif