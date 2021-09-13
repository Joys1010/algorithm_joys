#include <iostream>
#include <string>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int map[251][251];
int visited[251][251];
int R, C;

int w_num;
int s_num;

void dfs(int y, int x);

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main() {
	FASTIO();
	
	cin >> R >> C;

	string tmp;
	int total_s_num = 0;
	int total_w_num = 0;

	for (int i = 0; i < R; i ++) {
		cin >> tmp;
		for (int j = 0; j < C; j ++) {
			if (tmp[j] == '#') {
				map[i+1][j+1] = 0;
			}
			else if (tmp[j] == '.') {
				map[i+1][j+1] = 1;
			}
			else if (tmp[j] == 'o') {
				total_s_num++;
				map[i+1][j+1] = 2;
			}
			else if (tmp[j] == 'v') {
				total_w_num++;
				map[i+1][j+1] = 3;
			}
		}
	}	

	for (int i = 1; i <= R; i ++) {
		for (int j = 1; j <= C; j ++) {
			if (visited[i][j] != 1 && map[i][j] != 0) {
				s_num = 0;
				w_num = 0;
				if (map[i][j] == 2) {
					s_num = 1;
				}
				else if (map[i][j] == 3) {
					w_num = 1;
				}
				visited[i][j] = 1;
				dfs(i, j);
				if (s_num > w_num) {
					total_w_num -= w_num;
				}
				else {
					if (w_num != 0) {
						total_s_num -= s_num;
					}
				}
			}
		}
	}

	if (total_s_num <= 0) {
		total_s_num = 0;
	}
	if (total_w_num <= 0) {
		total_w_num = 0;
	}

	cout << total_s_num << " " << total_w_num << "\n";

	return 0;
}

void dfs(int y, int x) {

	for (int i = 0; i < 4; i ++) {
		int now_x = x + dx[i];
		int now_y = y + dy[i];

		if (now_x >= 1 && now_x <= C && now_y >= 1 && now_y <= R) {
			if (visited[now_y][now_x] != 1 && map[now_y][now_x] != 0) {
				visited[now_y][now_x] = 1;
				if (map[now_y][now_x] == 2) {
					s_num++;
				}
				else if (map[now_y][now_x] == 3) {
					w_num++;
				}
				dfs(now_y, now_x);
			}
		}
	}
}


