#include <iostream>
#include <string>
#include "realm.h"
#include "multiverse.h"
#include "essentials.h"

int main(void) {
	int rnum, magi;
	std::string realm1, realm2, charm;
	std::cin >> rnum;
	//realm *realms[rnum];
	multiverse realms;
	for(int i = 0; i < rnum; i++) {
		// realms[i] = new realm;
		// std::cin >> charm >> magi;
		// realms[i]->setCharm(charm);
		// realms[i]->setNumOfMagi(magi);
		// realms[i]->setPowerList();
		// realms[i]->setMaxIncantations();
		realm *temp = new realm;
		std::cin >> charm >> magi;
		temp->setCharm(charm);
		temp->setNumOfMagi(magi);
		temp->setPowerList();
		temp->setMaxIncantations();
		realms.addRealm(*temp);
	}
	std::cin >> realm1 >> realm2;
	//std::cout << incantationsNeeded(realm1, realm2, realm1.length(), realm2.length()) << std::endl;
	realms.printRealms();
	return 0;
}
