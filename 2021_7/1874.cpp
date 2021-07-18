#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int arr[100001];
stack <int> nums;
int until;
string result;
int result_flag;
void solve() {
	for (int i = 0; i < N; i ++) {
		if (i == 0) {
			for (int j = 0; j < arr[i]; j++) {
				nums.push(until);
				until++;
				result += "+\n";
			}
			nums.pop();
			result += "-\n";
		}
		
		else if (!nums.empty()) {
			if (nums.top() < arr[i]) {
				int tmp = until;
				for (int j = tmp - 1; j < arr[i]; j++) {
					nums.push(until);
					until++;
					result += "+\n";
				}
				nums.pop();
				result += "-\n";
			}
			else if (nums.top() == arr[i]) {
				nums.pop();
				result += "-\n";
			}
			else {
				cout << "NO\n";
				result_flag = 1;
				return;
			}
		}
		else {
			int tmp = until;
			for (int j = tmp - 1; j < arr[i]; j++) {
				nums.push(until);
				until++;
				result += "+\n";
			}
			nums.pop();
			result += "-\n";
		}

	}
}
int main() {

	cin >> N;

	for (int i = 0; i < N; i ++) {
		cin >> arr[i];
	}

	until = 1;
	solve();

	if (result_flag != 1) {
		cout << result;
	}
	return 0;
}
