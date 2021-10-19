#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

array<array<int,50>, 50> map;

int N, M;
int one_answer;
int two_answer;
int three_answer;
bool flg;
int shark_x, shark_y;
int direction, speed;

int start_x, start_y;
int target_x, target_y;
int direction_idx;


queue<pair<int, int>> empty_space;
queue<pair<int, int>> conti;

//위 아래 왼 오
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int tor_dy[4] = { 0, 1, 0, -1 };
int tor_dx[4] = { -1, 0, 1, 0 };



void throw_ice();
void move();
void explode();
void transform();


void q1_clear() {

	queue<pair<int, int>> new_empty_space;
	empty_space = new_empty_space;
}
void q2_clear() {
	queue<pair<int, int>> new_conti;
	conti = new_conti;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	shark_x = N / 2;
	shark_y = N / 2;

	for (int i = 0; i < M; i++) {
		cin >> direction >> speed;
		direction = direction - 1;
		throw_ice();
		move();
		q1_clear();
		
		while (true) {
			q1_clear();
			q2_clear();
			explode();
			if (flg == false) { //폭발시키지 않았으면
				break;
			}
			flg = false;
			move();

		}
		q1_clear();
		q2_clear();

		transform();
	}
	
	int ans = one_answer + 2 * two_answer + 3 * three_answer;
	cout << ans << "\n";

	return 0;
}

void throw_ice() {
	
	speed = speed % N;
	int until_x = shark_x + dx[direction] * speed;	
	int until_y = shark_y + dy[direction] * speed;

	//왼 오 이동
	if (until_x != shark_x) {
		if (until_x < shark_x) { //왼
			if (until_x < 0) {
				until_x = 0;
			}
			for (int i = until_x; i < shark_x; i++) {
				map[shark_y][i] = 0;
			}
 		}
		else { //오
			if (until_x > N - 1) {
				until_x = N - 1;
			}
			for (int i = shark_x + 1; i <= until_x; i++) {
				map[shark_y][i] = 0;
			}
		}
	}
	
	//위 아래 이동
	if (until_y != shark_y) {
		if (until_y < shark_y) { //위 이동
			if (until_y < 0) {
				until_y = 0;
			}
			for (int i = until_y; i <= shark_y; i++) {
				map[i][shark_x] = 0;
			}
		}
		else { //아래 이동
			if (until_y > N - 1) {
				until_y = N - 1;
			}
			for (int i = shark_y + 1; i <= until_y; i++) {
				map[i][shark_x] = 0;
			}
		}
	}
};


void move() {
	int move_cnt = 1;
	int flag = 0;

	start_x = shark_x;
	start_y = shark_y;
	direction_idx = 0;

	while (move_cnt != N) {

		flag++;
		for (int i = 0; i < move_cnt; i++) {
			//real_move
			target_x = start_x + tor_dx[direction_idx];
			target_y = start_y + tor_dy[direction_idx];

			if (map[target_y][target_x] == 0) {
				empty_space.push({ target_y, target_x });
			}
			else {
				if (!empty_space.empty()) {

					int pos_x = empty_space.front().second;
					int pos_y = empty_space.front().first;
					empty_space.pop();

					map[pos_y][pos_x] = map[target_y][target_x];

					map[target_y][target_x] = 0;
					empty_space.push({ target_y, target_x });
				}
			}

			start_x = target_x;
			start_y = target_y;
		}

		if (flag % 2 == 0) {
			flag = 0;
			move_cnt++;
		}
		direction_idx = (direction_idx + 1) % 4;
	}
	for (int i = 0; i < move_cnt - 1; i++) {
		//real_move
		target_x = start_x + tor_dx[direction_idx];
		target_y = start_y + tor_dy[direction_idx];

		if (map[target_y][target_x] == 0) {
			empty_space.push({ target_y, target_x });
		}
		else {
			if (!empty_space.empty()) {

				int pos_x = empty_space.front().second;
				int pos_y = empty_space.front().first;
				empty_space.pop();

				map[pos_y][pos_x] = map[target_y][target_x];

				map[target_y][target_x] = 0;
				empty_space.push({ target_y, target_x });
			}
		}

		start_x = target_x;
		start_y = target_y;
	}
}

