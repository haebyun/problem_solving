#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, Map[101][71], maxHeight;
queue<pair<int, int>> q;
bool visited[101][71], isHeight[501];
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void BFS(int start_x, int start_y) {
    visited[start_y][start_x] = true;
    q.push({start_x, start_y});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                continue;
            }
            if (!Map[ny][nx] || Map[ny][nx] > Map[y][x]) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            visited[ny][nx] = true;
            q.push({nx, ny});
        }
    }
}

void Solve() {
    int res{0};
    for (int h = maxHeight; h > 0; h--) {
        if (!isHeight[h]) {
            continue;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && Map[i][j] == h) {
                    BFS(j, i);
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
            maxHeight = max(maxHeight, Map[i][j]);
            isHeight[Map[i][j]] = true;
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
