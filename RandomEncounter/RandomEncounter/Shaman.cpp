#include <iostream>
#include <time.h>  
using namespace std;
#include "Shaman.h"

//Character functions
Shaman::~Shaman() {
}
void Shaman::setName(string n) {
	name = n;
}
void Shaman::setHealth(int r) {
	health = 30;
}
void Shaman::setMana(int r) {
	mana = 30;
}
int Shaman::attack() {
	//seed the srand
	srand(time(NULL));

	//shaman has two attacks
	//get a number between 0 - 1 (50%)
	int r = rand() % 2;
	int dmg = 0;
	if (r == 0) {
		dmg = 10;
		cout << getName() << " hits you!";
	}
	else if (r == 1) {
		dmg = 20;
		cout << getName() << " attacks with a spell!";
	}

	return dmg;
}