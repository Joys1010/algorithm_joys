#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
double E;

long long x[1001];
long long y[1001];
long long check[1001];

double answer;
long long length;

struct Edge {
	int s;
	int e;
	long long d;
};

Edge routes[500000];
int route_cnt;

Edge* getEdge(int start, int end) {
	routes[route_cnt].s = start;
	routes[route_cnt].e = end;
	routes[route_cnt].d = (x[start] - x[end]) * (x[start] - x[end]) + (y[start] - y[end]) * (y[start] - y[end]);
	
	return &routes[route_cnt++];
}

bool cmp(Edge* a, Edge* b) {

	return a->d < b->d;
}

int getParent(int a) {
	if (check[a] == a) {
		return a;
	}
	else {
		return getParent(check[a]);
	}
}

int isCycle(int a, int b) {

	//cycle 이면 return 1 아니면 return 0
	int a_parent = getParent(a);
	int b_parent = getParent(b);
	if (a_parent == b_parent) {
		return 1;
	}
	else {
		return 0;
	}
}

void unionFind(int a, int b) {
	
	int a_parent = getParent(a);
	int b_parent = getParent(b);

	if (a_parent < b_parent) {
		check[b_parent] = a_parent;
	}
	else {
		check[a_parent] = b_parent;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		vector <Edge*> info;
		//초기화
		route_cnt = 0;
		length = 0;
		answer = 0;
		for (int i = 0; i < 1001; i++) {
			check[i] = 0;
		}

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> y[i];
		}

		cin >> E;

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				Edge* new_edge = getEdge(i, j);
				info.push_back(new_edge);
			}
		}

		sort(info.begin(), info.end(), cmp);

		for (int i = 0; i < N; i++) {
			check[i] = i;
		}

		for (int i = 0; i < info.size(); i++) {

			//cycle이면 연결 안함, cycle 아니면 연결함
			if (!isCycle(info[i]->s, info[i]->e)) {
				length += info[i]->d;
				//연결
				unionFind(info[i]->s, info[i]->e);
			}
		}

		answer = E * length;

		//반올림 floor는 내림함수 0.5 더해서 편하게 계산
		answer = floor(answer + 0.5);
		cout << "#" << test_case << " " << (long long)answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
