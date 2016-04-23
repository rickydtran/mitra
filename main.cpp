#include <iostream>
#include <string>
#include "helper.h"
#include "realm.h"
#include "edge.h"
#include "multiverse.h"

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
		realms.addRealm(temp);
	}
	realms.generateAdjLists();
	std::cin >> realm1 >> realm2;
	realm *ptr1 = realms.getRealm(realm1);
	realm *ptr2 = realms.getRealm(realm2);
	//std::cout << incantationsNeeded(realm1, realm2, realm1.length(), realm2.length()) << std::endl;
	realms.printRealms();
	realms.pathOfLeastIncantations(ptr1, ptr2);
	realms.pathOfLeastIncantations(ptr2, ptr1);
	return 0;
}
