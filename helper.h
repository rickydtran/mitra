//INCLUDE GUARD
#ifndef HELPER_H
#define HELPER_H

//LITERALLY COMPUTES MINIMUM OF THREE INTEGERS LOL.
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

//BINARY SEARCH ALGORITHM USED TO GET THE MAX INCANTATIONS
int binarySearch(int *x, int *y, int left, int right, int val) {
	while(right - left > 1) {
		int m = left + (right - left) / 2;
		if(x[y[m]] >= val) {
			right = m;
		}
		else {
			left = m;
		}
	}
	return right;
}
#endif