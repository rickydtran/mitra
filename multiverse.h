#ifndef MULTIVERSE_H
#define MULTIVERSE_H

#include <vector>

class realm;
class edge;

class multiverse {
private:
	std::vector<realm*> realms;
public:
	void addRealm(realm *x);
	void generateAdjLists(void);
	void printRealms(void);
	void goToTest(void);
	multiverse();
};

void multiverse::addRealm(realm *x) {
	realms.push_back(x);
}

void multiverse::generateAdjLists(void) {
	for(int i = 0; i < realms.size(); i++) {
		for(int j = 0; j < realms.size(); j++) {
			if(realms[i]->goTo(realms[j]->getCharm()) == true) {
				edge *temp = new edge;
				temp->setDest(realms[j]);
				int weight = realms[i]->getNeeded(realms[j]->getCharm());
				temp->setWeight(weight);
				realms[i]->addEdge(temp);
			}
			else {
				continue;
			}
		}
	}
}

void multiverse::printRealms(void) {
	for(int i = 0; i < realms.size(); i++) {
		realms[i]->printRealmData();
		std::vector<edge*> temp = realms[i]->getAdjList();
		for(int j = 0; j < temp.size(); j++) {
			std::cout << realms[i]->getCharm() << ':' << temp[j]->getDest()->getCharm() << ':' << temp[j]->getWeight() << ' ';
		}
		std::cout << std::endl;	
	}
}

void multiverse::goToTest(void) {
	for(int i = 0; i < realms.size(); i++) {
		for(int j = 0; j < realms.size(); j++) {
			std::cout << realms[i]->goTo(realms[j]->getCharm());
		}
		std::cout << std::endl;
	}
}

multiverse::multiverse() {	
}
#endif