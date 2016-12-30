#include <iostream>
using namespace std;
#include "Character.h"

//Character functions
Character::~Character() {
	cout << "You Died. Game Over." << endl;
}
void Character::setName(string n) {
	name = n;
}
void Character::setGender(int g) {
	//1 = male; 2 = female
	if (g == 2) {
		gender = 2;
	}
	else {
		gender = 1;
	}
}
void Character::setRace(int r) {
	//1 = human; 2 = elf; 3 = dwarf
	race = r;
}
void Character::setHealth(int r) {
	switch (r) {
	case 1:	//human
		health = 100;
		break;
	case 2:	//elf
		health = 70;
		break;
	case 3:	//dwarf
		health = 150;
		break;
	default://other
		health = 100;
	}
}
void Character::setMana(int r) {
	switch (r) {
	case 1:	//human
		mana = 100;
		break;
	case 2:	//elf
		mana = 150;
		break;
	case 3:	//dwarf
		mana = 60;
		break;
	default://other
		mana = 100;
	}
}
//set new health from battle
void Character::setBattleHP(int h) {
	health = h;
}
//set new mana from battle
void Character::setBattleMP(int m) {
	mana = m;
}
//display gender
void printGenderOptions() {
	cout << "1) Male" << endl;
	cout << "2) Female" << endl;
	cout << "Please choose a gender: ";
}
//display race
void printRaceOptions() {
	cout << "1) Human" << endl;
	cout << "2) Elf" << endl;
	cout << "3) Dwarf" << endl;
	cout << "Please choose a Race: ";
}
//overloaded cin
istream & operator >> (istream &strm, Character &obj) {
	string n;	//name
	int g;		//gender
	int r;		//race

	//get the name
	cout << "\nCreating character..." << endl;
	cout << "\nPlease enter a name for your character: ";
	strm >> n;

	//get the gender
	try{
		do {
			printGenderOptions();	//print gender options
			while (!(strm >> g)) {	//reject characters
				strm.clear();	//clear strm
				strm.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter 1 or 2: ";
			}
		} while (g < 1 || g > 2);	//endl loop for g and check for valid gender
	}
	catch (const std::exception&){
		g = 1;
	}

	//get the race
	try
	{
		do {
			printRaceOptions();	//print race options
			while (!(strm >> r)) {	//reject characters
				strm.clear();	//clear strm
				strm.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter 1, 2, or 3: ";
			}
		} while (g < 1 || g > 3);	//endl loop for r and check for valid race
	}
	catch (const std::exception&)
	{
		r = 1;
	}

	//set the name, gender, race
	obj.setName(n);
	obj.setGender(g);
	obj.setRace(r);
	obj.setHealth(r);
	obj.setMana(r);

	return strm;

}	//end overloaded cin function
//show character stats
void Character::printStats() {
	string n = getName();
	int g = getGender();
	int r = getRace();
	string strG = convertGender(g);
	string strR = convertRace(r);
	
	cout << "----------------------------" << endl;
	cout << "Character Stats: " << endl;
	cout << "Name: " << n << endl;
	cout << "Gender: " << strG << endl;
	cout << "Race: " << strR << endl;
	cout << "Health: " << getHealth() << endl;
	cout << "Mana: " << getMana() << endl;
	cout << "----------------------------" << endl;
}

string Character::convertGender(int g) {
	string strG;
	switch (g) {
	case 1:	//Male
		strG = "Male";
		break;
	case 2:	//Female
		strG = "Female";
		break;
	default://other
		strG = "Other";
	}

	return strG;
}
string Character::convertRace(int r) {
	string strR;
	switch (r) {
	case 1:	//human
		strR = "Human";
		break;
	case 2:	//elf
		strR = "Elf";
		break;
	case 3:	//dwarf
		strR = "Dwarf";
		break;
	default://other
		strR = "Other";
	}

	return strR;
}
//show attack options by race
void Character::attackOptions() {
	if (race == 1) {
		cout << "\n1) Swing sword \n2) Lightning (20 mp)\n" << endl;
	}
	else if (race == 2) {
		cout << "\n1) Shoot arrow \n2) Heal (25 mp)\n" << endl;
	}
	else if (race == 3) {
		cout << "\n1) Swing axe \n2) Throw fireboob (10 mp)\n" << endl;
	}
}
//calculate dmg from attack option
int Character::attackSelection(int a) {
	int dmg = 0;
	switch (race) {
	case 1:	//human
			//calculate dmg
		if (a == 1) {
			cout << "You swing your sword. (10 dmg) " << endl;
			dmg = 10;
			return dmg;
		}
		else if (a == 2) {
			if (mana >= 20) {
				cout << "You cast lightning. (30 dmg, -20 mp) " << endl;
				dmg = 30;
				mana = mana - 20;
				return dmg;
			}
			else {
				cout << "You tried casting lightning, but it fizzled." << endl;
				dmg = 0;
				return dmg;
			}
		}
		else {
			cout << "error" << endl;
			dmg = 0;
			return dmg;
		}
		break;
	case 2:	//elf
			//calculate dmg
		if (a == 1) {
			cout << "You shoot your arrow. (10 dmg) " << endl;
			dmg = 10;
			return dmg;
		}
		else if (a == 2) {
			if (mana >= 20) {
				cout << "You cast heal. (50 hp, -25 mp) " << endl;
				dmg = 0;
				mana = mana - 25;
				health = health + 50;
				return dmg;
			}
			else {
				cout << "You tried casting heal, but it failed." << endl;
				dmg = 0;
				return dmg;
			}
		}
		else {
			cout << "error" << endl;
			dmg = 0;
			return dmg;
		}
		break;
	case 3:	//dwarf
			//calculate dmg
		if (a == 1) {
			cout << "You swing your axe. (10 dmg) " << endl;
			dmg = 10;
			return dmg;
		}
		else if (a == 2) {
			if (mana >= 20) {
				cout << "You throw a firebomb. (20 dmg, -10 mp) " << endl;
				dmg = 20;
				mana = mana - 10;
				return dmg;
			}
			else {
				cout << "You have no more firebombs." << endl;
				dmg = 0;
				return dmg;
			}
		}
		else {
			cout << "error" << endl;
			dmg = 0;
			return dmg;
		}
		break;
	default://other
		return dmg;
	}
}

int Character::attack() {
	int dmg = 10;
	cout << getName() << " attacks!";
	return dmg;
}