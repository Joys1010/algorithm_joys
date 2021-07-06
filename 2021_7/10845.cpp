#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

#include <sstream>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
queue<int> q;
string command;

void do_work(string command) {

	if (command[0] == 'p') {
		if (command[1] == 'u') {
			
			vector <string> substring;

			istringstream ss(command);
			string stringBuffer;
			while (getline(ss, stringBuffer, ' ')) {
				substring.push_back(stringBuffer);
			}
			int num = stoi(substring[1]);
			q.push(num);
		}
		else {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else {
				cout << "-1" << "\n";
			}
		}
	}
	else if (command[0] == 's') {
		cout << q.size() << "\n";
	}
	else if (command[0] == 'e') {
		if (!q.empty()) {
			cout << "0" << "\n";
		}
		else {
			cout << "1" << "\n";
		}
	}
	else if (command[0] == 'f') {
		if (!q.empty()) {
			cout << q.front() << "\n";
		}
		else {
			cout << "-1" << "\n";
		}
	}
	else if (command[0] == 'b') {
		if (!q.empty()) {
			cout << q.back() << "\n";
		}
		else {
			cout << "-1" << "\n";
		}
	}
}

int main() {
	
	cin >> N;
	cin.ignore();

	for (int i=0;i<N;i++) {
		getline(cin,command);
		do_work(command);
	}

	return 0;
}
