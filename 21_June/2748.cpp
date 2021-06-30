#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, value;
long fib[100];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> N;

	fib[0] = 0;
	fib[1] = 1;

	for (int i=2;i<N+1;i++) {
		if (fib[i] == 0) {
			fib[i] = fib[i-2] + fib[i-1];
		}
	}

	cout << fib[N] << endl;
	return 0;
}
