#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[110] = {0,};
vector <int> v;
int total,first,second;
int relations;
int parent,child;
int result;
int cnt, tmp, lca;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> total;
	cin >> first;
	cin >> second;

	cin >> relations;

	for (int i=0;i<relations;i++) {
		cin >> parent;
		cin >> child;

		arr[child] = parent;
	}

	tmp = first;
	while (tmp) {
		v.push_back(tmp);
		tmp = arr[tmp];
	}

	tmp = second;
	while (tmp) {
		
		auto it = find(v.begin(),v.end(),tmp);

		if (it != v.end()) {
			lca = tmp;
			break;
		}

		if (arr[tmp] == 0) {
			break;
		}
		tmp = arr[tmp];

	}

	if (lca == 0) {
		result = -1;
	}
	else {
		tmp = first;
		while (tmp != lca) {
			cnt++;
			tmp = arr[tmp];
		}

		tmp = second;
		while (tmp != lca) {
			cnt++;
			tmp = arr[tmp];
		}
		result = cnt;	
	}

	cout << result << endl;

	return 0;
}
