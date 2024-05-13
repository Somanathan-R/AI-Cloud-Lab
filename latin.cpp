#include <iostream> 
using namespace std; 

void printLatin(int n) 
{ 
	int k = n+1; 
	for (int i=1; i<=n; i++) 
	{ 
		int temp = k; 
		while (temp <= n) 
		{ 
			cout << temp << " "; 
			temp++; 
		} 

		for (int j=1; j<k; j++) 
			cout << j << " "; 

		k--; 
		cout << endl; 
	} 
} 

int main(void) 
{ 
	int n = 5; 
	printLatin(n); 
	return 0; 
} 
