#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
string str;

void check_vps(string str) {
	
	int length = str.length();
	stack<char> s;

	for (int i=0;i<length;i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else {
			if (!s.empty()) {
				s.pop();
			}
			else {
				cout << "NO\n";
				return;
			}
		}
	}
	if (!s.empty()) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	return;
}

int main() {

	FASTIO();

	cin >> N;

	for (int i=0;i<N;i++) {
		cin >> str;
		check_vps(str);
	}
	return 0;
}
