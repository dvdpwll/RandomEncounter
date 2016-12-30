#include <iostream>
using namespace std;
#include "Goblin.h"

//Character functions
Goblin::~Goblin() {
	//cout << getName() << " dies." << endl;
}
void Goblin::setName(string n) {
	name = n;
}
void Goblin::setHealth(int r) {
	health = 20;
}
void Goblin::setMana(int r) {
	mana = 10;
}
int Goblin::attack() {
	int dmg = 10;
	cout << getName() << " attacks!";
	return dmg;
}