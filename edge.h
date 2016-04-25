//INCLUDE GUARD
#ifndef EDGE_H
#define EDGE_H

//FORWARDED DECLARED DEPENDENCIES
class realm;

//EDGE CLASS. IT IS WHAT IT IS
class edge {
private:
	realm *dest;
	int weight;
	int gems;
public:
	void setDest(realm *x);
	realm *getDest(void);
	void setWeight(int num);
	int getWeight(void);
	void setGems(int num);
	int getGems(void);
};

//FUNCTION THAT SETS THE DESTINATION POINTER OF THE EDGE
void edge::setDest(realm *x) {
	this->dest = x;
}

//FUNCTION THAT GETS THE DESTINATION POINTER OF THAT EDGE
realm *edge::getDest() {
	return this->dest;
}

//FUNCTION THAT SETS THE WEIGHT OF AN EDGE
void edge::setWeight(int num) {
	this->weight = num;
}

//FUNCTION USED TO GET THE WEIGHT OF AN EDGE
int edge::getWeight() {
	return this->weight;
}

void edge::setGems(int num) {
	this->gems = num;
}

int edge::getGems(void) {
	return this->gems;
}
#endif