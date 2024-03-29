//INCLUDE GUARD
#ifndef REALM_H
#define REALM_H

//INCLUDED DEPENDENCIES
#include <cstring>
#include <vector>

//FORWARDED DECLARED DEPENDENCIES
class edge;

//REALM OBJECT. FANCY WORD OF THE USE OF A NODE
class realm {
private:
	std::string charm;
	int magi;
	int *power;
	int *subseq;
	int max;
	int needed;
	std::vector<edge*> adjList;
	bool visited;
	int dfs;
	int used;
public:
	void setCharm(std::string str);
	std::string getCharm(void);
	void setNumOfMagi(int num);
	int getNumOfMagi(void);
	void setPowerList();
	int *getPowerList(void);
	void setMaxIncantations(void);
	int getMaxIncantations(void);
	void setNeeded(std::string str);
	int getNeeded(void);
	bool goTo(std::string str);
	void addEdge(edge *x);
	std::vector<edge*> getAdjList(void);
	void setVisited(bool check);
	bool getVisited(void);
	void setDistFromSrc(int num);
	int getDistFromSrc(void);
	int calculateGemsNeeded(int weight);
	void setUsedGems(int num);
	int getUsedGems(void);
	void printRealmData(void);
	realm();
};

//FUNCTION THAT SETS THE CHARM OF A REALM
void realm::setCharm(std::string str) {
	this->charm = str;
}

//FUNCTION THAT RETRIEVES THE CHARM OF A REALM
std::string realm::getCharm(void) {
	return this->charm;
}

//FUNCTION USED TO SET THE NUMBER OF MAGIS IN A REALM
void realm::setNumOfMagi(int num) {
	this->magi = num;
}

//FUNCTION USED TO GET THE NUMBER OF MAGIS IN A REALM
int realm::getNumOfMagi(void) {
	return this->magi;
}

//FUNCTION USED TO SET THE LIST OF POWERS FOR THE MAGIS OF A REALM
void realm::setPowerList(void) {
	this->power = new int[this->magi];
	for(int i = 0; i < this->magi; i++) {
		std::cin >> this->power[i];
	}
}

//FUNCTION TO GET THE LIST OF POWERS OF THE MAGIS OF A REALM
int *realm::getPowerList(void) {
	return this->power;
}
/*
CURRENTLY ONLY RETURNS MAX INCANTATIONS. NEED TO RETRIEVE THE BIGGEST SUBSEQUENCE
NOT THAT OF IMPORTANCE, IF SUBSEQUENCE ARE OF THE SAME SIZE GET ONE WITH LESS GEMS
MODIFY TO GET THE ACTUAL SUBSEQUENCE.
*/
// void realm::setMaxIncantations(void) {
// 	int maxSubseq[this->magi];
// 	for(int i = 0; i < this->magi; i++) {
// 		maxSubseq[i] = 1;
// 	}
// 	for(int i = 1; i < this->magi; i++) {
// 		int currentMax = 1;
// 		for(int j = 0; j <= i; j++) {
// 			if(currentMax > maxSubseq[i]) {
// 				maxSubseq[i] = currentMax;
// 			}
// 			if(power[j] > power[i]) {
// 				continue;
// 			}
// 			else {
// 				currentMax = maxSubseq[j] + 1;
// 			}
// 		}
// 	}
// 	int maximum = maxSubseq[0];
// 	for(int i = 1; i < this->magi; i++) {
// 		if(maxSubseq[i] > maximum) {
// 			maximum = maxSubseq[i];
// 		}
// 		else {
// 			continue;
// 		}
// 	}
// 	this->max = maximum;
// }

/*
NEW SET MAX INCANTATIONS FUNCTION. UNLIKE PREVIOUS THIS USES A BINARY SEARCH TREE
TO FIND THE LONGEST INCRESASING SUBSEQUENCE. SETS MAX VALUE TO THIS AS WELL
AS STORE THE SUBSEQUENCE INTO AN ARRAY FOR USE LATER TO CALCULATE GEMS
*/
void realm::setMaxIncantations(void) {
	int *tail = new int[this->magi];
	int *prev = new int[this->magi];
	int maximum;
 	memset(tail, 0, sizeof(tail[0])*this->magi);
  	memset(prev, 0xFF, sizeof(prev[0])*this->magi);
	tail[0] = 0;
	prev[0] = -1;
	maximum = 1;
	for(int i = 1; i < this->magi; i++) {
		if(this->power[i] < this->power[tail[0]]) {
			tail[0] = i;
		}
		else if(this->power[i] > this->power[tail[maximum - 1]]) {
			prev[i] = tail[maximum - 1];
			tail[maximum++] = i;
		}
		else {
			int x = binarySearch(this->power, tail, -1, (maximum - 1), this->power[i]);
			prev[i] = tail[x - 1];
			tail[x] = i;
		}
	}
	int count = maximum - 1;

	this->subseq = new int[maximum];
	for(int i = tail[maximum - 1]; i >= 0; i = prev[i]) {
		subseq[count--] = this->power[i];
	}	
	this->max = maximum;
}

