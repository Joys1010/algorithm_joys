#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int K, N;
long long low, high, mid;
long long lengths[10010];
long long cnt, ans;
void find_answer() {
	
	while (low <= high) {
		
		mid = (low+high)/2;
		cnt = 0;
		
		for (int i = 0; i< K; i++) {
			cnt += lengths[i]/mid;	
		}
		
		if (cnt >= N) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}	
	}

	cout << ans << "\n";

}

int main() {
	FASTIO();

	cin >> K >> N;
	
	cin >> lengths[0];
	high = lengths[0];
	low = 1;
	for (int i = 1; i < K; i ++) {
		cin >> lengths[i];

		if (lengths[i] > high) {
			high = lengths[i];
		}
	}
	find_answer();

	return 0;
}
