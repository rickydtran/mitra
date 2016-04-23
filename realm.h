#ifndef REALM_H
#define REALM_H

#include <string>
#include <vector>

class edge;

class realm {
private:
	std::string charm;
	int magi;
	int *power;
	int max;
	std::vector<edge*> adjList;
	bool visited;
	int dfs;
public:
	void setCharm(std::string str);
	std::string getCharm(void);
	void setNumOfMagi(int num);
	int getNumOfMagi(void);
	void setPowerList();
	int *getPowerList(void);
	void setMaxIncantations(void);
	int getMaxIncantations(void);
	int getNeeded(std::string str);
	bool goTo(std::string str);
	void addEdge(edge *x);
	std::vector<edge*> getAdjList(void);
	void setVisited(bool check);
	bool getVisited(void);
	void setDistFromSrc(int num);
	int getDistFromSrc(void);
	void printRealmData(void);
	realm();
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

int realm::getMaxIncantations(void) {
	return this->max;
}

int realm::getNeeded(std::string str) {
	std::string src, dest;
	src = this->charm;
	dest = str;
	int m = src.length();
	int n = dest.length();
	int ld[m + 1][n + 1];
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			if(i == 0) {
				ld[i][j] = j;
			}
			else if(j == 0) {
				ld[i][j] = i;
			}
			else if(src[i - 1] == dest[j - 1]) {
				ld[i][j] = ld[i - 1][j - 1];
			}
			else {
				ld[i][j]= 1 + minimum(ld[i][j - 1], ld[i - 1][j], ld[i - 1][j - 1]);
			}
		}
	}
	return ld[m][n];
}

bool realm::goTo(std::string str) {
	int needed = getNeeded(str);
	if((needed <= max) && needed != 0) {
		return true;
	}	
	else {
		return false;
	}
}

void realm::addEdge(edge *x) {
	this->adjList.push_back(x);
}

std::vector<edge*> realm::getAdjList(void) {
	return this->adjList;
}

void realm::setVisited(bool check) {
	this->visited = check;
}

bool realm::getVisited(void) {
	return this->visited;
}

void realm::setDistFromSrc(int num) {
	this->dfs = num;
}

int realm::getDistFromSrc(void) {
	return this->dfs;
}

void realm::printRealmData(void) {
	std::cout << this->charm << std::endl;
	std::cout << this->magi << std::endl;
	for(int i = 0; i < this->magi; i++) {
		std::cout << this->power[i] << ' ';
	}
	std::cout << std::endl << this->max << std::endl;
	for(int i = 0; i < this->adjList.size(); i++) {
		std::cout << this->adjList[i] << ' ';
	}
	std::cout << std::endl;
}

realm::realm() {	
}

#endif