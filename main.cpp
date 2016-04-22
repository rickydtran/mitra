#include <iostream>
#include <string>
#include "realm.h"
#include "essentials.h"

int main(void) {
	int rnum, magi;
	std::string realm1, realm2, charm;
	std::cin >> rnum;
	realm *realms[rnum];
	for(int i = 0; i < rnum; i++) {
		realms[i] = new realm;
		std::cin >> charm >> magi;
		realms[i]->setCharm(charm);
		realms[i]->setNumOfMagi(magi);
		realms[i]->setPowerList();
	}
	std::cin >> realm1 >> realm2;
	//test
	std::cout << incantationsNeeded(realm1, realm2, realm1.length(), realm2.length()) << std::endl;
	for(int i = 0; i < rnum; i++) {
		realms[i]->printRealmData();
	}
	return 0;
}
