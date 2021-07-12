#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, M, first, second;
vector <int> works[100001];
queue <int> q;
int done[100001];
int work_num, result;

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i ++) {
		cin >> first >> second;
		works[second].push_back(first);
	}

	cin >> work_num;

	for (int i = 0; i < works[work_num].size(); i ++) {
		result ++;
		q.push(works[work_num][i]);
		done[works[work_num][i]] = 1;
	}
	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		for (int i = 0; i < works[pos].size(); i ++) {
			if (done[works[pos][i]] != 1) {
				result ++;
				q.push(works[pos][i]);
				done[works[pos][i]] = 1;
			}
		}
	}

	cout << result << endl;

	return 0;
}
