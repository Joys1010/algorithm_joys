#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<string.h>
using namespace std;

int N, node_num, left_node, right_node;
string info;
string input_data;

struct node {

	string node_data;
	node* left_child;
	node* right_child;
};

node tree[202];

void inorder_traversal(node* root) {

	if (root != nullptr) {
		inorder_traversal(root->left_child);
		cout << root->node_data;
		inorder_traversal(root->right_child);
	}
}


int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		//초기화
		for (int i = 0; i < 202; i++) {
			tree[i].node_data = "";
			tree[i].left_child = nullptr;
			tree[i].right_child = nullptr;
		}

		cin >> N;
		cin.ignore();
		for (int i = 0; i < N; i++) {
			node_num = 0;
			left_node = 0;
			right_node = 0;

			getline(cin, input_data);
			vector <string> tmp;
			int cnt;
			
			char str_buf[50];
			strcpy(str_buf, input_data.c_str());
			char* ptr = strtok(str_buf, " ");

			while (ptr != nullptr) {
				tmp.push_back(string(ptr));
				ptr = strtok(nullptr, " ");
			}
		

			for (int i = 0; i < tmp.size(); i++) {
				if (i == 0) {
					node_num = stoi(tmp[i]);
				}
				else if (i == 1) {
					info = tmp[i];
				}
				else if (i == 2) {
					left_node = stoi(tmp[i]);
				}
				else if (i == 3) {
					right_node = stoi(tmp[i]);
				}
			}

			tree[node_num].node_data = info;
			if (left_node != 0) {
				tree[node_num].left_child = &tree[left_node];
			}
			else {
				tree[node_num].left_child = nullptr;
			}
			if (right_node != 0) {
				tree[node_num].right_child = &tree[right_node];
			}
			else {
				tree[node_num].right_child = nullptr;
			}
		};
		
		cout << "#" << test_case << " ";
		inorder_traversal(&tree[1]);
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
