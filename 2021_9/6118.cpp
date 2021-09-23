#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, M;
int a_i, b_i;

vector <int> graph[20001];
vector <int> answer;
int visited[200001];
int dist[200001];
int dist_max;

void dfs() {

	queue <int> q;

	q.push(1);
	dist[1] = 0;

	visited[1] = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (dist_max < dist[current]) {
			dist_max = dist[current];
		}

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			if (visited[next] != 1) {
				visited[next] = 1;
				dist[next] = dist[current] + 1;
				q.push(next);

			}
		}
	}
}

int main() {
	FASTIO();

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a_i >> b_i;
		graph[a_i].push_back(b_i);
		graph[b_i].push_back(a_i);
	}

	dfs();

	for (int i = 1; i <= N; i++) {
		if (dist[i] == dist_max) {
			answer.push_back(i);
		}
	}
	
	sort(answer.begin(), answer.end());


	cout << answer[0] << " " << dist_max << " " << answer.size() << "\n";

	return 0;
}
