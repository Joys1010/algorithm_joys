#include <iostream>
#include <map>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

string s;
int l,a;

int main() {

	cin >> s;

	l = s.length();

	for (int i=0;i<l;i++) {


		if(s[i] == 'A' || s[i] == 'B' || s[i] == 'C') {
			a += 3;
		}
		else if(s[i] == 'D' || s[i] == 'E' || s[i] == 'F') {
			a += 4;
		}
		else if(s[i] == 'G' || s[i] == 'H' || s[i] == 'I') {
			a += 5;
		}
		else if(s[i] == 'J' || s[i] == 'K' || s[i] == 'L') {
			a += 6;
		}
		else if(s[i] == 'M' || s[i] == 'N' || s[i] == 'O') {
			a += 7;
		}
		else if(s[i] == 'P' || s[i] == 'Q' || s[i] == 'R' || s[i] == 'S') {
			a += 8;
		}
		else if(s[i] == 'T' || s[i] == 'U' || s[i] == 'V') {
			a += 9;
		}
		else if(s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'Z') {
			a += 10;
		}
	}

	cout << a << endl;

	return 0;
}
