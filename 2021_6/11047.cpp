#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int total;
int value;
vector <int> values;
int remain;
int cnt, global_cnt;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> total;

	for (int i=0;i<n;i++) {
		cin >> value;
		values.push_back(value);
	}

	remain = total;
	while (total != 0) {
		for (int i=n-1;i>-1;i--) {
			if (total <  values[i]) {
				continue;
			}
			else {
				cnt = total/values[i];
				global_cnt += cnt;
				total -= values[i]*cnt;
			}
		}			
	}

	cout << global_cnt << endl;
	return 0;
}
