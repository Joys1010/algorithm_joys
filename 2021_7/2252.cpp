#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N, M;
int edge_num[32001];
vector <int> works[32001];
int first, second;
queue<int> q;
int sorted[32001];

//topology sort

int main() {
	FASTIO();

	cin >> N >> M;

	for (int i = 0; i < M; i ++) {
		cin >> first >> second;
		works[first].push_back(second); //first 후에 뒤따르는 second의 목록 저장
		edge_num[second]++; //하나의 일에 해당하는 진입 차수 계산 및 저장
	}

	for (int i = 1; i < N+1; i ++) {
		if (edge_num[i] == 0) { //진입 차수가 0인 경우 queue에 추가
			q.push(i);		
		}
	}

	for (int i = 1; i < N+1; i ++) {
		int pos = q.front();
		q.pop();

		sorted[i] = pos; //위상정렬의 결과를 담은 배열에 현재 queue에서 가장 앞의 값 추가

		for (int j = 0; j < works[pos].size(); j ++) {
			int next_pos = works[pos][j]; //현재 pos에 해당 하는 일에 뒤따르는 일들의 진입 차수 계산 및 저장 / 현재 pos의 일과 뒤따르는 일들과 edge 끊기
			edge_num[next_pos]--;
			if (edge_num[next_pos] == 0) { 
				q.push(next_pos);
			}
		}
	}

	for (int i = 1; i < N+1; i ++) {
		cout << sorted[i] << " ";
	}

	return 0;
}
