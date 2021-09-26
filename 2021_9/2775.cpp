#include <iostream>

using namespace std;

int main() {
	
	int T, k, n;
	
	int people[15][15];
	for (int i = 1; i < 15; i++) {
		people[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			int tmp = 0;
			for (int k = 1; k < j + 1; k++) {
				tmp += people[i-1][k];
			}
			people[i][j] = tmp;
		}
	}

	cin >> T;
	

	while (T > 0) {
		cin >> k >> n;

		cout << people[k][n] << "\n";

		T--;
	}
	return 0;
}
