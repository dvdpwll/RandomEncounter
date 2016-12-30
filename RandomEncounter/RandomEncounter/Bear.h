#ifndef BEAR_H
#define BEAR_H
#include <string>

#include "Unit.h"
class Bear : public Unit {
private:

public:
	Bear() {
		setName("Bear");
		setHealth(60);
		setMana(10);
	}
	~Bear();

	//setters
	void setName(string);
	void setHealth(int);
	void setMana(int);
	int attack();
};
#endif