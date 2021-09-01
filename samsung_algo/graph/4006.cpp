#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

#define MAX_N 50001
#define MAX_M 200001

using namespace std;

int N;
int M;
int answer;

struct Edge {
	int s;
	int e;
	int c;
};

int edge_cnt;
Edge edges[MAX_M];
int check[MAX_N];
int level[MAX_N];

Edge* getEdge(int start, int end, int cost) {
	edges[edge_cnt].s = start;
	edges[edge_cnt].e = end;
	edges[edge_cnt].c = cost;

	return &edges[edge_cnt++];
}

bool cmp(Edge* a, Edge* b) {
	return a->c < b->c;
}

int getParent(int a) {

	if (check[a] == a) {
		return a;
	}
	else {
		check[a] = getParent(check[a]);
		return check[a];
	}
}

int unionFind(int a, int b) {

	int a_parent = getParent(a);
	int b_parent = getParent(b);


	if (a_parent == b_parent) {
		return 0;
	}

	if (level[a_parent] < level[b_parent]) {
		check[a_parent] = b_parent;
	}
	else {
		check[b_parent] = a_parent;
		if (level[a_parent] == level[b_parent]) {
			level[a_parent]++;
		}
	}
	return 1;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		//초기화
		vector <Edge*> info;
		for (int i = 0; i < MAX_N; i++) {
			check[i] = 0;
			level[i] = 0;
		}
		answer = 0;
		edge_cnt = 0;

		cin >> N;
		cin >> M;

		int start, end, cost;

		for (int i = 0; i < M; i++) {
			cin >> start >> end >> cost;
			Edge* new_edge = getEdge(start - 1, end - 1, cost);
			info.push_back(new_edge);
		}

		sort(info.begin(), info.end(), cmp);

		//union_arr 초기화
		for (int i = 0; i < N; i++) {
			check[i] = i;
		}

		for (int i = 0; i < info.size(); i++) {

			if (unionFind(info[i]->s, info[i]->e)) {
				answer += info[i]->c;
			}
		}
		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;
}
