#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main() {

	int m;

	cin >> N >> M;
	vector <vector<int>> map(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m;
			map[i].push_back(m);
		}
	}
	
	int max = 0;
	int tmp = 0;
	//skyblue (가로)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 3; j++) {
			tmp = map[i][j + 0] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//skyblue (세로)
	for (int i = 0; i < N - 3; i++) {
		for (int j = 0; j < M; j++) {
			tmp = map[i + 0][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
			if (tmp > max) {
				max = tmp;
			}
		}
	}

	//yellow
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			tmp = map[i][j + 0] + map[i][j + 1] + map[i + 1][j + 0] + map[i + 1][j + 1];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//orange 0
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//orange 90
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			tmp = map[i + 0][j] + map[i + 1][j] + map[i + 0][j + 1] + map[i + 0][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//orange 180
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			tmp = map[i + 0][j] + map[i + 0][j+1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//orange 270
	for (int i = 0; i < N-1; i++) {
		for (int j = 2; j < M; j++) {
			tmp = map[i + 1][j - 2] + map[i + 1][j - 1] + map[i + 1][j] + map[i][j];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//orange flip
	for (int i = 0; i < N-2; i++) {
		for (int j = 1; j < M; j++) {
			tmp = map[i + 0][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//orange flip 90
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M -2; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//orange flip 180
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//orange flip 270
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//green
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//green 90
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 1][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//green flip 
	for (int i = 0; i < N - 2; i++) {
		for (int j = 1; j < M; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//green flip 90
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//pink
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i][j + 2];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//pink 90
	for (int i = 0; i < N - 2; i++) {
		for (int j = 1; j < M; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//pink 180
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	//pink 270
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			if (tmp > max) {
				max = tmp;
			}
		}
	}

	cout << max << "\n";
	
	return 0;
}