//FUNCTION USED TO GET THE MAX NUMBER OF INCANTATIONS THAT CAN BE DONE IN A REALM
int realm::getMaxIncantations(void) {
	return this->max;
}

//FUNCTION THAT SETS THE AMOUNT OF INCANTATION NEEDED TO GO FROM CURRENT REALM TO ONE SPECIFIED
void realm::setNeeded(std::string str) {
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
	this->needed = ld[m][n];
}

//RETURNS NEEDED AMOUNT OF GEMS NEEDED TO GO TO REALM. 
//STORED LOCALLY SO DON'T NEED TO UNNECESSARILY CALL SET NEED FUNCTION
int realm::getNeeded(void) {
	return this->needed;
}

//FUNCTION THATRETURNS WHETHER OR NOT YOU CAN GO THE REALM SPECIFIED FROM THE CURRENT REALM OR NOT
bool realm::goTo(std::string str) {
	setNeeded(str);
	if((this->needed <= this->max) && this->needed != 0) {
		return true;
	}	
	else {
		return false;
	}
}

//FUNCTION THAT ADDS AN EDGE TO THE REALM'S ADJACENCY LIST
void realm::addEdge(edge *x) {
	this->adjList.push_back(x);
}

//FUNCTION THAT RETURNS THE REALM'S ADJACENCY LIST
std::vector<edge*> realm::getAdjList(void) {
	return this->adjList;
}

//FUNCTION USED TO SET WHETHER OR NOT THE REALM HAS BEEN VISITED OR NOT FOR PATHING ALGORITHM
void realm::setVisited(bool check) {
	this->visited = check;
}

//FUNCTION USED TO CHECK IF REALM HAS BEEN VISITED YET
bool realm::getVisited(void) {
	return this->visited;
}

//FUNCTION TO SET THE DISTANCE FROM SOURCE NODE FOR PATHING ALGORITHM
void realm::setDistFromSrc(int num) {
	this->dfs = num;
}

//RETRIEVES THE DISTANCE FROM THE SOURCE REALM
int realm::getDistFromSrc(void) {
	return this->dfs;
}

//CALCULATES GEMS NECESSSARY TO GO FROM ONE REALM TO ANOTHER
int realm::calculateGemsNeeded(int weight) {
	int gems = 0;
	for(int i = 0; i < weight; i++) {
		gems += this->subseq[i];
	}
	return gems;
}

//SETS AMOUNT OF USED GEMS USED SO FAR
void realm::setUsedGems(int num) {
	this->used = num;
}

//RETURNS AMOUNT OF GEMS USED ON PATH SO FAR
int realm::getUsedGems(void) {
	return this->used;
}

//PRINT TEST OF REALMS DATA
void realm::printRealmData(void) {
	std::cout << "CHARM: " << this->charm << std::endl;
	std::cout << "NUM OF MAGI: " << this->magi << std::endl;
	std::cout << "[LIST OF POWERS IN ORDER OF CONFRONTATION]" << std::endl;
	for(int i = 0; i < this->magi; i++) {
		std::cout << this->power[i] << ' ';
	}
	std::cout << std::endl << "MAX: " << this->max << std::endl;
	std::cout << "[LIST OF MAX SUBSEQUENCE FROM LIST OF POWERS]" << std::endl;
	for(int i = 0; i < this->max; i++) {
		std::cout << this->subseq[i] << ' ';
	}
	std::cout << std::endl << "[ADJLIST POINTERS]" << std::endl;
	if(this->adjList.size() == 0) {
		std::cout << "no pointer data. empty list";
	}
 	for(unsigned int i = 0; i < this->adjList.size(); i++) {
		std::cout << this->adjList[i] << ' ';
	}
	std::cout << std::endl;
}

realm::realm() {	
}

#endif