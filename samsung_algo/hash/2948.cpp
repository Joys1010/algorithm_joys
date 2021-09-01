#include<iostream>
#include<set>
#define FASTIO() do{ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); } while(0)
 
using namespace std;
 
int n1, n2;
string s;
int answer;
 
int main(int argc, char** argv)
{
    FASTIO();
    int test_case;
    int T;
 
    //freopen("input.txt", "r", stdin);
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        //초기화
        answer = 0;
 
        cin >> n1 >> n2;
        set <string> strings;
        set <string>::iterator find_iter;
 
        for (int i = 0; i < n1; i++) {
            cin >> s;
            strings.insert(s);
        }
 
        for (int i = 0; i < n2; i++) {
            cin >> s;
            find_iter = strings.find(s);
            if (find_iter != strings.end()) {
                answer++;
            }
        }
 
         
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
