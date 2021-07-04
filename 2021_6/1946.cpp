#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int number;
int t1, t2;

int cnt;
bool flg;

bool compare(pair<int,int> a, pair<int,int> b) {
	
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;

	while(T>0) {
		
		cin >> number;
		vector <pair<int,int>> scores;
		pair<int,int> mean;

		cnt = 1;
		
		for (int i=0;i<number; i++) {
			cin >> t1 >> t2;
			scores.push_back({t1,t2});
		}

		sort(scores.begin(), scores.end(), compare);
		
		mean = scores[0];

		for (int i=1;i<number;i++) {
			if (mean.second > scores[i].second) {
				cnt++;
				mean = scores[i];
			}
		}
		cout << cnt << "\n";
		T--;
	}

	return 0;
}
