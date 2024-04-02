#include <iostream>

using namespace std;

int N, M, H, limit;
bool isRight[32][12], isLeft[32][12], isPossible;

bool isDone() {
	for (int i = 1; i <= N; i++) {
		int x = i;
		int y = 1;
		while (y <= H) {
			if (isRight[y][x]) {
				x++;
			} else if (isLeft[y][x]) {
				x--;
			}
			y++;
		}
		if (x != i) {
			return false;
		}
	}
	return true;
}

void BT(int d, int x, int y) {
	if (d > H) {
		return;
	}
	if (d >= limit) {
		if (isDone()) {
			isPossible = true;
		}
		return;
	}
	for (int i = y; i <= H; i++) {
		if (i > y) {
			x = 1;
		}
		for (int j = x; j < N; j++) {
			if (isLeft[i][j] || isRight[i][j] || isRight[i][j + 1]) {
				continue;
			}
			isRight[i][j] = true;
			isLeft[i][j + 1] = true;
			BT(d + 1, j, i);
			isRight[i][j] = false;
			isLeft[i][j + 1] = false;
		}
	}
}

void Solve() {
	for (limit = 0; limit < 4; limit++) {
		BT(0, 1, 1);
		if (isPossible) {
			cout << limit << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

void Init() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		isRight[a][b] = true;
		isLeft[a][b + 1] = true;
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}