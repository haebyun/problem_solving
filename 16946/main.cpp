#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, res[1001][1001];
bool visited[1001][1001], Map[1001][1001];
queue<pair<int, int>> q, plusQ;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int start_x, int start_y) {
	int tmp{1};
	visited[start_y][start_x] = true;
	q.push({start_x, start_y});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > M || ny > N) {
				continue;
			}
			if (visited[ny][nx]) {
				continue;
			}
			if (Map[ny][nx]) {
				plusQ.push({nx, ny});
				visited[ny][nx] = true;
				continue;
			}
			tmp++;
			q.push({nx, ny});
			visited[ny][nx] = true;
		}
	}
	while (!plusQ.empty()) {
		int x = plusQ.front().first;
		int y = plusQ.front().second;
		plusQ.pop();
		res[y][x] += tmp;
		res[y][x] %= 10;
		visited[y][x] = false;
	}
}

void Solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j] && !Map[i][j]) {
				BFS(j, i);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << res[i][j] % 10;
		}
		cout << '\n';
	}
}

void Init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char ch;
			cin >> ch;
			if (ch == '1') {
				res[i][j] = 1;
				Map[i][j] = true;
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
