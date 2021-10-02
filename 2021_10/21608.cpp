#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_N 21

int N;
//1부터 N까지
int seat[MAX_N][MAX_N]; //(x, y)에 누가 앉아 있는지
int visited[MAX_N*MAX_N]; //index번째 친구가 앉아 있는지
pair<int, int> where[MAX_N*MAX_N]; //index번째 친구가 각각 어떤 자리에 앉아있는지

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool cmp(pair <int, int> a, pair <int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int information[MAX_N*MAX_N][4];

int main() {

	int student_number = 0;
	int student;

	cin >> N;

	student_number = N * N;

	while (student_number > 0) {

		student_number--;
		int like_info[4];

		cin >> student >> like_info[0] >> like_info[1] >> like_info[2] >> like_info[3];

		for (int i = 0; i < 4; i++) {
			information[student][i] = like_info[i];
		}

		if (student_number == N * N - 1) { //first iter인 경우
			where[student] = { 2, 2 };
			visited[student] = 1;
			seat[2][2] = student;
			continue;
		}
		else {
			if (visited[like_info[0]] == 1 || visited[like_info[1]] == 1 || visited[like_info[2]] == 1 || visited[like_info[3]] == 1) { //좋아하는 친구가 이미 어딘가에 앉아있을때 (한명이라도)
				//각 친구의 인접 자리 vector에 푸시
				vector <pair<int, int>> near_seat;

				for (int i = 0; i < 4; i++) { // 좋아하는 친구들의 인접 빈 자리의 리스트 만들기
					if (visited[like_info[i]] == 1) {
						for (int j = 0; j < 4; j++) {
							int now_x;
							int now_y;
							now_x = where[like_info[i]].first + dx[j];
							now_y = where[like_info[i]].second + dy[j];

							if (now_x > 0 && now_x < N + 1 && now_y > 0 && now_y < N + 1 && seat[now_x][now_y] == 0) {
								near_seat.push_back({ now_x, now_y });
							}
						}
					}
				}

				if (near_seat.size() == 0) {
					int flg = 0;
					for (int n = 4; n > -1; n--) { //4, 3, 2, 1, 0
						for (int i = 1; i < N + 1; i++) {
							for (int j = 1; j < N + 1; j++) { //판 처음부터 돌면서
								int cnt = 0;

								for (int k = 0; k < 4; k++) {
									int now_x = i + dx[k];
									int now_y = j + dy[k];

									if (now_x > 0 && now_x < N + 1 && now_y > 0 && now_y < N + 1) {
										if (seat[now_x][now_y] == 0) {
											cnt++;
										}
									}
								}

								if (cnt == n && seat[i][j] == 0) {
									where[student] = { i,j };
									visited[student] = 1;
									seat[i][j] = student;
									flg = 1;
									break;
								}
							}
							if (flg == 1) {
								break;
							}
						}
						if (flg == 1) {
							break;
						}
					}
				}
				else {
					//빈자리의 리스트 돌면서 주변에 좋아하는 친구 몇명인지 계산하기
					vector <int> how_many(near_seat.size());
					int max_num = 0;
					for (int i = 0; i < near_seat.size(); i++) {

						for (int j = 0; j < 4; j++) { //좋아하는 친구들의 정보가 지금 4방향 중 하나랑 일치
							int check_x = near_seat[i].first + dx[j];
							int check_y = near_seat[i].second + dy[j];

							for (int k = 0; k < 4; k++) {
								if (check_x > 0 && check_x < N + 1 && check_y > 0 && check_y < N + 1 && check_x == where[like_info[k]].first && check_y == where[like_info[k]].second) {
									how_many[i]++;
								}
								if (max_num < how_many[i]) {
									max_num = how_many[i];
								}
							}
						}
					}

					vector <pair<int, int>> candi;
					for (int i = 0; i < how_many.size(); i++) {
						if (how_many[i] == max_num) { //1번 조건 : 좋아하는 학생이 인접한 칸에 가장 많은 칸을 잡은것
							candi.push_back(near_seat[i]);
						}
					}

					if (candi.size() == 1) { //1번 조건에 해당하는게 하나인 것
						where[student] = { candi[0] };
						visited[student] = 1;
						seat[candi[0].first][candi[0].second] = student;
						continue;
					}
					else if (candi.size() > 1) { //2번 조건 : 1번이 여러개이면 인접 칸 중 빈 칸이 가장 많은 
						vector <int> candi_free(candi.size());
						int max_free = 0;
						for (int i = 0; i < candi.size(); i++) {
							for (int j = 0; j < 4; j++) {
								int now_x = candi[i].first + dx[j]; //x좌표
								int now_y = candi[i].second + dy[j]; //y좌표

								if (now_x > 0 && now_x < N + 1 && now_y > 0 && now_y < N + 1 && seat[now_x][now_y] == 0) {
									candi_free[i]++;
								}
							}
							if (max_free < candi_free[i]) {
								max_free = candi_free[i];
							}
						}

						vector <pair<int, int>> free_many;
						for (int i = 0; i < candi_free.size(); i++) {
							if (max_free == candi_free[i]) {
								free_many.push_back(candi[i]);
							}
						}

						if (free_many.size() == 1) { //2번 조건에 해당하는게 하나인 것
							where[student] = { free_many[0] };
							visited[student] = 1;
							seat[free_many[0].first][free_many[0].second] = student;
							continue;
						}

						else if (free_many.size() > 1) { //3번 조건 : 2번도 여러개이면 r, c 작은 거
							sort(free_many.begin(), free_many.end(), cmp);
							where[student] = { free_many[0] };
							visited[student] = 1;
							seat[free_many[0].first][free_many[0].second] = student;
							continue;
						}
					}
				}
			}


			else { //한 명도 안 앉아있을때는 row, col이 작은, 인접 칸이 제일 많은 곳에 앉히기
				int flg = 0;
				for (int n = 4; n > -1; n--) { //4, 3, 2, 1, 0
					for (int i = 1; i < N + 1; i++) {
						for (int j = 1; j < N + 1; j++) { //판 처음부터 돌면서
							int cnt = 0;

							for (int k = 0; k < 4; k++) {
								int now_x = i + dx[k];
								int now_y = j + dy[k];

								if (now_x > 0 && now_x < N + 1 && now_y > 0 && now_y < N + 1) {
									if (seat[now_x][now_y] == 0) {
										cnt++;
									}
								}
							}

							if (cnt == n && seat[i][j] == 0) {
								where[student] = { i,j };
								visited[student] = 1;
								seat[i][j] = student;
								flg = 1;
								break;
							}
						}
						if (flg == 1) {
							break;
						}
					}
					if (flg == 1) {
						break;
					}
				}
			}
		}
	}

	int score = 0;


	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			int friends = 0;
			vector <int> tmp;
			for (int k = 0; k < 4; k++) {
				tmp.push_back(information[seat[i][j]][k]);
			}

			for (int k = 0; k < 4; k++) {

				int now_x = i + dx[k];
				int now_y = j + dy[k];


				if (now_x > 0 && now_x < N + 1 && now_y > 0 && now_y < N + 1) { //범위 안에

					auto it = find(tmp.begin(), tmp.end(), seat[now_x][now_y]);
					if (it != tmp.end()) {
						friends++;
					}
				}
			}
			if (friends == 4) {
				score += 1000;
			}
			else if (friends == 3) {
				score += 100;
			}
			else if (friends == 2) {
				score += 10;
			}
			else if (friends == 1) {
				score += 1;
			}
		}
	}
	cout << score << "\n";

	return 0;
}
