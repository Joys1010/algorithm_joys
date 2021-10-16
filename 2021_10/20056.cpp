#include <iostream>
#include <vector>

using namespace std;

struct info {
	int _r;
	int _c;
	int _m;
	int _s;
	int _d;
};

vector <info> map[51][51];
vector <info> fireball_info;
int N, M, K;
int r, c, m, s, d;
int ans;

void move_fireball();
void after_move_fireball();

int main() {

	cin >> N >> M >> K;

	struct info ball;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		ball._r = r - 1;
		ball._c = c - 1;
		ball._m = m;
		ball._s = s;
		ball._d = d;

		fireball_info.push_back(ball);
		map[r - 1][c - 1].push_back(ball);
	}

	for (int i = 0; i < K; i++) { //명령

		move_fireball();
		after_move_fireball();
	}

	for (int i = 0; i < fireball_info.size(); i++) {
		ans += fireball_info[i]._m;
	}

	cout << ans << "\n";

	return 0;
}

void move_fireball() {

	//기존 맵 제거
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j].clear();
		}
	}
	int now_r, now_c, now_m, now_d, now_s;
	for (int j = 0; j < fireball_info.size(); j++) {
		now_r = fireball_info[j]._r;
		now_c = fireball_info[j]._c;
		now_m = fireball_info[j]._m;
		now_s = (fireball_info[j]._s) % N; //속력
		now_d = fireball_info[j]._d; //방향

		if (now_d == 0) {
			now_r = (now_r - now_s + N) % N;
			fireball_info[j]._r = now_r;
		}
		else if (now_d == 1) {
			now_r = (now_r - now_s + N) % N;
			now_c = (now_c + now_s + N) % N;
			fireball_info[j]._r = now_r;
			fireball_info[j]._c = now_c;
		}
		else if (now_d == 2) {
			now_c = (now_c + now_s + N) % N;
			fireball_info[j]._c = now_c;
		}
		else if (now_d == 3) {
			now_r = (now_r + now_s + N) % N;
			now_c = (now_c + now_s + N) % N;
			fireball_info[j]._r = now_r;
			fireball_info[j]._c = now_c;
		}
		else if (now_d == 4) {
			now_r = (now_r + now_s + N) % N;
			fireball_info[j]._r = now_r;
		}
		else if (now_d == 5) {
			now_r = (now_r + now_s + N) % N;
			now_c = (now_c - now_s + N) % N;
			fireball_info[j]._r = now_r;
			fireball_info[j]._c = now_c;
		}
		else if (now_d == 6) {
			now_c = (now_c - now_s + N) % N;
			fireball_info[j]._c = now_c;
		}
		else if (now_d == 7) {
			now_r = (now_r - now_s + N) % N;
			now_c = (now_c - now_s + N) % N;
			fireball_info[j]._r = now_r;
			fireball_info[j]._c = now_c;
		}
		map[now_r][now_c].push_back(fireball_info[j]);
	}//이동 종료
}

void after_move_fireball() {

	struct info ball;
	vector <info> new_fireball_info;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map[i][j].size() == 0) continue;
			else if (map[i][j].size() == 1) {
				new_fireball_info.push_back(map[i][j][0]);
			}
			else { //여러 개의 공
				int weight = 0;
				int speed = 0;
				int direction_flg = -1;
				int cnt = map[i][j].size();
				for (int k = 0; k < cnt; k++) {
					weight += map[i][j][k]._m;
					speed += map[i][j][k]._s;
					if (direction_flg == -1) { //첫공 
						if (map[i][j][k]._d % 2 == 1) { //홀
							direction_flg = 0;
						}
						else { //짝
							direction_flg = 1;
						}
					}
					else {
						if (direction_flg == 0) {
							if (map[i][j][k]._d % 2 == 0) {
								direction_flg = 2;
							}
						}
						else if (direction_flg == 1) {
							if (map[i][j][k]._d % 2 == 1) {
								direction_flg = 2;
							}
						}
						else { //이미 홀짝 반전이 있었음
							//nothing happen
						}
					}	
				}
				weight /= 5;
				speed /= cnt;

				int direction[4];
				if (direction_flg == 0 || direction_flg == 1) {
					direction[0] =  0;
					direction[1] = 2;
					direction[2] = 4;
					direction[3] = 6;
				}
				else {
					direction[0] = 1;
					direction[1] = 3;
					direction[2] = 5;
					direction[3] = 7;
				}

				if (weight != 0) {

					for (int k = 0; k < 4; k++) {
						ball._r = i;
						ball._c = j;
						ball._m = weight;
						ball._s = speed;
						ball._d = direction[k];

						new_fireball_info.push_back(ball);
					}
				}
			}
		}
	}
	fireball_info = new_fireball_info;
}
