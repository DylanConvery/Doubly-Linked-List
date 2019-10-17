#ifndef GOD_H
#define GOD_H

#include <string>

struct God{
	//constructors
	God(const std::string& name, const std::string& mythology, const std::string& vehicle, const std::string& weapon) : _name{ name }, _mythology{ mythology }, _vehicle{ vehicle }, _weapon{ weapon }{};

	//operators
	bool operator == (const God& god);
	friend std::ostream& operator << (std::ostream& os, const God& god);

	//member variables
	std::string _name;
	std::string _mythology;
	std::string _vehicle;
	std::string _weapon;
};

#endif //!GOD_H