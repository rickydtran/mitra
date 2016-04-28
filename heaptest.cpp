//INCLUDED DEPENDENCIES
#include <iostream>
#include "helper.h"
#include "realm.h"
#include "edge.h"
#include "multiverse.h"
#include "heap.h"

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
	std::vector<realm*> temp = realms.getRealms();
	for(int i = 0; i < rnum; i++) {
		int val;
		std::cin >> val; 
		temp[i]->setDistFromSrc(val);
	}
	minHeap heap(temp);
	while(!heap.isHeapEmpty()) {
		realm *test = heap.extractMin();
		std::cout << test->getCharm() << std::endl; 
	}
}