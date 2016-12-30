#include <iostream>
using namespace std;
#include "BigGoblin.h"

//Character functions
BigGoblin::~BigGoblin() {
	//cout << getName() << " dies." << endl;
}
void BigGoblin::setName(string n) {
	name = n;
}
void BigGoblin::setHealth(int r) {
	health = 50;
}
void BigGoblin::setMana(int r) {
	mana = 10;
}
int BigGoblin::attack() {
	int dmg = 20;
	cout << getName() << " attacks!";
	return dmg;
}