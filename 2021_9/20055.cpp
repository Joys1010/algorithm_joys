#include <iostream>
using namespace std;

#define MAX_N 100
int belt[MAX_N * 2];
int robots[MAX_N * 2];

int N;
int K;

void out() {
	if (robots[N - 1] == 1) {
		robots[N - 1] = 0;
	}
}

void rotate_belt() {

	int tmp = belt[2 * N - 1];

	for (int i = 2 * N - 2; i > -1; i--) {
		belt[i + 1] = belt[i];
	}
	belt[0] = tmp;
	
	for (int i = 2 * N - 2; i > -1; i--) {
		robots[i + 1] = robots[i];
	}
	robots[0] = 0;

	out();
}

void move_robot() {
	
	for (int i = 2 * N - 2; i > -1; i--) {
		if (robots[i + 1] == 0 && robots[i] == 1) {
			if (belt[i + 1] > 0) {
				robots[i + 1] = 1;
				robots[i] = 0;
				belt[i + 1]--;
			}
		}
	}
	out();
}

int check_zero() {
	int zero_cnt = 0;
	for (int i = 0; i < 2*N; i++) {
		if (belt[i] == 0) {
			zero_cnt++;
		}
	}
	return zero_cnt;
}

void new_robot() {
	if (belt[0] > 0) {
		robots[0] = 1;
		belt[0]--;
	}
}

int main() {

	int cnt = 1;

	cin >> N >> K;

	for (int i = 0; i < 2*N; i++) {
		cin >> belt[i];
	}

	while (true) {
		//level_1
		rotate_belt();
		
		//level 2
		move_robot();
		
		//level 3
		new_robot();
		
		//level 4
		if (check_zero() >= K) {
			cout << cnt << "\n";
			return 0;
		}
	
		cnt++;
		
	}
	return 0;
}
