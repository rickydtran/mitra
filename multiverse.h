#ifndef MULTIVERSE_H
#define MULTIVERSE_H

#include <vector>

class multiverse {
private:
	std::vector<realm> realms;
public:
	void addRealm(realm x);
	void printRealms(void);
	multiverse();
};

void multiverse::addRealm(realm x) {
	realms.push_back(x);
}

void multiverse::printRealms(void) {
	for(int i = 0; i < realms.size(); i++) {
		realms[i].printRealmData();
	}
}
multiverse::multiverse() {	
}
#endif