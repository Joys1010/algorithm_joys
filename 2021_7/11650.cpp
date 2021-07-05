#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int x,y;
vector <pair<int,int>> numbers;

bool ascend(pair<int,int> x, pair<int,int> y) {

	if (x.first == y.first) {
		return x.second < y.second;
	}
	else {
		return x.first < y.first;
	}
}

int main() {

	FASTIO();

	cin >> N;

	for (int i=0;i<N;i++) {
		cin >> x >> y;
		numbers.push_back(make_pair(x,y));
	}

	sort(numbers.begin(), numbers.end(), ascend);

	for (int i=0;i<N;i++) {
		cout << numbers[i].first << " " << numbers[i].second << "\n";
	}
	return 0;
}
