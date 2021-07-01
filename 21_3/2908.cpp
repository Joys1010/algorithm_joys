#include <iostream>
#include <map>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	char s[100] = {0, };
	char a[5] = {0, };
	char b[5] = {0, };
	int c,d;

	cin.getline(s,100);


	for (int i=0;i<3;i++) {
	
		a[i] = s[2-i];
	}

	for (int j=0;j<3;j++) {
		b[j] = s[6-j];
	}

	c = stoi(a);
	d = stoi(b);

	if (c >= d) {
		cout << c << endl;
	}
	else {
		cout << d << endl;
	}

	return 0;
}
