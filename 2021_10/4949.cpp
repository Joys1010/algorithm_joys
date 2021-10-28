#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
string c;

int main() {
	
	while (true) {
		
		getline(cin,str);
		
		if (str == ".") {
			break;
		}

		vector <char> my_stack;
		bool flag = true;
		
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']') {
				continue;
			}
			else if (str[i] == '(') {
				my_stack.push_back(str[i]);
			}
			else if (str[i] == '[') {
				my_stack.push_back(str[i]);
			}
			else if (str[i] == ')') {
				if (my_stack.empty()) {
					flag = false;
					break;
				}
 				char back = my_stack.back();
				if (back == '(') {
					my_stack.pop_back();
				}
				else {
					flag = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (my_stack.empty()) {
					flag = false;
					break;
				}
				char back = my_stack.back();
				if (back == '[') {
					my_stack.pop_back();
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (!my_stack.empty()) {
			flag = false;
		}
		if (flag) cout << "yes\n";
		else cout << "no\n";
	}
	
	return 0;
}

