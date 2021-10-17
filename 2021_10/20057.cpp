#include <iostream>
#include <vector>


using namespace std;

int map[500][500];

int N;

//왼 아래 오 위

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

int direction_idx;

int start_x;
int start_y;
int target_x;
int target_y;
int target_sand;
int answer;
void move();
void fly_sand();

void print() {
	cout << "-------------------\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	start_y = N / 2;
	start_x = N / 2;

	move();

	return 0;
}

void move() {

	//토네이도 cnt 칸 이동
	int move = 1;
	int cnt = 0;
	direction_idx = 0;
	while (true) {


		cnt++;
		for (int i = 0; i < move; i++) {
			fly_sand();
		}
		
		if (cnt == 2) {
			cnt = 0;
			move++;
		}

		direction_idx = (direction_idx + 1) % 4;
		if (move == N) {
			break;
		}
	}
	for (int i = 0; i < move-1 ; i++) {
		fly_sand();

	}
	cout << answer << "\n";

}
void fly_sand() {

	target_x = start_x + dx[direction_idx];
	target_y = start_y + dy[direction_idx];
	target_sand = map[target_y][target_x];
	map[target_y][target_x] = 0;

	int five = target_sand * 0.05;
	int ten = target_sand * 0.1;
	int seven = target_sand * 0.07;
	int two = target_sand * 0.02;
	int one = target_sand * 0.01;

	int alpha = target_sand - five - 2 * ten - 2 * seven - 2 * two - 2 * one;

	//alpha, five, ten up, ten down, two up, two down, seven up, seven down, one up, one down
	int cal_x[10] = { -2, -3, -2, -2, -1, -1, -1, -1, 0, 0};
	int cal_y[10] = { 0, 0, -1, 1, -2, 2, -1, 1, -1, 1 };
	int cal_val[10] = { alpha, five, ten, ten, two, two, seven, seven, one, one };
	if (direction_idx == 0) {
		for (int i = 0; i < 10; i++) {
			if (start_x + cal_x[i] < 0 || start_x + cal_x[i] > N - 1 || start_y + cal_y[i] < 0 || start_y + cal_y[i] > N - 1) {
				answer += cal_val[i];
			}
			else {
				map[start_y + cal_y[i]][start_x + cal_x[i]] += cal_val[i];
			}
		}
	}
	else if (direction_idx == 1) {
		for (int i = 0; i < 10; i++) {
			if (start_x + cal_y[i] < 0 || start_x + cal_y[i] > N - 1 || start_y - cal_x[i] < 0 || start_y - cal_x[i] > N - 1) {
				answer += cal_val[i];
			}
			else {
				map[start_y - cal_x[i]][start_x + cal_y[i]] += cal_val[i];
			}
		}
	}
	else if (direction_idx == 2) {
		for (int i = 0; i < 10; i++) {
			if (start_x - cal_x[i] < 0 || start_x - cal_x[i] > N - 1 || start_y - cal_y[i] < 0 || start_y - cal_y[i] > N - 1) {
				answer += cal_val[i];
			}
			else {
				map[start_y - cal_y[i]][start_x - cal_x[i]] += cal_val[i];
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (start_x - cal_y[i] < 0 || start_x - cal_y[i] > N - 1 || start_y + cal_x[i] < 0 || start_y + cal_x[i] > N - 1) {
				answer += cal_val[i];
			}
			else {
				map[start_y + cal_x[i]][start_x - cal_y[i]] += cal_val[i];
			}
		}
	}
	start_x = target_x;
	start_y = target_y;
}

