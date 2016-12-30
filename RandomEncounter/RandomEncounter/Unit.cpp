#include <iostream>
using namespace std;
#include "Unit.h"

//Character functions
Unit::~Unit() {
}
void Unit::setName(string n) {
	name = n;
}
void Unit::setHealth(int r) {
		health = r;
}
void Unit::setMana(int r) {
		mana = r;
}
int Unit::attack() {
	int dmg = 10;
	cout << getName() << " attacks!";
	return dmg;
}