#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, cnt, vol;
int Map[501][501];
bool visited[501][501];
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int start_x, int start_y) {
    cnt++;
    q.push({start_x, start_y});
    visited[start_y][start_x] = true;
    int cmp{0};
    while (!q.empty()) {
        cmp++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                continue;
            }
            if (!Map[ny][nx]) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            q.push({nx, ny});
            visited[ny][nx] = true;
        }
    }
    vol = max(vol, cmp);
}

void Solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Map[i][j] && !visited[i][j]) {
                BFS(j, i);
            }
        }
    }
    cout << cnt << '\n' << vol;
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
