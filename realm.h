#ifndef REALM_H
#define REALM_H

class realm {
private:
	std::string charm;
	int magi;
	int *power;
	int max;
public:
	void setCharm(std::string str);
	std::string getCharm(void);
	void setNumOfMagi(int num);
	int getNumOfMagi(void);
	void setPowerList();
	int *getPowerList(void);
	void setMaxIncantations(void);
	void printRealmData(void);
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

void realm::setPowerList(void) {
	this->power = new int[this->magi];
	for(int i = 0; i < this->magi; i++) {
		std::cin >> this->power[i];
	}
}

int *realm::getPowerList(void) {
	return this->power;
}

void realm::setMaxIncantations(void) {
	int maxSubseq[this->magi];
	for(int i = 0; i < this->magi; i++) {
		maxSubseq[i] = 1;
	}
	for(int i = 1; i < this->magi; i++) {
		int currentMax = 1;
		for(int j = 0; j <= i; j++) {
			if(currentMax > maxSubseq[i]) {
				maxSubseq[i] = currentMax;
			}
			if(power[j] > power[i]) {
				continue;
			}
			else {
				currentMax = maxSubseq[j] + 1;
			}
		}
	}
	int maximum = maxSubseq[0];
	for(int i = 1; i < this->magi; i++) {
		if(maxSubseq[i] > maximum) {
			maximum = maxSubseq[i];
		}
		else {
			continue;
		}
	}
	this->max = maximum;
}

void realm::printRealmData(void) {
	std::cout << this->charm << std::endl;
	std::cout << this->magi << std::endl;
	for(int i = 0; i < this->magi; i++) {
		std::cout << this->power[i] << ' ';
	}
	std::cout << std::endl << this->max << std::endl;
}

#endif