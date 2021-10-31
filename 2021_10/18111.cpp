#include <iostream>
#include <array>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, B;
int num;
int mini_time = 100000000;
int height;
int mini = 100000000;
int maxi;
set <int> h;
vector <int> board;

bool cmp(int a, int b) {
	return a > b;
}

int main() {

	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			mini = min(mini, num);
			maxi = max(maxi, num);
			board.push_back(num);
			h.insert(num);
		}
	}
	
	sort(board.begin(), board.end(), cmp);
	
	for (int i = mini ; i <= maxi; i++) {
		int tmp_h = i;
		int tmp_b = B;
		int time = 0;
		bool flg = true;

		for (int i = 0; i < board.size(); i++) {
			if (tmp_h == board[i]) continue;
			else if (tmp_h < board[i]) { //지금 보고있는 칸이 더 높음
				tmp_b += (board[i] - tmp_h);
				time += 2 * (board[i] - tmp_h);
			}
			else { //tmp_h > board[i] //지금 보고 있는 칸이 더 낮음
				if (tmp_b >= (tmp_h - board[i])) {
					tmp_b -= (tmp_h - board[i]);
					time += (tmp_h - board[i]);
				}
				else {
					flg = false;
					break;
				}
			}
		}
		if (flg) {
			if (mini_time > time) {
				mini_time = time;
				height = tmp_h;
			}
			else if (mini_time == time) {
				if (height < tmp_h) {
					height = tmp_h;
				}
			}
		}
	}

	cout << mini_time << " " << height << "\n";
	return 0;
}

