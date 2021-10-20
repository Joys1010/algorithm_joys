#include <iostream>
#include <cmath>
#include <array>

using namespace std;

array<array<int, 100>, 100> map;
array<array<bool, 100>, 100> roads;

int N, L;
int answer;

void find_roads();


int main() {

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	find_roads();

	cout << answer << "\n";

	return 0;
}


void find_roads() {

	for (int i = 0; i < N; i++) {
		int old_value = map[i][0];
		int conti = 1;
		bool flg = true;
		for (int j = 1; j < N; j++) {
			if (map[i][j] + 1 == old_value) { //작아지면 그 다음 
				old_value = map[i][j];
				bool space = true;
				for (int k = 0; k < L; k++) {
					//L만큼 공간 있나 체크
					if (map[i][j + k] != map[i][j]) {
						space = false;
						break;
					}
				}
				if (space) {
					//build road
					for (int k = 0; k < L; k++) {
						roads[i][j + k] = true;
					}
				}
				else {
					flg = false;
					break;
				}
			}
			else if (map[i][j] - 1 == old_value) {
				old_value = map[i][j];
				if (conti >= L) {
					//build road
					bool space = true;
					for (int k = 0; k < L; k++) {
						if (roads[i][j -1 - k] != false) {
							space = false;
							break;
						}
					}
					if (space == false) {
						flg = false;
						break;
					}
					else {
						for (int k = 0; k < L; k++) {
							roads[i][j -1 - k] = true;
						}
					}
				}
				else {
					flg = false;
					break;
				}
			}
			else if (map[i][j] == old_value) {
				conti++;
			}
			else {
				flg = false;
				break;
			}
		}

		if (flg) {
			answer++;
		}
	} 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			roads[i][j] = false;
		}
	}

	for (int j = 0; j < N; j++) {
		int old_value = map[0][j];
		int conti = 1;
		bool flg = true;
		for (int i = 1; i < N; i++) {
			if (map[i][j] + 1 == old_value) { //작아지면 그 다음 
				old_value = map[i][j];
				bool space = true;
				for (int k = 0; k < L; k++) {
					//L만큼 공간 있나 체크
					if (map[i+k][j] != map[i][j]) {
						space = false;
						break;
					}
				}
				if (space) {
					//build road
					for (int k = 0; k < L; k++) {
						roads[i+k][j] = true;
					}
				}
				else {
					flg = false;
					break;
				}
			}
			else if (map[i][j] - 1 == old_value) {
				old_value = map[i][j];
				if (conti >= L) {
					//build road
					bool space = true;
					for (int k = 0; k < L; k++) {
						if (roads[i-1-k][j] != false) {
							space = false;
							break;
						}
					}
					if (space == false) {
						flg = false;
						break;
					}
					else {
						for (int k = 0; k < L; k++) {
							roads[i-1-k][j] = true;
						}
					}
				}
				else {
					flg = false;
					break;
				}
			}
			else if (map[i][j] == old_value) {
				conti++;
			}
			else {
				flg = false;
				break;
			}
		}

		if (flg) {
			answer++;
		}
	}
}

