#include <iostream>
#include <cmath>

#define FASTIO() do { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0);

using namespace std;

void pass(int cal) {
        if (cal == 1) {
                cout << "-";
        }
        else {
                pass(cal/3);
                for (int i = 0; i < cal/3; i ++) {
                        cout << " ";
                }
                pass(cal/3);
        }
}
int main() {
        int N;
        while (true) {

                cin >> N;
                if (cin.eof() == true) {
                        break;
                }

                pass(pow(3,N));
                cout << "\n";
        }
        return 0;
}

