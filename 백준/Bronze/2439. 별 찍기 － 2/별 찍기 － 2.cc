// boj 2439

#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		for(int k = 0; k < t - i; k++) {
			cout << " ";
		}
		for(int k = 0; k < i; k++) {
			cout << "*";
		}
		cout << '\n';
	}
	
	return 0;
}