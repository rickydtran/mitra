#ifndef EDGE_H
#define EDGE_H

class realm;

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

void edge::setDest(realm *x) {
	this->dest = x;
}

realm *edge::getDest() {
	return this->dest;
}

void edge::setWeight(int num) {
	this->weight = num;
}

int edge::getWeight() {
	return this->weight;
}

#endif