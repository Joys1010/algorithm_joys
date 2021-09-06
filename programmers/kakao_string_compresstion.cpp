#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();

	int s_len = s.length();

	for (int i = 1; i <= s_len/2; i ++) {
		
		int cnt = 1;
		string tmp = "";
		string change = "";

		tmp = s.substr(0,i);

		for (int j = i; j < s_len; j += i) {

			if (tmp == s.substr(j,i)) {
				cnt++;
			}
			else {
				if (cnt > 1) {
					change += to_string(cnt);		
				}
				change += tmp;
				tmp = s.substr(j,i);
				cnt = 1;
			}
		}

		if (cnt > 1) {
			change += to_string(cnt);	
		}

		change += tmp;
		if (change.length() < answer) {
			answer = change.length();
		}
	}
	return answer;
}
