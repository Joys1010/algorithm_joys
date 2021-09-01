#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int V, E, first, second;
int s, e;
int result;
int lca;
int answer;

int tree_info[10001];

void solve() {
	int tmp = 0;
	//first와 second의 공통조상 찾기..
	
	vector <int> v;
	//first
	tmp = first;
	while (tmp) {
		v.push_back(tmp);
		tmp = tree_info[tmp];
	}
	//second
	tmp = second;
	while (tmp) {
		auto it = find(v.begin(), v.end(), tmp);
		if (it != v.end()) {
			lca = tmp;
			break;
		}
		tmp = tree_info[tmp];
	}

	queue <int> q;
	q.push(tmp);
	while (!q.empty()) {
		tmp = q.front();
		for (int i = 1; i <= V; i++) {
			if (tree_info[i] == tmp) {
				result++;
				q.push(i);
			}
		}
		q.pop();
	}

	result = result + 1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//초기화
		result = 0;
		lca = 0;
		for (int i = 0; i < 10001; i++) {
			tree_info[i] = 0;
		}

		cin >> V >> E >> first >> second;


		for (int i = 0; i < E; i++) {
			cin >> s >> e;
			tree_info[e] = s;
		}

		solve();

		cout << "#" << test_case << " " << lca << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
