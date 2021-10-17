#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int map[20][20];

int N, M;
int answer;
int standard_x;
int standard_y;

int block_group();
void delete_and_add();
void gravity();
void rotate();

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };

struct info {
	int y;
	int x;
	int cnt;
	int rainbow_cnt;
	vector <pair<int, int>> blocks;
};

vector <info> information;

bool cmp(info a, info b) {

	if (a.cnt == b.cnt) {
		if (a.rainbow_cnt == b.rainbow_cnt) {
			if (a.y == b.y) {
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.rainbow_cnt > b.rainbow_cnt;
	}
	return a.cnt > b.cnt;
}



int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int flg = 0;

	while (true) {
		flg = block_group();
		if (flg == 0) break;
		delete_and_add();
		gravity();
		for (int i = 0; i < 3; i++) {
			rotate();
		}
		gravity();
	}
	cout << answer << "\n";
	return 0;
}

int block_group() {

	bool visited[20][20] = { false, };

	int flag = 0;

	information.clear();

	for (int i = 0; i < N; i++) {
		vector <pair<int, int>> rainbow_pos;
		for (int j = 0; j < N; j++) {
			vector <pair<int, int>> blocks;
			if (visited[i][j] == false && map[i][j] != -1 && map[i][j] != 0 && map[i][j] != -3) { //검은색 블록과 무지개 블록은 기준 블록이 될 수 없음

				//bfs
				queue <pair<int, int>> q;
				q.push({ i,j }); //기준블록
				visited[i][j] = true;
				blocks.push_back({ i,j });

				int value = map[i][j];
				int size = 1;
				int rainbow_cnt = 0;


				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;

					q.pop();

					for (int k = 0; k < 4; k++) {
						int now_y = y + dy[k];
						int now_x = x + dx[k];

						if (now_y < 0 || now_y > N - 1 || now_x < 0 || now_x > N - 1) { //out of range
							continue;
						}
						else {
							if (visited[now_y][now_x] == false) { //방문한적 없고
								if (map[now_y][now_x] == value || map[now_y][now_x] == 0) { //조건에 맞을 때
									visited[now_y][now_x] = true;
									size++;
									if (map[now_y][now_x] == 0) {
										rainbow_cnt++;
										rainbow_pos.push_back({ now_y, now_x });
									}
									q.push({ now_y, now_x });
									blocks.push_back({ now_y, now_x });
								}
							}
						}
					}
				}
				information.push_back({ i, j, size, rainbow_cnt, blocks });
				for (int k = 0; k < rainbow_pos.size(); k++) {
					visited[rainbow_pos[k].first][rainbow_pos[k].second] = false;
				}
			}
		}

	}

	sort(information.begin(), information.end(), cmp);

	if (information.size() != 0) {
		if (information[0].cnt > 1) {
			standard_y = information[0].y;
			standard_x = information[0].x;
			flag = 1;
		}
	}
	return flag;
}

void delete_and_add() {

	int y = standard_y;
	int x = standard_x;
	int cnt = 0;
	vector <pair<int, int>> target;

	for (int i = 0; i < information.size(); i++) {
		if (y == information[i].y && x == information[i].x) {
			target = information[i].blocks;
			cnt = information[i].cnt;
		}
	}

	for (int i = 0; i < target.size(); i++) {
		int now_y = target[i].first;
		int now_x = target[i].second;

		map[now_y][now_x] = -3;
	}

	answer += (cnt * cnt);
}

void gravity() {

	//같은 column의 -3 갯수와 위치 확인. 아래부터

	int cnt = 0;

	for (int i = 0; i < N; i++) { //col을 이동한다 (세로 첫줄부터 마지막줄까지 이동)
		queue <int> move_space;
		for (int j = N - 1; j > -1; j--) { //세로줄에서 아래서부터 올라옴
			if (map[j][i] == -3) { //빈공간이면
				cnt++;
				move_space.push(j);
			}
			else if (map[j][i] == -1) { //검은색 블록이면 큐 비우기
				while (!move_space.empty()) {
					move_space.pop();
				}
			}
			else {
				if (move_space.size() != 0) { //빈 공간이 있으면
					int moving = move_space.front(); //가장 아래의 빈 공간의 정보 가져오기
					move_space.pop(); //정보 없애기
					map[moving][i] = map[j][i]; //가장 아래 빈 공간에 지금 값 채우기
					map[j][i] = -3; //옮겼으니까 현재 위치 빈 공간 처리
					move_space.push(j); //비었으니 빈 공간 큐에 넣기
				}
			}
		}
	}
}

void rotate() {

	int tmp[20][20] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp[N - 1 - j][i];
		}
	}
}
