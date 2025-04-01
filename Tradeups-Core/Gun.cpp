#include "Gun.h"
#include <iostream>

std::string gunName = "AUG";

Gun::Gun() {

}
Gun::~Gun() {

}
std::string Gun::printGun() {
	return gunName;
}
