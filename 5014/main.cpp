#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool visited[1000001];
queue<int> q;
int dx[2];

void BFS(int start) {
	visited[start] = true;
	q.push(start);
	int cnt{0};
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int x = q.front();
			q.pop();

			if (x == G) {
				cout << cnt << '\n';
				return;
			}
			for (int j = 0; j < 2; j++) {
				int nx = x + dx[j];
				if (nx < 1 || nx > F) {
					continue;
				}
				if (visited[nx]) {
					continue;
				}
				q.push(nx);
				visited[nx] = true;
			}
		}
		cnt++;
	}
	cout << "use the stairs" << '\n';
}

void Solve() {
	BFS(S);
}

void Init() {
	cin >> F >> S >> G >> U >> D;
	dx[0] = U;
	dx[1] = -D;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
