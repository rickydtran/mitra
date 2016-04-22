#include <iostream>
#include <string>
#include "incantations.h"

int main(void) {
	std::string str1, str2;
	std::cin >> str1 >> str2;
	int need = incantationsNeeded(str1, str2, str1.length(), str2.length());
	std::cout << need << std::endl;
	return 0;
}