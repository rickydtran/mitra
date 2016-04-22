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

void setMaxIncantations(){
	int maxSubsequence[this->magi];																// Create 1 array of the indicated size

	for (int i = 0; i < this->magi; i++){														// Fill in the indicated magi levels into the array
		maxSubsequence[i] = 1;																	// Max subsequent increasing for each individual point is 1
	}

	int currentMax;
	for (int i = 1; i < this->magi; i++)														// Iterate though all i
	{
		currentMax = 1;
		for ( int j = 0; j <= i;j++) {															// Iterate though all j within i

			if ( currentMax > maxSubsequence[i]){												// If the current max is greater change the respective array location
				maxSubsequence[i] = currentMax;
				//cout  << "\n" << "During loop: " << j << " we get =" << maxSubsequence[i]; 
			}
			if ( power[j] > power[i] ){															// if the value at j is greater then the value at i continue to next iteration
				continue;
			}else {																				// Else increase current max by 1
				currentMax  = maxSubsequence[j] + 1;
			}
			

		}
	}
	int maxi = maxSubsequence[0];
	for ( int g = 1; g < this->magi ; g++){														// Iterate through array and find the largest value
		if ( maxSubsequence[g] > maxi) maxi = maxSubsequence[g];
		//cout << "\n"<< "Max at I:" << g << " value = " << maxSubsequence[g];
	}
	this->max = maxi;																			// Return largest integer

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