#include <iostream>

using namespace std;

int LIS( int size ){

	int arr[size], maxSubsequence[size];														// Create 2 arrays of the indicated size

	for (int i = 0; i < size; i++){																// Fill in the indicated magi levels into the array
		cin >> arr[i];
		maxSubsequence[i] = 1;																	// Max subsequent increasing for each individual point is 1
	}

	int currentMax;
	for (int i = 1; i < size; i++)																// Iterate though all i
	{
		currentMax = 1;
		for ( int j = 0; j <= i;j++) {															// Iterate though all j within i

			if ( currentMax > maxSubsequence[i]){												// If the current max is greater change the respective array location
				maxSubsequence[i] = currentMax;
				//cout  << "\n" << "During loop: " << j << " we get =" << maxSubsequence[i]; 
			}
			if ( arr[j] > arr[i] ){																// if the value at j is greater then the value at i continue to next iteration
				continue;
			}else {																				// Else increase current max by 1
				currentMax  = maxSubsequence[j] + 1;
			}
			

		}
	}
	int max = maxSubsequence[0];
	for ( int g = 1; g < size ; g++){															// Iterate through array and find the largest value
		if ( maxSubsequence[g] > max) max = maxSubsequence[g];
		//cout << "\n"<< "Max at I:" << g << " value = " << maxSubsequence[g];
	}
	return max;																					// Return largest integer

}

int main(){

	int NumOfMagi;

	cin >> NumOfMagi;																			// Enter the Number of Magi encountered in the current Realm
	int maxChanges = LIS(NumOfMagi);															// Return the length of the longest increasing subsequence
	cout << "\n" << maxChanges;

	return 0;
}