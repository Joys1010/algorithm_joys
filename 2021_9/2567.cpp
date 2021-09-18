#include <iostream>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

bool white_paper[101][101];
int cnt;
int x, y;
int answer = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void add_paper(int x_pos, int y_pos) {

	for (int i = y_pos; i < y_pos+10; i ++) {
		for (int j = x_pos; j < x_pos+10; j ++) {
			white_paper[i][j] = true;
		}	
	}
}	
int main() {
	FASTIO();

	cin >> cnt;

	for (int i = 0; i < cnt; i ++) {
		cin >> x >> y;
		add_paper(x, y);
	}


	for (int i = 1; i <= 100; i ++) {
		for (int j = 1; j <= 100; j ++) {
			if (white_paper[i][j] == true) {
				for (int k = 0; k < 4; k ++) {
					int now_y = i + dy[k];
					int now_x = j + dx[k];

					if (white_paper[now_y][now_x] == 0) {
						answer++;
					}
				}
			}
		}
	}

	cout << answer << "\n";


	return 0;
}
