#include<iostream>
#include<algorithm>

using namespace std;

int dp[101][1001];
int v[101];
int c[101];
int N, K;
int result;

int solve();

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> v[i] >> c[i];
		}
	
		result = solve();

		cout << "#" << test_case << " " << result << "\n";

		//다음 테스트케이스를 위한 초기화
		for (int i = 0; i < N; i++) {
			v[i] = 0;
			c[i] = 0;
		}
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 1001; j++) {
				dp[i][j] = 0;
			}
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int solve() {
	
	int ans = 0;

	for (int i = 1; i <= N; i++) { //물건 갯수
		for (int j = 1; j <= K; j++) { //물건 무게
			if (v[i - 1] <= j) {
				dp[i][j] = max(c[i - 1] + dp[i - 1][j - v[i - 1]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			if (ans < dp[i][j]) {
				ans = dp[i][j];
			}
		}
	}
	return ans;
}
