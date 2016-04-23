#ifndef MULTIVERSE_H
#define MULTIVERSE_H

#include <vector>
#include <limits.h>

class realm;
class edge;

class multiverse {
private:
	std::vector<realm*> realms;
public:
	void addRealm(realm *x);
	realm *getRealm(std::string str);
	void generateAdjLists(void);
	void printRealms(void);
	void goToTest(void);
	realm *minDistance(void);
	void pathOfLeastIncantations(realm *src, realm *dest);
	multiverse();
};

void multiverse::addRealm(realm *x) {
	this->realms.push_back(x);
}

realm *multiverse::getRealm(std::string str) {
	for(int i = 0; i < this->realms.size(); i++) {
		if(this->realms[i]->getCharm() == str) {
			return realms[i];
		}
		else {
			continue;
		}
	}
}

void multiverse::generateAdjLists(void) {
	for(int i = 0; i < this->realms.size(); i++) {
		for(int j = 0; j < this->realms.size(); j++) {
			if(this->realms[i]->goTo(this->realms[j]->getCharm()) == true) {
				edge *temp = new edge;
				temp->setDest(this->realms[j]);
				int weight = this->realms[i]->getNeeded(this->realms[j]->getCharm());
				temp->setWeight(weight);
				this->realms[i]->addEdge(temp);
			}
			else {
				continue;
			}
		}
	}
}

void multiverse::printRealms(void) {
	for(int i = 0; i < this->realms.size(); i++) {
		this->realms[i]->printRealmData();
		std::vector<edge*> temp = this->realms[i]->getAdjList();
		for(int j = 0; j < temp.size(); j++) {
			std::cout << this->realms[i]->getCharm() << ':' << temp[j]->getDest()->getCharm() << ':' << temp[j]->getWeight() << ' ';
		}
		std::cout << std::endl;	
	}
}

void multiverse::goToTest(void) {
	for(int i = 0; i < this->realms.size(); i++) {
		for(int j = 0; j < this->realms.size(); j++) {
			std::cout << this->realms[i]->goTo(this->realms[j]->getCharm());
		}
		std::cout << std::endl;
	}
}

realm *multiverse::minDistance(void) {
	int min = INT_MAX;
	realm *ptr = NULL;
	for(int i = 0; i < this->realms.size(); i++) {
		if(this->realms[i]->getVisited() == false && this->realms[i]->getDistFromSrc() <= min) {
			min = this->realms[i]->getDistFromSrc();
			ptr = realms[i];
		}
		else {
			continue;
		}
	}
	return ptr;
}

void multiverse::pathOfLeastIncantations(realm *src, realm *dest) {
	for(int i = 0; i < this->realms.size(); i++) {
		this->realms[i]->setVisited(false);
		this->realms[i]->setDistFromSrc(INT_MAX);
	}
	src->setDistFromSrc(0);
	src->setVisited(true);
	std::vector<edge*> temp = src->getAdjList();
	for(int i = 0; i < temp.size(); i++) {
		if(!temp[i]->getDest()->getVisited() && (temp[i]->getDest()->getDistFromSrc() > (src->getDistFromSrc() + temp[i]->getWeight()))) {
			temp[i]->getDest()->setDistFromSrc(src->getDistFromSrc() + temp[i]->getWeight());
		}
	}
	for(int i = 0; i < this->realms.size() - 1; i++) {
		realm *ptr = minDistance();
		ptr->setVisited(true);
		temp = ptr->getAdjList();
		for(int j = 0; j < temp.size(); j++) {
			if(!temp[j]->getDest()->getVisited() && ptr->getDistFromSrc() != INT_MAX && (temp[j]->getDest()->getDistFromSrc() > (ptr->getDistFromSrc() + temp[j]->getWeight()))) {
				temp[j]->getDest()->setDistFromSrc(ptr->getDistFromSrc() + temp[j]->getWeight());
			}			
		}
	}
	for(int i = 0; i < realms.size(); i++) {
		std::cout << realms[i]->getDistFromSrc() << ' ';
	}
	std::cout << std::endl;
}

multiverse::multiverse() {	
};
#endif