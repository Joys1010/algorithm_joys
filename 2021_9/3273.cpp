#include <iostream>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int num;
int n;
int want;
int answer;
int nums[2000010];
int main() {

	cin >> n;

	for (int i = 0; i < n; i ++) {
		cin >> num;
		nums[num]++;
	}

	cin >> want;

	for (int i = 0; i <= want; i++) {
		if (nums[i] != 0 && nums[want - i] != 0) {
			answer++;
		}
	}

	
	cout << answer/2 << "\n";

	return 0;
}
