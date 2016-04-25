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
public:
	void setDest(realm *x);
	realm *getDest(void);
	void setWeight(int num);
	int getWeight(void);
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

#endif