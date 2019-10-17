#include <iostream>
#include <string>
#include "Link.h"
#include "God.h"

//moves forward Thorugh a list starting from the link argument provided and print each links value,
//we first check whether the link argument is not a nullptr, if so, we try print its value 
//property, after which we assign the link argument to it's successor pointer property. If 
//successful, we then print a new line and repeat.
void readLinks(Link* link){
	while(link){
		std::cout << link->getGod();
		if(link = link->getSuccessorLink()){
			std::cout << ",\n";
		}
	}
}

int main(){
	Link* gods = new Link(God{ "Thor","Norse","Pinzgauer","Hammer" });
	gods = gods->Insert(new Link(God{ "Odin","Norse","Eight-legged horse","" }));
	gods = gods->Insert(new Link(God{ "Zeus","Greek","","Lightning" }));
	gods = gods->Insert(new Link(God{ "Freia","Norse","F-transport","F-weapon" }));
	gods = gods->Insert(new Link(God{ "Hera","Greek","H-transport","Spear" }));
	gods = gods->Insert(new Link(God{ "Athena","Greek","A-transport","A-weapon" }));
	gods = gods->Insert(new Link(God{ "Mars","Roman","M-transport","M-weapon" }));
	gods = gods->Insert(new Link(God{ "Poseidon","Greek","Seahorse","Trident" }));
	gods = gods->Insert(new Link(God{ "Ares","Greek","A-transport","A-weapon" }));
	gods = gods->Insert(new Link(God{ "Vesuvius","Roman","V-transport","Volcano" }));
	gods = gods->Insert(new Link(God{ "Bacchus","Roman","Stretcher","Wine goblet" }));
	readLinks(gods);

	std::cin.get();
	return 0;
}