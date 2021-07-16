#include <iostream>
#include <cmath>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int first, second;

void find_sosu(int num) {
	if (num == 1) {
		return;
	}
	int sqrt_num = (int) sqrt(num);

	for (int i = 2; i < sqrt_num+1; i++) {
		if (num % i == 0) {
			return;
		}
	}
	cout << num << "\n";
	return;

}

int main() {
	FASTIO();

	cin >> first >> second;

	for (int i = first; i < second + 1; i++) {
		find_sosu(i);
	}
	return 0;
}

