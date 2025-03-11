#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
bool visited[51][51];
int Map[51][51], dp[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool is_ok(int x, int y) {
    if (x < 1 || y < 1 || x > M || y > N) {
        return false;
    }
    if (!Map[y][x]) {
        return false;
    }
    return true;
}

int DFS(int x, int y) {
    if (!is_ok(x, y)) {
        return 0;
    }
    if (visited[y][x]) {
        cout << -1 << '\n';
        exit(0);
    }
    if (dp[y][x]) {
        return dp[y][x];
    }
    int tmp{0};
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] * Map[y][x];
        int ny = y + dy[i] * Map[y][x];
        tmp = max(tmp, DFS(nx, ny));
    }
    visited[y][x] = false;
    return dp[y][x] = tmp + 1;
}

void Solve() {
    DFS(1, 1);
    cout << dp[1][1] << '\n';
}

void Init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char ch;
            cin >> ch;
            ch == 'H' ? Map[i][j] = 0 : Map[i][j] = ch - '0';
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
