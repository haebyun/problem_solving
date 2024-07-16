#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, N, M, sec, spa;
vector<vector<char>> v;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int start_x, int start_y) {
    q.push({start_x, start_y});
    visited[start_y][start_x] = true;
    spa++;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                continue;
            }
            if (v[ny][nx] == '#') {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            spa++;
            q.push({nx, ny});
            visited[ny][nx] = true;
        }
    }
}

void Solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && v[i][j] == '.') {
                sec++;
                BFS(j, i);
            }
        }
    }
    if (sec == 1) {
        cout << sec << " section, ";
    } else {
        cout << sec << " sections, ";
    }
    if (spa == 1) {
        cout << spa << " space" << '\n';
    } else {
        cout << spa << " spaces" << '\n';
    }
}

void Init() {
    cin >> N >> M;
    v.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        v[i].resize(M, '#');
        visited[i].resize(M, false);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }
}

void Reset() {
    v = vector<vector<char>>();
    visited = vector<vector<bool>>();
    spa = 0;
    sec = 0;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        Init();
        Solve();
        Reset();
    }
    return 0;
}
