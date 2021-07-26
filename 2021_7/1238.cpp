#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>

#define INF 10000000
#define MAX_M 500000
using namespace std;

vector <pair<int, int>> right_way[MAX_M];
vector <pair<int, int>> reverse_way[MAX_M];


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int** ways;
	int* to_x;
	int* from_x;
	int N, M, X;
	int start, end, time;

	int tmp;
	int mini_idx;
	int mini;
	int result;

	int cost;
	int pos;
	int next;
	int nextDist;

	setbuf(stdout, NULL);
	scanf("%d %d %d", &N, &M, &X);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &start, &end, &time);

		right_way[start - 1].push_back({ end - 1,time });
		reverse_way[end - 1].push_back({ start - 1, time });
	}

	to_x = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		if (i == X - 1) {
			to_x[i] = 0;
		}
		else {
			to_x[i] = INF;
		}
	}

	from_x = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		if (i == X - 1) {
			from_x[i] = 0;
		}
		else {
			from_x[i] = INF;
		}
	}


	priority_queue <pair<int, int>> pq;

	pq.push({ 0, X - 1 });
	while (!pq.empty()) {
		cost = -pq.top().first;
		pos = pq.top().second;
		pq.pop();

		if (to_x[pos] < cost) {
			continue;
		}

		for (int i = 0; i < right_way[pos].size(); i++) {

			next = right_way[pos][i].second;
			nextDist = cost + next;

			if (nextDist < to_x[right_way[pos][i].first]) {
				to_x[right_way[pos][i].first] = nextDist;
				pq.push({ -nextDist, right_way[pos][i].first });
			}
		}
	}

	pq.push({ 0, X - 1 });
	while (!pq.empty()) {
		cost = -pq.top().first;
		pos = pq.top().second;
		pq.pop();

		if (from_x[pos] < cost) {
			continue;
		}

		for (int i = 0; i < reverse_way[pos].size(); i++) {

			next = reverse_way[pos][i].second;
			nextDist = cost + next;

			if (nextDist < from_x[reverse_way[pos][i].first]) {
				from_x[reverse_way[pos][i].first] = nextDist;
				pq.push({ -nextDist, reverse_way[pos][i].first });
			}
		}

	}

	result = to_x[0] + from_x[0];
	for (int i = 0; i < N; i++) {
		if (result < to_x[i] + from_x[i]) {
			result = to_x[i] + from_x[i];
		}
	}

	printf("%d\n", result);


	free(to_x);
	free(from_x);

	return 0;
}
