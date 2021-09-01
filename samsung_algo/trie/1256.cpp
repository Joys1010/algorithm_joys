#include<iostream>
#include<string>
#include<map>
 
using namespace std;
 
int want;
string origin_word;
map <string, int> my_map;
map <int, string> real_map;
string answer;
int idx;
 
void addWord(string origin) {
 
    int len = origin.length();
    string subword = "";
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            subword += origin[j];
        }
        my_map.insert({ subword, 0 });
        subword = "";
    }
}
 
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
 
    //freopen("input.txt", "r", stdin);
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        //초기화
        my_map.clear();
        idx = 0;
        answer = "";
 
        cin >> want;
        cin >> origin_word;
 
        addWord(origin_word);
 
        map<string, int>::iterator iter;
 
        for (iter = my_map.begin(); iter != my_map.end(); iter++) {
            real_map[idx] = iter->first;
            idx++;
        }
 
        if (want > idx) {
            answer = "none";
        }
        else {
            answer = real_map[want - 1];
        }
 
        cout << "#" << test_case << " " << answer << "\n";
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
