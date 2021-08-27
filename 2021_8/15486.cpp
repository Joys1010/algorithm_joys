#include <iostream>
#include <cmath>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

#define N 1500000
using namespace std;

int dp[N+1];
int info[N][2];
int maxi;
int n;

int main() {
	FASTIO();
	
	cin >> n;

	for (int i = 0; i < n; i ++) {
		cin >> info[i][0] >> info[i][1];
	}

	
	for (int i = 0; i <= n; i ++) {
		maxi = max(dp[i], maxi);

		if (i + info[i][0] > n) {
			continue;
		}

		dp[i + info[i][0]] = max(maxi + info[i][1], dp[i + info[i][0]]);
	}

	cout << maxi << "\n";

	return 0;
}
