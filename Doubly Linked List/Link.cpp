#include "Link.h"

//insert a link into the list behind this object. We set new_link's successor pointer to point at this object. Then
//we check whether this objects previous pointer pointed at anything and if so, we set that objects successor 
//pointer to point at new_link. We then set new_links previous pointer to point at the object which this object's 
//previous pointer pointed at. We then set this object's previous pointer to point at new_link and return a pointer
//to new_link
Link* Link::Insert(Link* new_link){
	if(!new_link){ return this; }//if new_link pointer is null, don't fuck up this pointer
	if(!this){ return new_link; }//undefined behaviour territory
	new_link->_successor = this;
	if(_previous){ _previous->_successor = new_link; }
	new_link->_previous = _previous;
	_previous = new_link;
	return new_link;
}

//adds a link to the front of a list. We begin by setting new_link's previous pointer to point at this object. We
//then check whether this object's successor pointer points at anything and if so, we throw a runtime_error. After
//this, we set this objects's successor pointer to point at new_link and return a pointer to new_link
Link* Link::Add(Link* new_link){
	if(!new_link){ return this; }//if new_link pointer is null, don't fuck up this pointer
	if(!this){ return new_link; }//undefined behaviour territory
	new_link->_previous = this;
	if(_successor){ throw std::runtime_error("ERROR: Cannot add link to object which already contains the next link."); }
	_successor = new_link;
	return new_link;
}

//removes this object from a list and patches the list back together without this object included. We first check
//whether this object's previous pointer pointed at anything and if so, we set the object which this object's 
//previous pointer pointed at to now have it's successor pointer to point at whatever this object's successor
//pointer points at. We then check whether this object's successor pointer points at anything and if so, we set 
//that object's previous pointer to point at whatever this object's previous pointer points at. We then return 
//this object's successor (could be nullptr)
Link* Link::Remove(){
	if(!this){ return this; }//undefined behaviour territory
	if(_successor){ _successor->_previous = _previous; }
	if(_previous){ _previous->_successor = _successor; }
	return _successor;
}

//move forward through a list from this object, if a link with a value matching the string argument provided is 
//found, return that link, otherwise returns a nullptr
Link* Link::Find(const std::string& god){
	if(!this){ return this; }//undefined behaviour territory
	Link* p = this;
	while(p){
		if(p->_god._name == god){ return p; }
		p = p->_successor;
	}
	return nullptr;
}

//move forward through a list from this object, if a link with a value matching the string argument provided is
//found, return that link, otherwise returns a nullptr
const Link* Link::Find(const std::string& god) const{
	if(!this){ return nullptr; }//undefined behaviour territory
	Link* p = const_cast<Link*>(this);//shouldn't ever do this
	while(p){
		if(p->_god._name == god){ return p; }
		p = p->_successor;
	}
	return nullptr;
}

//jumps forward or backward in a list depending on the provided jump argument. If provided value exceeds the 
//amount of links in a list, a nullptr is returned. After making the required amount of jumps, a pointer to that
//link is returned.
Link* Link::advance(int jumps) const{
	if(!this){ return nullptr; }//undefined behaviour territory
	Link* p = const_cast<Link*>(this);//shouldn't ever do this
	if(jumps > 0){
		while(jumps--){
			if(!p->_successor){ return nullptr; }
			p = p->_successor;
		}
	} else if(jumps < 0){
		while(jumps++){
			if(!p->_previous){ return nullptr; }
			p = p->_previous;
		}
	}
	return p;
}