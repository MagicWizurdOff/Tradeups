#ifndef GUN_H
#define GUN_H
#include <iostream>
class Gun
{
public:
	Gun();
	~Gun();
	static std::string printGun();
	static std::string gunName;
private:

};

Gun::Gun()
{
}

Gun::~Gun()
{
}

#endif // !GUN_H
