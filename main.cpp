//INCLUDED DEPENDENCIES
#include <iostream>
#include <string>
#include "helper.h"
#include "realm.h"
#include "edge.h"
#include "multiverse.h"

//MAIN DRIVER FUNCTION
int main(void) {
	int rnum, magi;
	std::string realm1, realm2, charm;
	std::cin >> rnum;
	//NEW MULTIVERSE
	multiverse realms;
	//CREATION OF REALMS BASED OFF HOW MANY REALMS SPECIFIED
	for(int i = 0; i < rnum; i++) {
		realm *temp = new realm;
		std::cin >> charm >> magi;
		temp->setCharm(charm);
		temp->setNumOfMagi(magi);
		temp->setPowerList();
		temp->setMaxIncantations();
		realms.addRealm(temp);
	}
	//GENERATES ADJACENCY LISTS AND WEIGHTS OF MULTIVERSE
	realms.generateAdjLists();
	std::cin >> realm1 >> realm2;
	//REALM POINTER DATA RETRIEVAL
	realm *src = realms.getRealm(realm1);
	realm *dest = realms.getRealm(realm2);
	//PRINTS THE TEST DATA OF THE REALMS
	realms.printRealms();
	//FINDS PATH OF LEAST INCANTATIONS FROM SOURCE TO DESTINATION AND THEN BACK TO SOURCE
	realms.pathOfLeastIncantations(src, dest);
	realms.pathOfLeastIncantations(dest, src);
	return 0;
}
