#include <iostream>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int want;
int tree;
int maxi;
int trees[1000000];

void binary() {
	
	int low = 0;
	int high = maxi;
	long long ans = 0;
	int now = 0;
	while (low <= high) {
		now = (low + high) / 2;
		ans = 0;
		for (int i = 0; i < N; i ++) {
			if (trees[i] - now > 0) {
				ans += trees[i] - now;
			}
		}

		if (ans >= want) {
			low = now + 1;
		}
		else {
			high = now - 1;
		}
	}
	cout << high << "\n";
}

int main() {
	FASTIO();
	cin >> N >> want;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		if (maxi < trees[i]) {
			maxi = trees[i];
		}
	}
	binary();
	
	return 0;
}
