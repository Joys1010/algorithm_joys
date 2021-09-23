#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, P;
int line_num;
int flat;
int min_move;

int main() {
	FASTIO();

	cin >> N >> P;

	stack <int> s[6];
	vector <pair<int, int>> melody;

	for (int i = 0; i < N; i++) {
		cin >> line_num >> flat;
		melody.push_back({ line_num, flat });
	}

	for (int i = 0; i < N; i++) {
		pair <int, int> tmp = melody[i];

		if (s[tmp.first - 1].empty()) { //해당 줄 번호의 스택이 비어있으면
			s[tmp.first - 1].push(tmp.second);
			min_move++;
		}
		else {

			while (!s[tmp.first - 1].empty() && s[tmp.first - 1].top() > tmp.second) {
				s[tmp.first - 1].pop();
				min_move++;
			}
			if (!s[tmp.first - 1].empty() && s[tmp.first - 1].top() == tmp.second) {
				continue;
			}

			s[tmp.first - 1].push(tmp.second);
			min_move++;
		}
	}

	cout << min_move << "\n";

	return 0;
}
