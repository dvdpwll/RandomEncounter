#ifndef SHAMAN_H
#define SHAMAN_H
#include <string>

#include "Goblin.h"
class Shaman : public Goblin {
private:

public:
	Shaman() {
		setName("Shaman");
		setHealth(30);
		setMana(30);
	}
	~Shaman();

	//setters
	void setName(string);
	void setHealth(int);
	void setMana(int);
	int attack();
};
#endif