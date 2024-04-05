#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Infor {
public:
    int x;
    int y;
    int cmp;
};

int N, M, Map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[101][101];
deque<Infor> dq;

void Solve() {
    dq.push_back({1, 1, 0});
    visited[1][1] = true;
    while (!dq.empty()) {
        int x = dq.front().x;
        int y = dq.front().y;
        int cmp = dq.front().cmp;
        dq.pop_front();

        if (x == N && y == M) {
            cout << cmp << '\n';
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > N || ny > M) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            visited[ny][nx] = true;
            if (!Map[ny][nx]) {
                dq.push_front({nx, ny, cmp});
            } else {
                dq.push_back({nx, ny, cmp + 1});
            }
        }
    }
}

void Init() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            char ch;
            cin >> ch;
            Map[i][j] = ch - '0';
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
