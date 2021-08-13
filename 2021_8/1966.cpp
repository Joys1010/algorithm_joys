#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int doc_num;
int pos;
int n;
int cnt;

struct compare {
	bool operator()(pair<int,int> a, pair<int,int> b) {

		return a.second < b.second;
	}
};


int main() {
	FASTIO();

	cin >> N;
	for (int i = 0; i < N; i ++) {
		priority_queue<pair<int,int>,vector<pair<int,int>>, compare> pq;
		queue<pair<int,int>> q;

		cin >> doc_num >> pos;

		for (int j = 0; j < doc_num; j++) {
			cin >> n;
			pq.push(make_pair(j,n));
			q.push(make_pair(j,n));			
		}
		
		pair<int,int> pq_tmp;
		pair<int,int> q_tmp;
		
		while (!q.empty()) {
			pq_tmp = pq.top();
			q_tmp = q.front();

			if (pq_tmp.second == q_tmp.second) {
				cnt++;
				pq.pop();
				q.pop();

				if (q_tmp.first == pos) {
					cout << cnt << "\n";
				}
			}
			else {
				q.pop();
				q.push(q_tmp);
			}
		}
		cnt = 0;

	}

	return 0;
}
