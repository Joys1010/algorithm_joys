#include <iostream>
#include <map>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

string s;
int l,a;

int main() {

        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

	cin >> s;
	l = s.length();

	for (int i=0;i<l;i++) {

		if (s[i] == 'c') {
			if (i+1 >= l) {
				a++;
				break;
			}
			else if (s[i+1] == '=') {
				a++;
				i++;
			}
			else if (s[i+1] == '-') {
				a++;
				i++;
			}
			else {
				a++;
			}
		}
		else if (s[i] == 'd') {
			if (i+1 >= l) {
				a++;
				break;
			}
			else if (s[i+1] == '-') {
				a++;
				i++;
			}
			else if (s[i+1] == 'z') {
				if (i+2 >= l) {
					a += 2;
					break;
				}
				else if (s[i+2] == '=') {
					a++;
					i += 2;
				}
				else {
					a++;;
				}
			}
			else {
				a++;
			}
		}
		else if (s[i] == 'l' || s[i] == 'n') {
			if (i+1 >= l) {
				a++;
				break;
			}
			else if (s[i+1] == 'j') {
				a++;
				i++;
			}
			else {
				a++;
			}
		}
		else if (s[i] == 's' || s[i] == 'z') {
			if (i+1 >= l) {
				a++;
				break;
			}
			else if (s[i+1] == '=') {
				a++;
				i++;
			}
			else {
				a++;
			}

		}
		else {
			a++;
		}

	}

	cout <<  a << endl;


	return 0;
}
