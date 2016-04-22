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
	void setPowerList();
	int *getPowerList(void);
	void printRealmData(void);
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

void realm::setPowerList() {
	this->power = new int[this->magi];
	for(int i = 0; i < this->magi; i++) {
		std::cin >> power[i];
	}
}

int *realm::getPowerList(void) {
	return this->power;
}

void realm::printRealmData(void) {
	std::cout << this->charm << std::endl;
	std::cout << this->magi << std::endl;
	for(int i = 0; i < this->magi; i++) {
		std::cout << this->power[i] << ' ';
	}
	std::cout << std::endl;
}
#endif