#include <iostream>
#include <queue>
using namespace std;

queue <int> q;
int n, m, v;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i < n+1; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		
		v = q.front();
		q.push(v);
		q.pop();
	}

	cout << q.front() << endl;

    return 0;
}
