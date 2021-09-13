#include <iostream>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int map[101][101];
int visited[101][101];
int N, M, K;
int r, c;

int cnt, ans;

void dfs(int y, int x);

int main() {
	FASTIO();

	cin >> N >> M >> K;

	for (int i = 0; i < K; i ++) {
		cin >> r >> c;

		map[r][c] = 1;
	}

	for (int i = 1; i <= N; i ++) {
		for (int j = 1; j <= M; j ++) {
			if (visited[i][j] != 1 && map[i][j] == 1) {
				cnt = 1;
				visited[i][j] = 1;
				dfs(i, j);
				if (cnt >= ans) {
					ans = cnt;
				}
			}
		}
	}

	cout << ans << "\n";
	return 0;
}

int dx[4] = { -1, 1, 0, 0}; 
int dy[4] = { 0, 0, -1, 1};

void dfs(int y, int x) {

	for (int i = 0; i < 4; i ++) {
		int now_x = x + dx[i];
		int now_y = y + dy[i];

		if (now_x >= 1 && now_x <= M && now_y >= 1 && now_y <= N) {
			if (visited[now_y][now_x] != 1 && map[now_y][now_x] == 1) {
				visited[now_y][now_x] = 1;
				cnt++;
				dfs(now_y, now_x);
			}
		}
	}

}
