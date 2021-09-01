#include<iostream>
#define MAX_N 1000001

using namespace std;

int n, p;
int study[MAX_N]; //1~1000000 날 중 공부를 한 날 표시
int day;

int find() {
	int before = 0;
	int pos = 0;
	int result = 0;
	int max = 0;
	int tmp = p;

	while (pos < MAX_N) {
		if (study[pos] == 1) {
			result++;
			pos++;
			if (result > max) {
				max = result;
			}
		}
		else {
			if (tmp == 0) {
				if (result > max) {
					max = result;
				}
				if (study[before] == 2) { //해킹한날이면 해킹 취소
					study[before] = 0;
					tmp++;
				}
				before++;
				result--;
			}
			else { //해킹
				tmp--;
				study[pos] = 2;
				pos++;
				result++;
				if (result > max) {
					max = result;
				}
			}
		}
	}
	return max;
}




int main(int argc, char** argv)
{
	int test_case;
	int T;
	int result; 

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//초기화
		for (int i = 0; i < MAX_N; i++) {
			study[i] = 0;
		}
		result = 0;

		cin >> n >> p;

		for (int i = 0; i < n; i++) {
			cin >> day;
			study[day] = 1;
		}

		result = find();

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
