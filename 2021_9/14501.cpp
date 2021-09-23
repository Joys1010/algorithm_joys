#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int t, d;
int dp[16];
int info[16][2];
int maxi;

int main() {
	FASTIO();

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> info[i][0] >> info[i][1];
	}

	for (int i = 0; i <= N; i++) {

		maxi = max(maxi, dp[i]);

		if (i + info[i][0] > N) {
			continue;
		}

		dp[i + info[i][0]] = max(dp[i + info[i][0]], maxi + info[i][1]);
	} 


	cout << maxi << "\n";

	return 0;
}

