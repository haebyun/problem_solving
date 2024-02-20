#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
int Map[21][21];
vector<int> orders, dice(7);
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void south() {
	dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
}

void north() {
	dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
}

void east() {
	dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
}

void west() {
	dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
}

void roll(int order) {
	switch (order) {
		case 0: east();
			break;
		case 1: west();
			break;
		case 2: north();
			break;
		case 3: south();
			break;
		default: break;
	}
}

void Solve() {
	for (int i : orders) {
		int order = i - 1;
		int nx = x + dx[order];
		int ny = y + dy[order];

		if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
			continue;
		}
		roll(order);
		cout << dice[1] << '\n';
		if (!Map[ny][nx]) {
			Map[ny][nx] = dice[6];
		} else {
			dice[6] = Map[ny][nx];
			Map[ny][nx] = 0;
		}
		x = nx;
		y = ny;
	}
}

void Init() {
	cin >> N >> M >> y >> x >> K;
	orders.resize(K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> orders[i];
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
