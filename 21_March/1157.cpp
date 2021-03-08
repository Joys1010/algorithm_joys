#include <iostream>
#include <map>
#include <stdio.h>
#include <cstring>

using namespace std;

int main() {

	map<char,int> l;
	char s[1000010] = {0, };
	int a,len,n,max;
	char ans;
	bool flg = false;

	scanf(" %s",s);

	len = strlen(s);

	for (int i=0;i<len;i++) {
		a = s[i];
		if (a >= 97) {
			if (l.find(s[i]) == l.end() && l.find(char(a-32)) == l.end()) {
				l.insert(make_pair(char(a-32),1));
			}
			else {
				
				l[char(a-32)]++;
			}
		}
		else {

			if (l.find(s[i]) == l.end() && l.find(char(a+32)) == l.end()) {
				l.insert(make_pair(s[i],1));
			}
			else {
				l[s[i]]++;
			}
		}
	}


	map<char,int>::iterator it;
	it = l.begin();
	max = 0;
	for (it=l.begin();it!=l.end();it++) {
		if (max == it->second) {
			flg = true;
		}
		else if (max < it->second) {
			max = it->second;
			ans = it->first;
			flg = false;	
		}
	}

	if (flg == true){
		printf("?\n");
	}
	else {
		printf("%c\n",ans);
	}

	return 0;
}
