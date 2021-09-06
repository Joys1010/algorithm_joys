#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int n, k;


int main() {
	FASTIO();

	int cnt = 0;
	int s;
	string tmp = "";
	vector <int> nums;
	set <string> new_nums;
	
	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i ++) {
		cin >> s;
		nums.push_back(s);
	}

	sort(nums.begin(), nums.end());

	do {
		tmp = "";
		for (int i = 0; i < k; i++) {
			tmp += to_string(nums[i]);
		}
		new_nums.insert(tmp);

	} while (next_permutation(nums.begin(), nums.end()));

	cout << new_nums.size() << "\n";

	return 0;
}