void explode() {

	int old_value_explode = -1;
	int continue_cnt = 0;
	
	//상어 위치부터 search 하면서
	int move_cnt = 1;
	int flag = 0;

	start_x = shark_x;
	start_y = shark_y;
	direction_idx = 0;
	
	while (move_cnt != N) {

		flag++;
		for (int i = 0; i < move_cnt; i++) {
			target_x = start_x + tor_dx[direction_idx];
			target_y = start_y + tor_dy[direction_idx];

			if (old_value_explode == -1) { //상어 왼쪽의 첫 값
				old_value_explode = map[target_y][target_x];
				continue_cnt++;
				conti.push({ target_y, target_x });
			}

			else {
				if (map[target_y][target_x] != old_value_explode) { //연속이 깨졌고

					if (continue_cnt >= 4) { //연속 구슬 폭파시키기
						//폭파 로직...... 별로야
						for (int j = 0; j < continue_cnt; j++) {
							int b_y = conti.front().first;
							int b_x = conti.front().second;

							map[b_y][b_x] = 0;
							conti.pop();
						}
						if (old_value_explode == 1) {
							one_answer += continue_cnt;
						}
						else if (old_value_explode == 2) {
							two_answer += continue_cnt;
						}
						else if (old_value_explode == 3) {
							three_answer += continue_cnt;
						}
						flg = true;
					}

					old_value_explode = map[target_y][target_x]; //연속 깨진 값으로 변경
					continue_cnt = 1;
					q2_clear();
					conti.push({ target_y, target_x });
				}
				else {
					continue_cnt++;
					conti.push({ target_y, target_x });
				}
			}
			start_x = target_x;
			start_y = target_y;
		}

		if (flag % 2 == 0) {
			flag = 0;
			move_cnt++;
		}
		direction_idx = (direction_idx + 1) % 4;
	}
	for (int i = 0; i < move_cnt - 1; i++) {
		target_x = start_x + tor_dx[direction_idx];
		target_y = start_y + tor_dy[direction_idx];

		if (old_value_explode == -1) { //상어 왼쪽의 첫 값
			old_value_explode = map[target_y][target_x];
			continue_cnt++;
			conti.push({ target_y, target_x });
		}

		else {
			if (map[target_y][target_x] != old_value_explode) { //연속이 깨졌고

				if (continue_cnt >= 4) { //연속 구슬 폭파시키기
					//폭파 로직...... 별로야
					for (int j = 0; j < continue_cnt; j++) {
						int b_y = conti.front().first;
						int b_x = conti.front().second;

						map[b_y][b_x] = 0;
						conti.pop();
					}
					if (old_value_explode == 1) {
						one_answer += continue_cnt;
					}
					else if (old_value_explode == 2) {
						two_answer += continue_cnt;
					}
					else if (old_value_explode == 3) {
						three_answer += continue_cnt;
					}
					flg = true;
				}

				old_value_explode = map[target_y][target_x]; //연속 깨진 값으로 변경
				continue_cnt = 1;
				q2_clear();
				conti.push({ target_y, target_x });
			}
			else {
				continue_cnt++;
				conti.push({ target_y, target_x });
			}
		}
		start_x = target_x;
		start_y = target_y;
	}

}

void transform() {
	//상어 위치부터 search 하면서

	vector <int> new_info;
	
	int move_cnt = 1;
	int flag = 0;
	int old_value = -1;
	int continue_cnt = 0;

	start_x = shark_x;
	start_y = shark_y;
	direction_idx = 0;

	while (move_cnt != N) {

		flag++;
		for (int i = 0; i < move_cnt; i++) {
	
			target_x = start_x + tor_dx[direction_idx];
			target_y = start_y + tor_dy[direction_idx];

			if (old_value == -1) { //상어 왼쪽의 첫 값
				old_value = map[target_y][target_x];
				continue_cnt = 1;
			}
			else {
				if (old_value != map[target_y][target_x]) {
					new_info.push_back(continue_cnt);
					new_info.push_back(old_value);

					continue_cnt = 1;
					old_value = map[target_y][target_x];
				}
				else {
					continue_cnt++;
				}
			}
			start_x = target_x;
			start_y = target_y;
		}

		if (flag % 2 == 0) {
			flag = 0;
			move_cnt++;
		}
		direction_idx = (direction_idx + 1) % 4;
	}

	for (int i = 0; i < move_cnt - 1; i++) {
		target_x = start_x + tor_dx[direction_idx];
		target_y = start_y + tor_dy[direction_idx];

		if (old_value == -1) { //상어 왼쪽의 첫 값
			old_value = map[target_y][target_x];
			continue_cnt = 1;
		}
		else {
			if (old_value != map[target_y][target_x]) {
				new_info.push_back(continue_cnt);
				new_info.push_back(old_value);

				continue_cnt = 1;
				old_value = map[target_y][target_x];
			}
			else {
				continue_cnt++;
			}
		}
		start_x = target_x;
		start_y = target_y;
	}

	array<array<int, 50>, 50> new_map = { 0, };

	move_cnt = 1;
	flag = 0;
	
	start_x = shark_x;
	start_y = shark_y;
	direction_idx = 0;
	
	int vector_idx = 0;
	int end_flag = 0;

	while (move_cnt != N) {

		flag++;
		for (int i = 0; i < move_cnt; i++) {

			target_x = start_x + tor_dx[direction_idx];
			target_y = start_y + tor_dy[direction_idx];
			
			if (vector_idx < new_info.size()) {
				new_map[target_y][target_x] = new_info[vector_idx];
				vector_idx++;
			}
			else {
				end_flag = true;
				break;
			}
			start_x = target_x;
			start_y = target_y;
		}
		if (end_flag == true) {
			break;
		}
		if (flag % 2 == 0) {
			flag = 0;
			move_cnt++;
		}
		direction_idx = (direction_idx + 1) % 4;
	}
	if (end_flag == true) {
		map = new_map;
		return;
	}

	for (int i = 0; i < move_cnt - 1; i++) {
		target_x = start_x + tor_dx[direction_idx];
		target_y = start_y + tor_dy[direction_idx];

		if (vector_idx < new_info.size()) {
			new_map[target_y][target_x] = new_info[vector_idx];
			vector_idx++;
		}
		else {
			end_flag = true;
			start_x = target_x;
			start_y = target_y;
			break;
		}
		start_x = target_x;
		start_y = target_y;
	}
	map = new_map;
	return;
}

