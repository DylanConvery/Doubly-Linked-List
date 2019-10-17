#ifndef LINK_H
#define LINK_H

#include <string>
#include "God.h"

class Link{
public:
	//constructs link object, by default setting both previous and successor to a nullptr if no argument is provided
	//for their parameters
	Link(const God& god, Link* previous = nullptr, Link* successor = nullptr) : _god{ god }, _previous{ previous }, _successor{ successor }{}

	//member functions
	Link* Insert(Link* new_link);
	Link* Add(Link* new_link);
	Link* Remove();
	Link* Find(const std::string& god);
	const Link* Find(const std::string& god) const;
	Link* advance(int jumps) const;

	//setters
	void setGod(const God& god){ _god = god; }

	//getters
	Link* getPreviousLink() const{ return _previous; }
	Link* getSuccessorLink() const{ return _successor; }
	God getGod() const{ return _god; }

private:
	//member variables
	God _god;
	Link* _previous;
	Link* _successor;
};

#endif // !LINK_H
