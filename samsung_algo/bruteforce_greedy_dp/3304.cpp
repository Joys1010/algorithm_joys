#include<iostream>
#include<algorithm>

using namespace std;

char first_string[1001];
char second_string[1001];

int dp[1001][1001];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
	
		cin >> first_string >> second_string;

		int i = 0;
		int j = 0;
		int maxi = 0;
		
		while (second_string[i] != '\0') {
			while (first_string[j] != '\0') {
				if (second_string[i] == first_string[j]) {
					dp[i+1][j+1] = dp[i][j] + 1;
				}
				else {
					dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
				}
				if (maxi < dp[i + 1][j + 1]) {
					maxi = dp[i + 1][j + 1];
				}
				j++;
			}
			i++;
			j = 0;
		}
		cout << "#" << test_case << " " << maxi << "\n";

	
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
