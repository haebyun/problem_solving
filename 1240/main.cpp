#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, res;
vector<pair<int, int>> v[1001];
bool visited[1001];

void DFS(int cur, int target, int d) {
    visited[cur] = true;
    if (cur == target) {
        res = d;
    }
    for (auto &p: v[cur]) {
        int next = p.first;
        int cost = p.second;
        if (!visited[next]) {
            DFS(next, target, d + cost);
        }
    }
}

void Solve() {
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        DFS(a, b, 0);
        cout << res << '\n';
        res = 0;
        for (int j = 0; j <= N; j++) {
            visited[j] = false;
        }
    }
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
