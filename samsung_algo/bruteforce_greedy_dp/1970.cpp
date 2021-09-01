#include<iostream>

using namespace std;
int money;




int main(int argc, char** argv)
{
	int test_case;
	int T;
	int unit[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
	int save[8]{ 0, };

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> money;


		for (int i = 0; i < 8; i++) {
			save[i] = 0;
		}
		
		
		for (int i = 0; i < 8; i++) {
			if (money >= unit[i]) {
				save[i] = money / unit[i];
				money %= unit[i];
			}
		}
		cout << "#" << test_case << "\n";
		for (int i = 0; i < 8; i++) {
			cout << save[i] << " ";
		}
		cout << "\n";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
