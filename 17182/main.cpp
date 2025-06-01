#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, res{2000000000};
int dis[11][11];
bool visited[11];

void BT(int d, vector<int> &v) {
    if (d == N - 1) {
        int tmp{0};
        for (int i = 0; i < v.size() - 1; i++) {
            tmp += dis[v[i]][v[i + 1]];
        }
        res = min(res, tmp);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(i);
            BT(d + 1, v);
            v.pop_back();
            visited[i] = false;
        }
    }
}

void Solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    visited[K] = true;
    vector<int> v;
    v.push_back(K);
    BT(0, v);
    cout << res << '\n';
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dis[i][j];
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
