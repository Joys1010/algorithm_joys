#define MAX_SIZE 100000
#define INT_MAX 1e9
int node_cnt;
int pop_cnt;
struct my_node {
	int u_id;
	int income;
};

my_node heap[MAX_SIZE];
my_node pop_arr[100000];

int heapSort() {

	int cur = node_cnt;
	while (cur > 0 && heap[cur].income >= heap[(cur - 1) / 2].income) {
		if (heap[cur].income == heap[(cur - 1) / 2].income) {
			if (heap[cur].u_id < heap[(cur - 1) / 2].u_id) { //u_id에 따른 소팅 하기 : u_id가 작으면 위로 올리기
				int tmp_uid = heap[(cur - 1) / 2].u_id;
				int tmp_income = heap[(cur - 1) / 2].income;
				heap[(cur - 1) / 2].u_id = heap[cur].u_id;
				heap[(cur - 1) / 2].income = heap[cur].income;
				heap[cur].u_id = tmp_uid;
				heap[cur].income = tmp_income;
				cur = (cur - 1) / 2;
			}
			else {
				break;
			}
		}
		else {
			int tmp_uid = heap[(cur - 1) / 2].u_id;
			int tmp_income = heap[(cur - 1) / 2].income;
			heap[(cur - 1) / 2].u_id = heap[cur].u_id;
			heap[(cur - 1) / 2].income = heap[cur].income;
			heap[cur].u_id = tmp_uid;
			heap[cur].income = tmp_income;
			cur = (cur - 1) / 2;
		}
		
	}

	return 1;
}

my_node heapPop() {
	if (node_cnt <= 0) {
		my_node tmp;
		tmp.u_id = -1;
		tmp.income = INT_MAX;

		return tmp;
	}

	my_node result = heap[0];

	node_cnt = node_cnt - 1;
	heap[0] = heap[node_cnt];

	int cur = 0;
	while (cur * 2 + 1 < node_cnt) {
		int child;
		if (cur * 2 + 2 == node_cnt) {
			child = cur * 2 + 1;
		}
		else {
			if (heap[cur * 2 + 1].income > heap[cur * 2 + 2].income) {
				child = cur * 2 + 1;
			}
			else if (heap[cur * 2 + 1].income == heap[cur * 2 + 2].income) {
				if (heap[cur * 2 + 1].u_id < heap[cur * 2 + 2].u_id) {
					child = cur * 2 + 1;
				}
				else {
					child = cur * 2 + 2;
				}
			}
			else {
				child = cur * 2 + 2;
			}
		}

		if (heap[cur].income > heap[child].income) {
			break;
		}
		else {
			if (heap[cur].income == heap[child].income) {
				if (heap[cur].u_id > heap[child].u_id) { //지금 uid가 더 클 때만 아래로 내리기(더 늦게 pop 되도록)
					int tmp_uid = heap[cur].u_id;
					int tmp_income = heap[cur].income;

					heap[cur].u_id = heap[child].u_id;
					heap[cur].income = heap[child].income;

					heap[child].u_id = tmp_uid;
					heap[child].income = tmp_income;
					cur = child;
				}
				else {
					break;
				}
			}
			else { //income이 작으면
				int tmp_uid = heap[cur].u_id;
				int tmp_income = heap[cur].income;

				heap[cur].u_id = heap[child].u_id;
				heap[cur].income = heap[child].income;

				heap[child].u_id = tmp_uid;
				heap[child].income = tmp_income;
				cur = child;
			}
		}

		
	}

	return result;

}

int heapPush(int uID, int height) {

	if (node_cnt + 1 > MAX_SIZE) {
		return 0;
	}
	else {
		heap[node_cnt].u_id = uID;
		heap[node_cnt].income = height;

		heapSort();
		node_cnt += 1;

		return 1;
	}

}



void init()
{
	node_cnt = 0;
	pop_cnt = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		heap[i].u_id = 0;
		heap[i].income = 0;
	}
}


void addUser(int uID, int height)
{

	heapPush(uID, height);

}

int getTop10(int result[10])
{

	int cnt = 0;
	
	for (int i = 0; i < 10; i++) {
		pop_arr[i] = heapPop();
		if (pop_arr[i].u_id != -1) {
			result[i] = pop_arr[i].u_id;
			cnt++;
		}
		else {
			result[i] = 0;
		}
		
	}

	for (int i = 0; i < 10; i++) {
		if (pop_arr[i].u_id != -1) {
			heapPush(pop_arr[i].u_id, pop_arr[i].income);
		}
	}

	return cnt;
}
