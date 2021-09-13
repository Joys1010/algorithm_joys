#include <iostream>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

#define MAX_SIZE 1001
int R, C;
int Q;
int where[4];

int photo[MAX_SIZE][MAX_SIZE];
int sum[MAX_SIZE][MAX_SIZE];

void solve();
int main() {
	FASTIO();
	
	cin >> R >> C >> Q;

	for (int i = 1; i <= R; i ++) {
		for (int j = 1; j <= C; j ++) { 
			cin >> photo[i][j];
			if (j == 1) {
				sum[i][j] = photo[i][j];
			}
			else {
				sum[i][j] = sum[i][j-1] + photo[i][j];
			}
		}
	}

	for (int i = 0; i < Q; i ++) {
		cin >> where[0] >> where[1] >> where[2] >> where[3];

		solve();
	}
	return 0;
}

void solve() {

	int answer = 0;

	
	int size = (where[2] - where[0] + 1)*(where[3] - where[1] + 1);
	
	if (size == 1) {
		cout << photo[where[0]][where[1]] << "\n";
	}
	else {

		for (int i = where[0]; i <= where[2]; i ++) {
			//cout << "i : " << i << " value : " << sum[i][where[3]] << " " <<  sum[i][where[1]] << "\n";
			if (where[1] != 0) {
				answer += (sum[i][where[3]] - sum[i][where[1] - 1]);
			}
			else {
				answer += (sum[i][where[3]] - sum[i][where[1]]);
			}
		}
	
		answer = answer / size;

		cout << answer << "\n";
	}
	
}
