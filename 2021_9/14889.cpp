#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int point[20][20];

int calculate_point(vector <int> &start, vector <int> &link) {
	int gap = 0;
	int start_score = 0;
	int link_score = 0;
	//start팀 점수 계산
	for (int i = 0; i < start.size(); i++) {
		for (int j = i; j < start.size(); j++) {
			if (i != j) {
				start_score += point[start[i] - 1][start[j] - 1] + point[start[j] - 1][start[i] - 1];
			}
		}
	}
	//link팀 점수 계산
	for (int i = 0; i < link.size(); i++) {
		for (int j = i; j < link.size(); j++) {
			if (i != j) {
				link_score += point[link[i] - 1][link[j] - 1] + point[link[j] - 1][link[i] - 1];
			}
		}
	}

	gap = start_score - link_score;
	if (gap < 0) {
		gap = -gap;
	}
	return gap;
}

int result = 20000000;

void divide_team(vector <int>& start_team, vector <int>& link_team, int people_num, int pos) {

	if (pos == people_num * 2 && start_team.size() == people_num && link_team.size() == people_num) {
		int gap = calculate_point(start_team, link_team);
		result = min(gap, result);
		return;
	}

	if (start_team.size() < people_num) {
		start_team.push_back(pos + 1);
		divide_team(start_team, link_team, people_num, pos + 1);
		start_team.pop_back();
	}
	if (link_team.size() < people_num) {
		link_team.push_back(pos + 1);
		divide_team(start_team, link_team, people_num, pos + 1);
		link_team.pop_back();
	}
}


int main() {

	int N;

	int tmp;
	vector <int> people;
	int ans;

	cin >> N;

	for (int i = 0; i < N; i++) {
		people.push_back(i + 1);
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			point[i][j] = tmp;
		}
	}
	
	vector <int> start_team;
	vector <int> link_team;

	divide_team(start_team, link_team, N / 2, 0);

	cout << result;

	return 0;
}


