#ifndef BIGGOBLIN_H
#define BIGGOBLIN_H
#include <string>

#include "Goblin.h"
class BigGoblin : public Goblin {
private:

public:
	BigGoblin() {
		setName("Big Goblin");
		setHealth(50);
		setMana(10);
	}
	~BigGoblin();

	//setters
	void setName(string);
	void setHealth(int);
	void setMana(int);
	int attack();
};
#endif