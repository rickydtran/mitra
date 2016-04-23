#ifndef HELPER_H
#define HELPER_H

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

#endif