#include "God.h"

//checks whether this God object and another are equal in their attributes
bool God::operator == (const God& god){
	if(_name != god._name){
		return false;
	} else if(_mythology != god._mythology){
		return false;
	} else if(_vehicle != god._vehicle){
		return false;
	} else if(_weapon != god._weapon){
		return false;
	} else{
		return true;
	}
}

//prints out a God objects attributes
std::ostream& operator << (std::ostream& os, const God& god){
	return os << "{\n"
		<< "    " << god._name << ",\n"
		<< "    " << god._mythology << ",\n"
		<< "    " << god._vehicle << ",\n"
		<< "    " << god._weapon << ",\n"
		<< "}";
}