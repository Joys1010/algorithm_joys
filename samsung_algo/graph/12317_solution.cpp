struct node {
	int data;
	int child[5];
};

node tree[101];


void dfs_init(int N, int path[100][2])
{
	//초기화	
	for (int i = 0; i < 101; i++) {
		tree[i].data = 0;
		for (int j = 0; j < 5; j++) {
			tree[i].child[j] = 0;
		}
	}



	for (int i = 0; i < N-1; i++) {
		tree[path[i][0]].data = path[i][0];
		for (int j = 0; j < 5; j++) {
			if (tree[path[i][0]].child[j] == 0) {
				tree[path[i][0]].child[j] = path[i][1];
				break;
			}
		}
	}
}

int king;
int my_dfs(int n);

int dfs(int n)
{
	int ans = 0;
	king = 0;
    
	king = n;
	ans = my_dfs(n);
	return ans;
}

int my_dfs(int n) {
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		if (tree[n].child[0] == 0) {
			return -1;
		}
		else if (tree[n].child[i] != 0) {
			if (tree[n].child[i] > king) {
				return tree[n].child[i];
			}
			else {
				ans = my_dfs(tree[n].child[i]);
				if (ans > n) {
					return ans;
				}
			}
		}
	}
	return -1;
}
