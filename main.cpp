#include <iostream>
#include <string>
#include "objects.h"
#include "incantations.h"

using namespace std;

int main() {
	int rnum;
	string realm1, realm2;
	cin >> rnum;
	realm *realms[rnum];
	for(int i = 0; i < rnum; i++) {
		realms[i] = new realm;
		cin >> realms[i]->charm >> realms[i]->magi;
		int power[realms[i]->magi];
		for(int j = 0; j < realms[i]->magi; j++) {
			cin >> power[j];
		}
		realms[i]->power = power;
	}
	cin >> realm1 >> realm2;
	//test
	cout << incantationsNeeded(realm1, realm2, realm1.length(), realm2.length()) << endl;
}