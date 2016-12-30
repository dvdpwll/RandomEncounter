#include <iostream>
using namespace std;
#include "Bear.h"

//Character functions
Bear::~Bear(){}

void Bear::setName(string n) {
	name = n;
}
void Bear::setHealth(int r) {
	health = 60;
}
void Bear::setMana(int r) {
	mana = 10;
}
int Bear::attack() {
	int dmg = 20;
	cout << getName() << " attacks!";
	return dmg;
}