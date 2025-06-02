#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
char board[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q, f_q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fireFunc() {
	int q_size = f_q.size();
	for (int k = 0; k < q_size; k++) {
		int x = f_q.front().first;
		int y = f_q.front().second;
		f_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
				continue;
			}
			if (board[ny][nx] != '.') {
				continue;
			}
			board[ny][nx] = 'F';
			f_q.push({nx, ny});
		}
	}
}

int BFS() {
	int cnt{0};
	while (!q.empty()) {
		int q_size = q.size();
		fireFunc();
		for (int k = 0; k < q_size; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
					return cnt + 1;
				}
				if (visited[ny][nx]) {
					continue;
				}
				if (board[ny][nx] != '.') {
					continue;
				}
				visited[ny][nx] = true;
				q.push({nx, ny});
			}
		}
		cnt++;
	}
	return -1;
}

void Solve() {
	int res = BFS();
	res == -1 ? cout << "IMPOSSIBLE" : cout << res;
}

void Init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				f_q.push({j, i});
			} else if (board[i][j] == 'J') {
				visited[i][j] = true;
				q.push({j, i});
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
