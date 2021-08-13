#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
vector <pair<int,int>> nums;
pair<int,int> num;
int x, y;

bool cmp(pair<int,int> a, pair<int,int> b) {

	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	FASTIO();

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		num.first = x;
		num.second = y;

		nums.push_back(num);
	}

	sort(nums.begin(), nums.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << nums[i].first << " " << nums[i].second << "\n";
	}
	return 0;
}
