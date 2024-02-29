#include <iostream>
using namespace std;

int N, L, Map[102][102], res;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[2][102];

bool isDone(int x, int y, int dir) {
	if (dir == 0 && x == N + 1) {
		return true;
	}
	if (dir == 1 && y == N + 1) {
		return true;
	}
	if (dir == 2 && x == 0) {
		return true;
	}
	if (dir == 3 && y == 0) {
		return true;
	}
	return false;
}

pair<int, int> down(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int cmp = Map[ny][nx];
	for (int i = 1; i < L; i++) {
		nx += dx[dir];
		ny += dy[dir];
		if (cmp != Map[ny][nx]) {
			return {0, 0};
		}
	}
	return {nx, ny};
}

void check(int x, int y, int dir) {
	int tmp = Map[y][x];
	int cnt{1};
	int cmp = dir % 2;
	if (cmp == 0 && visited[cmp][y]) {
		return;
	}
	if (cmp == 1 && visited[cmp][x]) {
		return;
	}
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (isDone(nx, ny, dir)) {
			if (cmp == 0) {
				visited[0][y] = true;
			} else {
				visited[1][x] = true;
			}
			res++;
			return;
		}

		if (tmp == Map[ny][nx]) {
			cnt++;
		} else if (Map[ny][nx] - 1 == tmp && cnt >= L) {
			cnt = 1;
		} else if (Map[ny][nx] + 1 == tmp) {
			pair<int, int> p = down(x, y, dir);
			nx = p.first;
			ny = p.second;
			cnt = 0;
			if (nx == 0 && ny == 0) {
				return;
			}
		} else {
			return;
		}
		tmp = Map[ny][nx];
		x = nx;
		y = ny;
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		check(1, i, 0);
		check(N, i, 2);
		check(i, 1, 1);
		check(i, N, 3);
	}
	cout << res << '\n';
}

void init() {
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j];
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	init();
	solve();
	return 0;
}
