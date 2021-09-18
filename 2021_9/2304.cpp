#include <iostream>
#include <stack>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int x, y;
int answer;
int max_y_x_pos;
int max_y, max_x;
int min_x = 1010;
int storage[1010];

stack <int> s;

int main() {
	FASTIO();


	cin >> N;

	for (int i = 0; i < N; i ++) {
		cin >> x >> y;
		storage[x] = y;
		if (y > max_y) {
			max_y = y;
			max_y_x_pos = x;
		}
		if (x > max_x) {
			max_x = x;
		}		
		if (x < min_x) {
			min_x = x;
		}
	}

	s.push(0);
	for (int i = min_x; i <= max_y_x_pos; i ++) {
		if (s.top() < storage[i]) {
			s.pop();
			s.push(storage[i]);
		}
		answer += s.top();
	}

	while (!s.empty()) {
		s.pop();
	}
		
	s.push(0);
	for (int i = max_x; i > max_y_x_pos; i --) {
		if (s.top() < storage[i]) {
			s.pop();
			s.push(storage[i]);
		}
		answer += s.top();
	}

	cout << answer << "\n";

	return 0;
}

