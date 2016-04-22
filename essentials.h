#ifndef ESSENTIALS_H
#define ESSENTIALS_H
int minimum(int a, int b, int c) {
	int min = a;
	if(b < min) {
		min = b;
	}
	if(c < min) {
		min = c;
	}
	return min;
}
int incantationsNeeded(std::string str1, std::string str2, int m, int n) {
	int ld[m + 1][n + 1];
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			if(i == 0) {
				ld[i][j] = j;
			}
			else if(j == 0) {
				ld[i][j] = i;
			}
			else if(str1[i - 1] == str2[j - 1]) {
				ld[i][j] = ld[i - 1][j - 1];
			}
			else {
				ld[i][j]= 1 + minimum(ld[i][j - 1], ld[i - 1][j], ld[i - 1][j - 1]);
			}
		}
	}
	return ld[m][n];
}
#endif