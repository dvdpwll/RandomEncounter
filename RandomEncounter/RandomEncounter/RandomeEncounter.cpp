/*
David Powell
4/18/16

Program: RandomEncounter
-similar to a video game rpg, you will move around and encounter and enemy by random chance. You
Will then battle it. If you win you will be able to continue walking, if you lose you will get a game over.
*/

/*
instructions:
Your final project should demonstrate:
•	Header files (done)
•	Classes and subclasses (done)
o	Multiple constructors (done)
o	Destructor (done)
o	Abstract Base class (done)
•	Inheritance / Polymorphism (done)
•	Pointers (done)
•	Static variables & functions (done)
•	Exceptions (done)
•	Templates
•	Binary File I/O with random access (sorta done)
Extra points for:
•	Recursion
•	Virtual function or class (done)
•	Linked lists / Stacks / Queues
•	Binary search trees
•	Overloaded operators (done)
•	A “friend” function
Don’t forget: pseudocode & comments!!!
You will turn in: all working code and any associated files.
Due date: 5/9/2016

*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>  
#include <fstream>
#include <iostream>
#include "Character.h"
#include "Unit.h"
#include "Goblin.h"
#include "BigGoblin.h"
#include "Shaman.h"
#include "Bear.h"
using namespace std;

//functin prototypes
bool encounterCheck();
void battle(Character &ch);
void saveFile(Character &ch);
void loadFile(Character &ch);

int main() {
	string name;
	int gender;	//1-male, 2-female
	int race;	//1-Human, 2-Elf, 3-Dwarf
	char cont;	//load from save?


	//make a character object
	Character c;

	//ask user if load from save
	cout << "\nDo you want to load from a previous save (y/n)?" << endl;
	do {
		cin >> cont;
	} while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

	//get info for character
	if (cont == 'y' || cont == 'Y') {
		//continue from save state
		loadFile(c);
	}
	else {
		//new character
		cin >> c;
	}

	//show stats
	c.printStats();

	bool tryEncounter;	//try looking for monster?
	bool encounter = false;	//monster encountered?
	string step;	//input from user
	int cSteps = 0;	//count steps taken
	do {
		do {
			//get input
			cout << "Do you want to take a step? ";
			cin >> step;

			//yes
			if (step == "y" || step == "Y" || step == "yes" || step == "Yes") {
				cout << "You took a step." << endl;
				cSteps++;
				tryEncounter = true;
			}
			//no
			else if (step == "n" || step == "N" || step == "no" || step == "No" || step == "stop" || step == "Stop!") {
				cout << "You take a step anyways." << endl;
				cSteps++;
				tryEncounter = true;
			}
			//save
			else if (step == "save" || step == "Save" || step == "SAVE" || step == "s") {
				saveFile(c);
				tryEncounter = false;
			}
			//load
			else if (step == "load" || step == "Load" || step == "LOAD" || step == "l") {
				loadFile(c);
				tryEncounter = false;
				c.printStats();
			}
			//stats
			else if (step == "stats" || step == "Stats") {
				c.printStats(); 
				tryEncounter = false;
			}
			//help
			else if (step == "?" || step == "help" || step == "???") {
				cout << "\nSome commands:" << endl;
				cout << "y" << endl;
				cout << "n" << endl;
				cout << "save" << endl;
				cout << "load" << endl;
				cout << "stats" << endl;
				tryEncounter = false;
			}
			//everything else
			else {
				cout << "Your character is confused... you take a step." << endl;
				cSteps++;
				tryEncounter = true;
			}

			//check for encounter
			if (tryEncounter == true) {
				cout << "encounter check" << endl;
				encounter = encounterCheck();
			}
		} while (!encounter);	//end while loop, check for encounter

		//enter battle mode
		cout << "A monster attacks you!" << endl;
		encounter = false;
		battle(c);

	} while (c.getHealth() > 0);	//end while loop, check for health

	system("pause");
	return 0;
}

//functions for main
//checks for monster
bool encounterCheck() {
	//seed the srand
	srand(time(NULL));

	//get a number between 0 - 2 (33% encounter rate)
	int r = rand() % 3;

	//cout << "r = " << r << endl;

	//you encounter a monster if 0
	if (r == 0) {
		return true;
	}
	else {
		return false;
	}
}

//if encounter check is true fight a monster
void battle(Character &ch) {
	cout << "\n\n~~~Battle music~~~\n" << endl;
	int dmg;
	int eHealth;
	int eMana;
	static int monstersKilled = 0;

	int choice = 0;	//for menu choices
	int cHealth = ch.getHealth();
	int cMana = ch.getMana();
	//cout << cHealth << endl << cMana << endl << eHealth << endl;
	

	//make a monster
	//seed the srand to choose which monster to fight
	srand(time(NULL));

	//get a number between 0 - 3
	int r = rand() % 4;

	//choose monster
	if (r == 0){
		cout << "A wild goblin appears!" << endl;
		Goblin g;
		eHealth = g.getHealth();
		eMana = g.getMana();
		dmg = g.attack();
	}
	else if (r == 1){
		cout << "A big goblin appears!" << endl;
		BigGoblin g;
		eHealth = g.getHealth();
		eMana = g.getMana();
		dmg = g.attack();
	}
	else if (r == 2){
		cout << "A goblin shaman appears!" << endl;
		Shaman g;
		eHealth = g.getHealth();
		eMana = g.getMana();
		dmg = g.attack();
	}
	else if (r == 3){
		cout << "A wild bear appears!" << endl;
		Bear g;
		eHealth = g.getHealth();
		eMana = g.getMana();
		dmg = g.attack();
	}


	

	//keep fighting monster
	do {
		//get attack option
		do {
			ch.attackOptions();
			
			//get the choice
			if (cin >> choice) {
			}
			else {
				// So first clear the state.
				cin.clear();

				//this gets rid of the bad input (letters) and resets the stream
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Please enter 1, or 2: ";
			}
		} while (choice < 1 || choice > 2);	//endl loop for choice and check for valid options (1 or 2)

		//calculate dmg
		int cDamage = ch.attackSelection(choice);
		eHealth = eHealth - cDamage;
		cHealth = ch.getHealth();
		cMana = ch.getMana();		

		//monster dmg
		if (eHealth > 0){
			cout << "The enemy hits you for " << dmg << "." << endl;
			cHealth = cHealth - dmg;
			cout << "Your current health is: " << cHealth << endl;
			cout << "Your current mana is: " << ch.getMana() << endl;
			ch.setBattleHP(cHealth);
		}
	} while (eHealth > 0 && cHealth > 0);	//end loop if someone dies
	
	

	//display victory/death screen
	if (cHealth <= 0 && eHealth <= 0) {
		cout << "\nYou both died. Game Over." << endl;
	}
	else if (eHealth <= 0) {
		monstersKilled++;
		cout << "\nYou win!" << endl;
		cout << "you've killed " << monstersKilled << " monsters." << endl;
	}
	else if (cHealth <= 0) {
		cout << "\nYou died. Game Over." << endl;
	}

	//adjust character stats from battle
	ch.setBattleHP(cHealth);
	ch.setBattleMP(cMana);
}

//saving game
void saveFile(Character &ch) {
	//get info for save
	int h, m, g, r;
	h = ch.getHealth();
	m = ch.getMana();
	g = ch.getGender();
	r = ch.getRace();

	//open files
	fstream bFile("saves.dat", ios::binary | ios::out);
	ofstream tFile("saves.txt");
	if (bFile) {
		tFile << ch.getName() << endl;
		bFile.write(reinterpret_cast<char *> (&h), sizeof(h));
		bFile.write(reinterpret_cast<char *> (&m), sizeof(m));
		bFile.write(reinterpret_cast<char *> (&g), sizeof(g));
		bFile.write(reinterpret_cast<char *> (&r), sizeof(r));

		//close files
		bFile.close();
		tFile.close();
		cout << "\nCharacter Saved." << endl;
	}
	else { 
		cout << "\nUnable to save data." << endl; 
	}
}

//loading game
void loadFile(Character &ch) {
	//variable for input
	string n;
	int h, m, g, r;

	//open files
	fstream iBFile("saves.dat", ios::binary | ios::in);
	ifstream tFile("saves.txt");
	tFile >> n;
	iBFile.read(reinterpret_cast<char *> (&h), sizeof(h));
	iBFile.read(reinterpret_cast<char *> (&m), sizeof(m));
	iBFile.read(reinterpret_cast<char *> (&g), sizeof(g));
	iBFile.read(reinterpret_cast<char *> (&r), sizeof(r));
	
	//close files
	iBFile.close();
	tFile.close();

	//set the saved info to character
	ch.setName(n);
	ch.setGender(g);
	ch.setRace(r);
	ch.setBattleHP(h);
	ch.setBattleMP(m);
	cout << "\nCharacter Loaded." << endl;
}