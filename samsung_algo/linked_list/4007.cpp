#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>

#define INF 10000000
#define MAX_N 50010
#define MAX_M 500010
using namespace std;

struct Edge {
	int time;
	int end_room;
	Edge* next;
};
struct Node {
	Edge* info;
};

int right_cnt;
int reverse_cnt;

Node room[MAX_N];
Node reverse_room[MAX_N];

Edge rightway[MAX_M];
Edge reverseway[MAX_M];

void init() {
	right_cnt = 0;
	reverse_cnt = 0;
}

Edge* getEdge(int e, int t, int right) {
	if (right == 1) {
		rightway[right_cnt].end_room = e;
		rightway[right_cnt].time = t;
		rightway[right_cnt].next = nullptr;
		return &rightway[right_cnt++];
	}
	else {
		reverseway[reverse_cnt].end_room = e;
		reverseway[reverse_cnt].time = t;
		reverseway[reverse_cnt].next = nullptr;
		return &reverseway[reverse_cnt++];
	}
}

void addEdgeToRoom(Edge *edge, int start, int right) {

	if (right == 1) {
		Edge* tmp = room[start].info;
		if (tmp == nullptr) {
			room[start].info = edge;
			return;
		}
		else {
			edge->next = tmp;
			room[start].info = edge;
		}
	}
	else {
		Edge* tmp = reverse_room[start].info;
		if (tmp == nullptr) {
			reverse_room[start].info = edge;
			return;
		}
		else {
			edge->next = tmp;
			reverse_room[start].info = edge;
		}
	}
}


priority_queue <pair<int, int>> pq;

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

	//cin >> T;
	setbuf(stdout, NULL);
	scanf("%d", &T);

	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		scanf("%d %d %d", &N, &M, &X);
		//cin >> N >> M >> X;
		init();

		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &start, &end, &time);
			//cin >> start >> end >> time;
			//edge 생성
			Edge *right_edge = getEdge(end-1, time, 1);
			Edge* reverse_edge = getEdge(start-1, time, 0);
			//room에 edge 달기
			addEdgeToRoom(right_edge, start-1 , 1);
			addEdgeToRoom(reverse_edge, end-1, 0);	
		}

		//to_x 배열 만들고 초기화
		to_x = (int*)malloc(sizeof(int) * N);
		for (int i = 0; i < N; i++) {
			if (i == X - 1) {
				to_x[i] = 0;
			}
			else {
				to_x[i] = INF;
			}
		}

		//from_x 배열 만들고 초기화
		from_x = (int*)malloc(sizeof(int) * N);
		for (int i = 0; i < N; i++) {
			if (i == X - 1) {
				from_x[i] = 0;
			}
			else {
				from_x[i] = INF;
			}
		}

		Edge* tmp = nullptr;
		pq.push({ 0, X - 1 });
		while (!pq.empty()) {
			cost = -pq.top().first;
			pos = pq.top().second;
			pq.pop();

			if (to_x[pos] < cost) {
				continue;
			}
			tmp = room[pos].info;
			while (tmp != nullptr) {
				next = tmp->time;
				nextDist = cost + next;

				if (nextDist < to_x[tmp->end_room]) {
					to_x[tmp->end_room] = nextDist;
					pq.push({ -nextDist, tmp->end_room });
				}
				tmp = tmp->next;
			}
		}

		//reverse
		pq.push({ 0, X - 1 });
		while (!pq.empty()) {
			cost = -pq.top().first;
			pos = pq.top().second;
			pq.pop();

			if (from_x[pos] < cost) {
				continue;
			}

			tmp = reverse_room[pos].info;
			while (tmp != nullptr) {
				next = tmp->time;
				nextDist = cost + next;

				if (nextDist < from_x[tmp->end_room]) {
					from_x[tmp->end_room] = nextDist;
					pq.push({ -nextDist, tmp->end_room });
				}
				tmp = tmp->next;
			}
		}

		result = to_x[0] + from_x[0];
		for (int i = 0; i < N; i++) {
			if (result < to_x[i] + from_x[i]) {
				result = to_x[i] + from_x[i];
			}
		}

		printf("#%d %d\n", test_case, result);

		free(to_x);
		free(from_x);

		for (int i = 0; i < MAX_N; i++) {
			room[i].info = nullptr;
			reverse_room[i].info = nullptr;
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
