#ifndef GOBLIN_H
#define GOBLIN_H
#include <string>

#include "Unit.h"
class Goblin : public Unit {
private:

public:
	Goblin() {
		setName("Goblin");
		setHealth(20);
		setMana(10);
	}
	~Goblin();

	//setters
	void setName(string);
	void setHealth(int);
	void setMana(int);
	int attack();
};
#endif