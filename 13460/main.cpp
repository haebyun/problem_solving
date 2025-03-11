#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int N, M, cnt{-1};
pair<int, int> R_start, B_start, tar;
char Map[11][11];
set<pair<pair<int, int>, pair<int, int>>> visited; //pair<R, B>
queue<pair<pair<int, int>, pair<int, int>>> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

pair<int, int> move(int x, int y, int d) {
    while (true) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (make_pair(nx, ny) == tar) {
            return {nx, ny};
        }
        if (Map[ny][nx] != '.') {
            return {x, y};
        }
        x = nx;
        y = ny;
    }
}

pair<pair<int, int>, pair<int, int>> move_func(pair<int, int> R, pair<int, int> B, int d) {
    bool red_first = false;

    if (d == 0) { // 위
        red_first = (R.second < B.second);
    } else if (d == 1) { // 오른쪽
        red_first = (R.first > B.first);
    } else if (d == 2) { // 아래
        red_first = (R.second > B.second);
    } else { // 왼쪽
        red_first = (R.first < B.first);
    }

    if (red_first) {
        // 빨간 구슬 먼저 이동
        R = move(R.first, R.second, d);

        if (R == tar) {
            // 빨간 구슬이 목표에 도달했으면 파란 구슬만 이동
            B = move(B.first, B.second, d);
            return {R, B};
        }

        // 빨간 구슬을 맵에 임시로 표시해 파란 구슬 이동에 영향을 주도록 함
        Map[R.second][R.first] = 'R';
        B = move(B.first, B.second, d);
        Map[R.second][R.first] = '.';
    } else {
        // 파란 구슬 먼저 이동
        B = move(B.first, B.second, d);

        // 파란 구슬을 맵에 임시로 표시
        Map[B.second][B.first] = 'B';
        R = move(R.first, R.second, d);
        Map[B.second][B.first] = '.';
    }

    return {R, B};
}


void Solve() {
    visited.insert({R_start, B_start});
    q.push({R_start, B_start});
    while (!q.empty()) {
        int q_size = q.size();
        cnt++;
        for (int k = 0; k < q_size; k++) {
            pair<int, int> R = q.front().first;
            pair<int, int> B = q.front().second;
            q.pop();

            if (R == tar) {
                cout << cnt << '\n';
                return;
            }
            for (int i = 0; i < 4; i++) {
                pair<pair<int, int>, pair<int, int>> nRB = move_func(R, B, i);
                if (visited.find(nRB) != visited.end()) {
                    continue;
                }
                if(nRB.second == tar) {
                    continue;
                }
                q.push({nRB.first, nRB.second});
                visited.insert({nRB.first, nRB.second});
            }
        }
    }
    cout << -1 << '\n';
}

void Init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'R') {
                R_start = {j, i};
                Map[i][j] = '.';
            } else if (Map[i][j] == 'B') {
                B_start = {j, i};
                Map[i][j] = '.';
            } else if (Map[i][j] == 'O') {
                tar = {j, i};
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
