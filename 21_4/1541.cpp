#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int l, sum, total;
string nums;
int mf,pf;

int main() {
	
	cin >> s;

	l = s.length();

	for (int i=0;i<l;i++) {

		if (s[i] == '-') {
			mf = 1;
		}

		else if (s[i] == '+') {

			if (mf == 1) {
				s[i] = '-';
			}	
		}
	}
	mf = 0;

	for (int i=0;i<l;i++) {
		if (s[i] == '-') {
			if (mf == 1) {
				total -= stoi(nums);
				nums = "";
			}
			else {
				total += stoi(nums);
				nums = "";
			}
			mf = 1;
		}

		else if (s[i] == '+') {
			total += stoi(nums);
			nums = "";
		}
		else {
			nums += s[i];
		}


	}

	if (mf == 1) {
		total -= stoi(nums);
	}
	else {
		total += stoi(nums);
	}

	cout << total << endl;

		
	return 0;
}
