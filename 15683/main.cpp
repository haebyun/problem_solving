#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 10000000;
const int WALL = 6;

int N, M, res = INF;
int Map[9][9];
int cur = 0;
vector<pair<int, pair<int, int>>> cameras;
bool visited[9][9][9];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<vector<int>>> directions = {
        {},
        {{0}, {1}, {2}, {3}},
        {{0, 2}, {1, 3}},
        {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
        {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}}
};

void updateVisibility(int d, int x, int y, bool flag) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (ny < 1 || nx < 1 || ny > N || nx > M || Map[ny][nx] == WALL) {
        return;
    }
    visited[cur][ny][nx] = flag;
    updateVisibility(d, nx, ny, flag);
}

void calculateResult() {
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (Map[i][j] == 0) {
                bool flag = true;
                for (int k = 0; k < cur; ++k) {
                    if (visited[k][i][j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ++cnt;
                }
            }
        }
    }
    res = min(res, cnt);
}

void BT(int d) {
    if (d == cameras.size()) {
        calculateResult();
        return;
    }
    int x = cameras[d].second.first;
    int y = cameras[d].second.second;
    int type = cameras[d].first;

    for (const auto& dirs : directions[type]) {
        for (int dir : dirs) {
            updateVisibility(dir, x, y, true);
        }
        cur++;
        BT(d + 1);
        cur--;
        for (int dir : dirs) {
            updateVisibility(dir, x, y, false);
        }
    }
}

void solve() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int n = Map[i][j];
            if (n == 0 || n == WALL) {
                continue;
            }
            if (n == 5) {
                for (int k = 0; k < 4; ++k) {
                    updateVisibility(k, j, i, true);
                }
                cur++;
            } else if (n > 0 && n < 5) {
                cameras.push_back({n, {j, i}});
            }
        }
    }
    BT(0);
    cout << res << '\n';
}

void init() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
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
