#include <iostream>
#include <map>
#include <stdio.h>
#include <cstring>

using namespace std;

int main() {

	char s[1000010] = {0, };
	char t[1000010] = {0, };
	int l,a;
	a = 0;

	scanf("%[^\n]s",s);

	l = strlen(s);
	for (int i=0;i<l;i++){
		if (s[i] == ' ') {
			a++;
		}
	}

	if (s[0] == ' ') {
		a--;
	}
	if (s[l-1] == ' ') {
		a--;
	}

	printf("%d\n",a+1);


	return 0;
}
