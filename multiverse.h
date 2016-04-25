//INCLUDE GUARD
#ifndef MULTIVERSE_H
#define MULTIVERSE_H

//INCLUDED DEPENDENCIES
#include <vector>
#include <unordered_map>
#include <limits.h>

//FORWARD DECLARED DEPENDENCIES
class realm;
class edge;

//MULTIVERSE OBJECT. PRETTY MUCH FANCY WORD FOR THE GRAPH ITSELF
class multiverse {
private:
	std::vector<realm*> realms;
	std::unordered_map<std::string, realm*> lookup;
public:
	void addRealm(realm *x);
	realm *getRealm(std::string str);
	void generateAdjLists(void);
	void printRealms(void);
	void goToTest(void);
	realm *minDistance(void);
	int pathOfLeastIncantations(realm *src, realm *dest);
	multiverse();
};

//REVISE TO ADD STRING KEY AND POINTER DATA TO HASHMAP FOR LOOKUP
void multiverse::addRealm(realm *x) {
	this->realms.push_back(x);
	this->lookup.insert(std::make_pair(x->getCharm(), x));
}

/*
OLD FUNCTION THAT GOT DATA IN 0(N) BY LINEARLY SEARCHING FOR THE STRING
*/
// realm *multiverse::getRealm(std::string str) {
// 	for(int i = 0; i < this->realms.size(); i++) {
// 		if(this->realms[i]->getCharm() == str) {
// 			return realms[i];
// 		}
// 		else {
// 			continue;
// 		}
// 	}
// }

//NEW GET FUNCTION THAT LOOKS UP STRING KEY IN HASHMAP AND RETURNS THE POINTER TO THE REALM
realm *multiverse::getRealm(std::string str) {
	std::unordered_map<std::string, realm*>::iterator it = lookup.find(str);
	if(it == lookup.end()) {
		std::cout << "BRUH" << std::endl;
	}
	else {
		return it->second;
	}
}

//FUNCTION USED TO GENERATE THE ADJACENCY LISTS FOR EACH OF THE REALMS. THIS IS NECESSARY DUE
//TO THE ABILITY TO GO THE OTHER REALMS IS DEPENDENT UPON THE NUMBER OF CHANGES TO A CHARM OF THE
//SOURCE REALM TO DESTINATION REALM AS WELL AS THE NUMBER OF CHANGES THAT COULD BE MADE IN A REALM
//IS DEPENDENT UPON THE MAX SUBSEQUENCE IN THE POWER OF THE MAGIS
//ADDED CALCULATION NEEDED ON THE EDGE TO GO FROM ONE REALM TO ANOTHER
void multiverse::generateAdjLists(void) {
	for(int i = 0; i < this->realms.size(); i++) {
		for(int j = 0; j < this->realms.size(); j++) {
			if(this->realms[i]->goTo(this->realms[j]->getCharm()) == true) {
				edge *temp = new edge;
				temp->setDest(this->realms[j]);
				int weight = this->realms[i]->getNeeded(this->realms[j]->getCharm());
				temp->setWeight(weight);
				//insert gem calculation function here
				int gems = this->realms[i]->calculateGemsNeeded(weight);
				temp->setGems(gems);				
				this->realms[i]->addEdge(temp);
			}
			else {
				continue;
			}
		}
	}
}

//PRINT TEST FUNCTION THAT PRINTS ALL THE DATA IN THE REALMS OF THE MULTIVERSE
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

//PRINT TEST FUNCTION THAT IS USED TO SEE IF THE GOTO FUNCTION WORKS PROPERLY. USED TO SEE IF A REALM CAN BE REACH
//FROM CURRENT REALM. IF TRUE THEN YOU CAN GO THE THE DESIRED REALM FROM THE CURRENT REALM
void multiverse::goToTest(void) {
	for(int i = 0; i < this->realms.size(); i++) {
		for(int j = 0; j < this->realms.size(); j++) {
			std::cout << this->realms[i]->goTo(this->realms[j]->getCharm());
		}
		std::cout << std::endl;
	}
}

/*
BELOW IS THE ALGORITHM USED TO FIND THE SHORTEST PATH (DIJKSTRA'S ALGORITHM)
CURRENTLY USING THE TIME COMPLEXITY OF O(N^2). 
TODO: MODIFY WITH THE USE OF A BINARY HEAP TO REDUCE TIME COMPLEXITY TO O(N+ELOG(N))
	  COULD USE FIBONACCI HEAP, BUT FUCK THAT
*/
//HELPER FUNCTION USED TO FIND THE VERTEX OR REALM THAT HAS NOT BEEN VISTED AND HAS A DISTANCE THAT IS 
//CURRENTLY LESS THAN THE CURRENT MINIMUM VALUE. ONCE HEAP IS IMPLEMENTED THIS FUNCTION IS NO LONGER NECESSARY
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

//CURRENTLY SOURCE TO ALL DESTINATIONS. NEEDS TO BE REVISED TO SOURCE TO DESTINATION
int multiverse::pathOfLeastIncantations(realm *src, realm *dest) {
	for(int i = 0; i < this->realms.size(); i++) {
		this->realms[i]->setVisited(false);
		this->realms[i]->setDistFromSrc(INT_MAX);
		this->realms[i]->setUsedGems(0);
	}
	src->setDistFromSrc(0);
	src->setVisited(true);
	std::vector<edge*> temp = src->getAdjList();
	for(int i = 0; i < temp.size(); i++) {
		if(!temp[i]->getDest()->getVisited() && (temp[i]->getDest()->getDistFromSrc() > (src->getDistFromSrc() + temp[i]->getWeight()))) {
			temp[i]->getDest()->setDistFromSrc(src->getDistFromSrc() + temp[i]->getWeight());
			temp[i]->getDest()->setUsedGems(temp[i]->getGems());			
		}
	}
	for(int i = 0; i < this->realms.size() - 1; i++) {
		realm *ptr = minDistance();
		ptr->setVisited(true);		
		temp = ptr->getAdjList();
		for(int j = 0; j < temp.size(); j++) {
			if(!temp[j]->getDest()->getVisited() && ptr->getDistFromSrc() != INT_MAX && (temp[j]->getDest()->getDistFromSrc() > (ptr->getDistFromSrc() + temp[j]->getWeight()))) {
				temp[j]->getDest()->setDistFromSrc(ptr->getDistFromSrc() + temp[j]->getWeight());
				temp[j]->getDest()->setUsedGems(temp[i]->getGems());						
			}			
		}
		if(ptr == dest) {
			return ptr->getDistFromSrc();
			break;
		}
		else {
			continue;
		}
		return INT_MAX;
	}
}

multiverse::multiverse() {	
};
#endif