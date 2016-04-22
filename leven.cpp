#include <iostream>
#include <string>
#include "incantations.h"

using namespace std;

int main() {	
	string a, b;
	cin >> a >> b;
	int dist = incantationsNeeded(a, b, a.length(), b.length());
	cout << dist << endl;
}