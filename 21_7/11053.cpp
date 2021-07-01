#include <iostream>
#include <algorithm>

using namespace std;

int N, x, y;
int numbers[1010];
int dps[1010];
int tmp, maximum;

int dp(int x) {

	if (numbers[x] > numbers[x-1]) {
		if (numbers[x] > numbers[x-2]) {
			dps[x] = 1 + max(dps[x-1], dps[x-2]);
		}
		else {
			dps[x] = 1 + dps[x-1];
		}
	}
	else {
		if (numbers[x] > numbers[x-2]) {
			dps[x] = 1 + dps[x-2];
		}
		else {
			dps[x] = 1;
		}
	}
	return dps[x];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	for (int i=0;i<N;i++) {
		cin >> x;
		numbers[i] = x;		
	}
	
	dps[0] = 1;

	if (numbers[1] > numbers[0]) {
		dps[1] = 1 + dps[0];
	}
	else {
		dps[1] = 1;
	}

	for (int i=2;i<N;i++) {
		tmp = dp(i);
		if (tmp >= maximum) {
			maximum = tmp;
		}
	}

	cout << maximum << endl;

	return 0;
}
