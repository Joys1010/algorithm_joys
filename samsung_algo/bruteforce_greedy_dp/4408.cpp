#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int s, e;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int hallway[201];
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		int overlap = 0;
		int cnt = 0;
		vector <pair<int, int>> ways;

		for (int i = 0; i < 201; i++) {
			hallway[i] = 0;
		}


		for (int i = 0; i < N; i++) {
			cin >> s >> e;
			if (e > s) {
				ways.push_back({ s,e });
			}
			else {
				ways.push_back({ e,s });
			}
		}

		sort(ways.begin(), ways.end());

		for (int i = 0; i < N; i++) {
			int st = ways[i].first;
			int en = ways[i].second;
			
			if (st % 2 != 1) {
				st--;
			}
			if (en % 2 != 1) {
				en--;
			}

			for (int j = st / 2; j < en / 2 + 1; j++) {
				hallway[j]++;
			}
		}
		cnt = hallway[0];
		for (int i = 1; i < 201; i++) {
			if (cnt < hallway[i]) {
				cnt = hallway[i];
			}
		}

		cout << "#" << test_case << " " << cnt << "\n";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
