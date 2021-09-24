#include <iostream>
#include <cmath>

using namespace std;

long long multiply(int A, int B, int C) {

	long long answer = 1;
	if (B == 1) {
		answer = A % C;
		return answer;
	}

	if (B % 2 == 0) {
		answer = multiply(A, B/2, C);
		answer %= C;
		answer = answer * answer;
		answer %= C;
		return answer;
	}
	else {
		answer = multiply(A, B/2, C);
		answer %= C;
		answer = answer * answer;
		answer %= C;
		answer *= A;
		answer %= C;
		return answer;
	}

}
int main() {
	
	int A, B, C;

	cin >> A >> B >> C;

	long long ans = multiply(A, B, C);
	
	cout << ans << "\n";
	
	return 0;
}
