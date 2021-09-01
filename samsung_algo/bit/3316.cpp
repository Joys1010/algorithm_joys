#include<iostream>
#include <string>
#define MAX_N 10010

using namespace std;

int dp[MAX_N][16];
string days;
int result;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> days;

		int N = days.size();
		int response;

		for (int i = 0; i < N; i++) { //날을 옮기는 for문
			response = 1 << ((days[i] - 'A'));

			if (i == 0) {
				for (int j = 1; j < 16; j++) {

					if ((response & j) == response && (j & 1) != 0) {
						dp[i][j] = 1;
					}
				}
			}
			else {
				for (int j = 1; j < 16; j++) { //바로 윗줄에 0이 아닌지를 판단해서 넘기는 for문
					if (dp[i - 1][j] != 0) {
						for (int k = 1; k < 16; k++) {
							if ((response & k) == response && (j & k) != 0) {
								dp[i][k] = (dp[i - 1][j] + dp[i][k]) % 1000000007;
							}
						}
					}
				}
			}
		}
		
		for (int i = 1; i < 16; i++) {
			result = (result + dp[N - 1][i]) % 1000000007;
		}
		cout << "#" << test_case << " " << result << "\n";

		//다음 테스트케이스를 위한 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 16; j++) {
				dp[i][j] = 0;
			}
		}
		result = 0;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
