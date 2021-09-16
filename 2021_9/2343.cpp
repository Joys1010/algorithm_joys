#include <iostream>
#include <vector>
#include <utility>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int blueray[100001];
int N, M;
long long sum, maxi;

int main() {
	FASTIO();

	cin >> N >> M;

	for (int i = 0; i < N; i ++) {
		cin >> blueray[i];
		sum += blueray[i];

		if (blueray[i] > maxi) {
			maxi = blueray[i];
		}
	}

	int right = sum;
	int left = maxi;
	int mid = 0;

	while (left <= right) {
		int cnt = 0;
		long long tmp = 0;
		mid = (left + right) / 2;

		for (int i = 0; i < N; i ++) {
			if (tmp + blueray[i] > mid) {
				tmp = 0;
				cnt += 1;
			}
			tmp += blueray[i];
		}

		if (tmp != 0) {
			cnt += 1;
		}

		if (cnt <= M) {
			right = mid - 1;
		}
		else {
			left = right + 1;
		}
	}

	cout << left << "\n";


	return 0;
}
