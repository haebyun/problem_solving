#include <iostream>
#include <vector>

using namespace std;

int N, M, res;
vector<vector<char>> Map;
int dy[3] = {-1, 0, 1};
bool flag;

void link(int x, int y) {
    if (flag) {
        return;
    }
    if (x == M) {
        res++;
        flag = true;
    }
    Map[y][x] = 'x';
    for (int i: dy) {
        int nx = x + 1;
        int ny = y + i;
        if (ny < 1 || ny > N) {
            continue;
        }
        if (Map[ny][nx] == 'x') {
            continue;
        }
        link(nx, ny);
    }
}

void Solve() {
    for (int i = 1; i <= N; i++) {
        link(0, i);
        flag = false;
    }
    cout << res << '\n';
}

void Init() {
    cin >> N >> M;
    Map.resize(N + 1, vector<char>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
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
