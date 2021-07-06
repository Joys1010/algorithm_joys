#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, K;
int weight, value;
int dps[100 + 1][100000 + 1];
int weights[100 + 1];
int values[101 + 1];
int maxi;

void dp() {

	for (int i=1;i<=N;i++) {
		for (int j=1;j<=K;j++) {

			if (weights[i-1] > j) {
				dps[i][j] = dps[i-1][j];
			}
			else {
				dps[i][j] = max(values[i-1] + dps[i-1][j-weights[i-1]], dps[i-1][j]);
			}

			if (maxi < dps[i][j]) {
				maxi = dps[i][j];
			}
		}
	}	
}

int main() {
	FASTIO();

	cin >> N >> K;

	for (int i=0;i<N;i++) {
		cin >> weights[i] >> values[i];	
	}

	dp();

	cout << maxi << "\n";
	
	return 0;
}
