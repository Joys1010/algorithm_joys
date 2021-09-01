#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N;
string name;

bool cmp(string a, string b) {
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return false;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		vector <string> names;

		for (int i = 0; i < N; i++) {
			cin >> name;
			names.push_back(name);
		}
		sort(names.begin(), names.end(),cmp);
	
		cout << "#" << test_case << "\n";
		cout << names[0] << "\n";
		for (int i = 1; i < names.size(); i++) {
			if (names[i] != names[i - 1]) {
				cout << names[i] << "\n";
			}
			
		}
	}
	return 0;
}
