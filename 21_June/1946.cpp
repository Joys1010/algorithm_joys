#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int number;
int t1, t2;

int cnt;
bool flg;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;

	while(T>0) {
		
		cin >> number;
		vector <int> t1s;
		vector <int> t2s;

		for (int i=0;i<number; i++) {
			cin >> t1 >> t2;
			t1s.push_back(t1);
			t2s.push_back(t2);
		}

		for (int i=0;i<number;i++) {
			for (int j=0;j<number;j++) {
				if (i != j) {
					if (t1s[i] > t1s[j] && t2s[i] > t2s[j]) {
						flg = false;
						break;
					}
					else {
						flg = true;
					}
				}
			}
			if (flg == true) {
				cnt++;
				flg = false;
			}

		}

		cout << cnt << endl;
		cnt = 0;
		flg = false;

		T--;
	}

	return 0;
}
