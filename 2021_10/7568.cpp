#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int n;
int height, weight;
vector <pair<int, int>> info;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> height >> weight;
		info.push_back({ height, weight });
	}

	for (int i = 0; i < n; i++) {
		int my_height = info[i].first;
		int my_weight = info[i].second;
		int my_rank = 1;
		for (int j = 0; j < n; j++) {
			if (info[j].first > my_height && info[j].second > my_weight) {
				my_rank++;
			}
		}
		cout << my_rank << " ";
	}

	return 0;
}

