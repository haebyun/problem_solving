#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 17;
int N, M, res, root{1};
vector<vector<pair<int, int>>> v;
vector<pair<int, int>> tar;
int depth[40001];
pair<int, int> parent[40001][MAX];

void getNodesDepth(int cur) {
    for (pair<int, int> p: v[cur]) {
        int node = p.first;
        int distance = p.second;
        if (depth[node] == -1) {
            parent[node][0].first = cur;
            parent[node][0].second = distance;
            depth[node] = depth[cur] + 1;
            getNodesDepth(node);
        }
    }
}

void getNodesParent() {
    for (int k = 1; k < MAX; k++) {
        for (int cur = 1; cur <= N; cur++) {
            parent[cur][k].first = parent[parent[cur][k - 1].first][k - 1].first;
            parent[cur][k].second = parent[parent[cur][k - 1].first][k - 1].second + parent[cur][k - 1].second;
        }
    }
}

void update(int &cur, int diff) {
    if (!diff) {
        return;
    }
    int lim = floor(log2(diff));
    diff -= pow(2, lim);
    res += parent[cur][lim].second;
    cur = parent[cur][lim].first;
    update(cur, diff);
}

void func(int &a, int &b) {
    for (int i = MAX - 1; i >= 0; i--) {
        if (parent[a][i].first != 0 && parent[a][i].first != parent[b][i].first) {
            update(a, pow(2, i));
            update(b, pow(2, i));
            break;
        }
    }
}

int LCA(int a, int b) {
    //deeperNode = a
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    res = 0;
    int diff = depth[a] - depth[b];
    update(a, diff);

    if (a == b) {
        return res;
    }

    while (parent[a][0].first != parent[b][0].first) {
        func(a, b);
    }
    res += (parent[a][0].second + parent[b][0].second);
    return res;
}

void solve() {
    getNodesDepth(root);
    getNodesParent();
    for (pair<int, int> p: tar) {
        cout << LCA(p.first, p.second) << '\n';
    }
}

void init() {
    cin >> N;
    v.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        depth[i] = -1;
    }
    depth[root] = 0;
    for (int i = 0; i < N - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        v[a].push_back({b, d});
        v[b].push_back({a, d});
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        tar.push_back({a, b});
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    init();
    solve();
    return 0;
}
