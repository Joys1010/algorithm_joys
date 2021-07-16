#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, R;
int numbers[10] = {1,2,3,4,5,6,7,8,9,0};
int visited[10];

void print_result() {
	
	for (int i = 0; i < N; i ++) {
		if (visited[i] == 1) {
			cout << i+1 << " ";
		}
	}
	cout << "\n";
}

void backtracking(int pos, int cnt) {
	
	if (cnt == R) {
		print_result();
		return;
	}
	else {
		for (int i = pos; i < N; i ++) {
			if (visited[i] == 1) {
				continue;
			}
			else {
				visited[i] = 1;
				backtracking(i, cnt+1);
				visited[i] = 0;
			}
		}	
	}	
}
int main() {
	FASTIO();

	cin >> N >> R;

	backtracking(0,0);
	
	return 0;
}
