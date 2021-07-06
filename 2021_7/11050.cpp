#include <iostream>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, K;
int result;

int main() {
	FASTIO();
	cin >> N >> K;

	result = 1;
	for (int i=N;i>N-K;i--) {
		result *= i;		
	}
	for (int i=1;i<=K;i++) {
		result /= i;
	}

	cout << result << "\n";

	return 0;
}
