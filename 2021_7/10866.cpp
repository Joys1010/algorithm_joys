#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>

#include <sstream>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

int N;
deque<int> dq;
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
			
			if (command[5] == 'f') {
				dq.push_front(num);
			}
			else {
				dq.push_back(num);
			}
			
		}
		else {
			if (command[4] == 'f') {
				if (!dq.empty()) {
					cout << dq.front() << "\n";
					dq.pop_front();
				}
				else {
					cout << "-1" << "\n";
				}
			}
			else {
				if (!dq.empty()) {
					cout << dq.back() << "\n";
					dq.pop_back();
				}
				else {
					cout << "-1" << "\n";
				}
			}
		}
	}
	else if (command[0] == 's') {
		cout << dq.size() << "\n";
	}
	else if (command[0] == 'e') {
		if (!dq.empty()) {
			cout << "0" << "\n";
		}
		else {
			cout << "1" << "\n";
		}
	}
	else if (command[0] == 'f') {
		if (!dq.empty()) {
			cout << dq.front() << "\n";
		}
		else {
			cout << "-1" << "\n";
		}
	}
	else if (command[0] == 'b') {
		if (!dq.empty()) {
			cout << dq.back() << "\n";
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
