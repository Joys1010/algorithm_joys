#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int n;
int frequency[8001];
vector <int> nums;

int main () {
	FASTIO();
	
	cin >> N;
	
	double sum = 0;
	int max_freq = 0;
	int result = 0;

	for (int i = 0; i < N; i ++) {
		cin >> n;
		nums.push_back(n);
		frequency[n+4000]++;
		if (max_freq < frequency[n+4000]) {
			max_freq = frequency[n+4000];
		}
	}
	sort(nums.begin(), nums.end());
	//first
	for (int i = 0; i < N; i ++) {
		sum += nums[i];
	}
	cout << int(floor((sum/N)+0.5)) << "\n";
	//second
	cout << nums[N/2] << "\n";
	//third
	int cnt = 0;
	for (int i = 0; i < 8001; i ++) {
		if (frequency[i] == max_freq) {
			result = i-4000;
			cnt++;
		}
		if (cnt == 2) {
			result = i-4000;
			cout << result << "\n";
			break;
		}
	}
	if (cnt == 1) {
		cout << result << "\n";
	}
	//fourth
	cout << nums[N-1] - nums[0] << "\n";
	return 0;
}
