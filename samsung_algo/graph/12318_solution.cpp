#define MAX_QUEUE_SIZE 101

struct my_node {
	int x;
	int y;
	int distance;
};

my_node queue[MAX_QUEUE_SIZE];
int front_pos = 0;
int back_pos = 0;

int my_map[11][11];
int visited[11][11];

int isFull() {
	if (back_pos == MAX_QUEUE_SIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

int isEmpty() {
	if (front_pos == back_pos) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(int x, int y, int distance) {
	if (!isFull()) {
		queue[back_pos].x = x;
		queue[back_pos].y = y;
		queue[back_pos].distance = distance;
	}
	back_pos++;
}

void pop() {
	front_pos++;
}

void bfs_init(int N, int map[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			my_map[i+1][j+1] = map[i][j];
		}
	}
};
int bfs(int x1, int y1, int x2, int y2) {

	front_pos = 0;
	back_pos = 0;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			visited[i][j] = 0;
		}
	}

	int d = 0;
	int x, y;
	push(x1, y1, d);
	while (!isEmpty()) {
		x = queue[front_pos].x;
		y = queue[front_pos].y;
		d = queue[front_pos].distance;
		visited[y][x] = 1;
		if (x == x2 && y == y2) {
			return d;
		}
		pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (x + j > 0 && x + j < 11 && y + i > 0 && y + i < 11) { //map 안에 위치
					if (i+j == 1 || i+j == -1) {
						if (my_map[y + i][x + j] == 0 && visited[y+i][x+j] != 1) {
							push(x + j, y + i, d + 1);
							visited[y + i][x + j] = 1;
						}
					}
				}
			}
		}
	}
		return -1;
};


