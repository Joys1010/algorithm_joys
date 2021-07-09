#include <iostream>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int numbers[1001];
int dp[2][1001];
int maximum;

void solve_dp_first(int x) {

	for (int i=0;i<x;i++) {
		if (numbers[x] > numbers[i] && dp[0][i] + 1 > dp[0][x]) {
			dp[0][x] = 1 + dp[0][i];
		}
	}
}

void solve_dp_second(int x) {

	for (int i=0;i<N-1-x;i++) {
		if (numbers[x] > numbers[N-1-i] && dp[1][N-1-i] + 1 > dp[1][x]) {
			dp[1][x] = 1 + dp[1][N-1-i];
		}
	}

}
void find_max() {

	for (int i=0;i<N;i++) {
		maximum = max(maximum, dp[0][i] + dp[1][i] - 1);
	}
	
}
int main() {

	cin >> N;

	for (int i=0;i<N;i++) {
		cin >> numbers[i];
		dp[0][i] = 1;
		dp[1][i] = 1;
	}

	for (int i=1;i<N;i++) {
		solve_dp_first(i);
	}
	for (int i=N-1;i>-1;i--) {
		solve_dp_second(i);
	}
	find_max();
	cout << maximum << "\n";
	return 0;
}

