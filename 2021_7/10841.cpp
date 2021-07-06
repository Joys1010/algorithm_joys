#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
int age;
string name;
vector <pair<int,string>> info;

bool cmp(pair<int,string> a, pair<int,string> b) {

	return a.first < b.first;
	
}

int main() {
	FASTIO();

	cin >> N;

	for (int i=0;i<N;i++) {
		cin >> age >> name;
		info.push_back(make_pair(age,name));
	}

	stable_sort(info.begin(),info.end(),cmp);

	for (int i=0;i<N;i++) {
		cout << info[i].first << " " << info[i].second << "\n";
	}

	return 0;
}
