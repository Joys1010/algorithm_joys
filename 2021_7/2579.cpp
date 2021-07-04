#include <iostream>
#include <algorithm>

using namespace std;
int stairs[310];
int N, x;
int values[310];

void dp(int x) {

	if (x == 0) {
		values[x] = stairs[x];
	}
	else if (x == 1) {
		values[x] = stairs[x] + values[x-1];
	}
	else if (x == 2) {
		values[x] = stairs[x] + max(stairs[x-1], values[x-2]);
	}	
	else {
		values[x] = stairs[x] + max(stairs[x-1]+values[x-3],values[x-2]);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i=0;i<N;i++) {
		cin >> x;
		stairs[i] = x;
	}
	
	for (int i=0;i<N;i++) {
		dp(i);
	}
	cout << values[N-1] << endl;

	return 0;
}
