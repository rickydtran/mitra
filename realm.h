#ifndef REALM_H
#define REALM_H

class realm {
private:
	std::string charm;
	int magi;
	int *power;
public:
	void setCharm(std::string str);
	std::string getCharm(void);
	void setNumOfMagi(int num);
	int getNumOfMagi(void);
	void setPowerList(int *arr);
	int *getPowerList(void);
	//realm(std::string charm, int magi, int *power);
};

void realm::setCharm(std::string str) {
	this->charm = str;
}

std::string realm::getCharm(void) {
	return this->charm;
}

void realm::setNumOfMagi(int num) {
	this->magi = num;
}

int realm::getNumOfMagi(void) {
	return this->magi;
}

void realm::setPowerList(int *arr) {
	this->power = arr;
}

int *realm::getPowerList(void) {
	return this->power;
}
#endif