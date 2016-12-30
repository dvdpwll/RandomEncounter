Locations of requirements:

Header files 
	-RancomEncounter.cpp (Lines: 38-50)
	-begining of all the classes and their cpp files
Classes and Subclasses
	-Unit, Character, Goblin, BigGoblin, Shaman, Bear
Multiple constructors
	-Character.h (Lines: 17-33)
Destructor
	-Character.h (Line: 34)
	-also in each of the enemy classes
Abstract Base Class
	-Unit.h
Inheritance/Polymorphos
	-Character, Goblin, Bear inherit from Unit.h
	-BigGoblin, Shaman inherit from Goblin.h
Pointers
	-RandomEncounter.cpp (Line: 54-56; 77; 111; 116; 152; 181-344)
	-The functions battle, saveFile, and loadFile use pointers
Static Variables and Functions
	-static variable in RandomEncounter (Line: 186)
	-functions are in all .cpp files
Exceptions
	-Character.cpp int he overloaded cin (Line: 88-117)
Templates
	-did not do
Binary files
	-RandomEncounter.cpp in saveFile and loadFile (Line: 289-344)
Recursion
	-did not do
Virtual Function or class
	-Unit.h (Line: 33)
Linked Lists
	-did not do
Binary search trees
	-did not do
Overloaded Operators
	-Character.cpp overloaded cin operator (Line: 76-128)
Friend function
	-did not do