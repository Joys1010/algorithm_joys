#include <iostream>
#include <algorithm>

using namespace std;

int N, x, y;
int numbers[1010];
int dps[1010];
int tmp, maximum;

void dp(int x) {

	for (int i=0;i<x;i++) {

		if (numbers[x] < numbers[i] && dps[i] + 1 > dps[x]) {
			dps[x] = 1 + dps[i];
		}
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i=0;i<N;i++) {

		cin >> x;
		numbers[i] = x;
		dps[i] = 1;
	}

	dps[0] = 1;

	for (int i=1;i<N;i++) {
		dp(i);
	}

	for (int i=0;i<N;i++) {
		tmp = dps[i];
		if (tmp > maximum) {
			maximum = tmp;
		}
	}
	
	cout << maximum << endl;
	return 0;
}
