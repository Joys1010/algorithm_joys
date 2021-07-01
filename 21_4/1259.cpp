#include <iostream>
#include <string>

using namespace std;

string s;
int l,f;

int main() {

        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
	
	while (true) {

		cin >> s;
		f = 0;
		if (s == "0") {
			break;
		}
		
		else {
			l = s.length();
			if (l == 1) {
				cout << "yes" << endl;
			}

			else {

				for (int i=0;i<l/2;i++) {
					if (s[i] != s[l-1-i]) {
						f = 1;
					}
				}

				if (f == 0) {
					cout << "yes" << endl;
				}
				else {
					cout << "no" << endl;
				}

			}
		}
	}

	return 0;
}
