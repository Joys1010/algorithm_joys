#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N, Q;
int n;


int map[64][64];

int level;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };

void rotate_ice();
void calculate_ice();
int find_big_ice(int y_pos, int x_pos);



int main() {

	cin >> N >> Q;

	n = pow(2, N);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {
		cin >> level;
		if (level > 0) {
			rotate_ice();
		}
		calculate_ice();
	}

	int sum = 0;
	int ans = 0;
	int maxi = 0;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (map[i][j] > 0) {
				sum += map[i][j];
				ans = find_big_ice(i, j);
				maxi = max(ans, maxi);
			}
		}
	}
	cout << sum << "\n" << maxi << "\n";

	return 0;
}

void rotate_ice() {

	int tmp[64][64] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = map[i][j];
		}
	}

	for (int r = 0; r < n; r += pow(2, level)) {
		for (int c = 0; c < n; c += pow(2, level)) {
			
			int idx_r = r + pow(2, level) - 1;
			
			for (int i = 0; i < pow(2, level); i++) {
				for (int j = 0; j < pow(2, level); j++) {
					map[r + i][c + j] = tmp[idx_r - j][c + i];
				}
			}

		}
	}
}

void calculate_ice() {

	bool new_map[64][64] = { false, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int now_x = j + dx[k];
				int now_y = i + dy[k];
				
				if (now_x > -1 && now_x < n && now_y > -1 && now_y < n && map[now_y][now_x] > 0) {
					cnt++;
				}
			}

			if (cnt < 3) {
				new_map[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (new_map[i][j] == true) {
				map[i][j] -= 1;
			}
		}
	}
}

int find_big_ice(int y_pos, int x_pos) {

	queue<pair<int, int>> q;
	bool visited[64][64] = { false, };

	q.push({ y_pos, x_pos });
	visited[y_pos][x_pos] = true;

	int count = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		if (map[y][x] < 1) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int now_y = y + dy[i];
			int now_x = x + dx[i];

			if (now_y > -1 && now_y < n && now_x > -1 && now_x < n) {
				if (map[now_y][now_x] > 0 && visited[now_y][now_x] == false) {
					visited[now_y][now_x] = true;
					count++;
					q.push({ now_y, now_x });
				}
			}
		}
	}
	return count;
}
