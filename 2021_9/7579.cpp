#include <iostream>
#include <cmath>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

#define MAX_N 100

int N, M;
int m, c;

long long memory[MAX_N+1];
long long cost[MAX_N+1];

long long dp[MAX_N*MAX_N+1];
int sum;

int main() {
	FASTIO();

	cin >> N >> M;

	for (int i = 1; i < N+1; i ++) {
		cin >> memory[i];
	}
	for (int i = 1; i < N+1; i ++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 1; i < N+1; i ++) {
		
		for (int j = sum; j >= cost[i]; j --) {
			dp[j] = max(dp[j], dp[j-cost[i]] + memory[i]);
		}
	}
	
	for (int i = 0; i <= sum; i ++) {
		if (dp[i] >= M) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}
