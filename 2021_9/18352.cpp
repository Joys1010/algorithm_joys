#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

#define MAX_N 3000000
#define INT_MAX 2147483647

int N, M, K, X;
int s, e;

vector <pair<int,int>> adj[MAX_N];
int dist[MAX_N];
int flg;

void dijkstra(int start);

int main() {
	FASTIO();

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i ++) {
		cin >> s >> e;
		adj[s].push_back({1, e});
	}

	for (int i = 1; i <= N; i ++) {
		dist[i] = INT_MAX;
	}
	
	dijkstra(X);

	for (int i = 1; i <= N; i ++) {
		if ( dist[i] == K) {
			flg = 1;
			cout << i << "\n";
		}
	}
	
	if (flg == 0) {
		cout << "-1\n";
	}
		
	return 0;
}

void dijkstra(int start) {

	priority_queue <pair<int,int>> pq;

	pq.push({0, start});
	dist[start] = 0;

	while (!pq.empty()) {
		int distance = -pq.top().first;
		int now = pq.top().second;

		pq.pop();

		if (dist[now] < distance) {
			continue;
		}
		int s = adj[now].size();
		for (int i = 0; i < s; i++) {
			int cost = distance + 1;

			if (cost < dist[adj[now][i].second]) {
				dist[adj[now][i].second] = cost;
				pq.push({-cost, adj[now][i].second});
			}
		}
	}
}
