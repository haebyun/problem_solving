#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 17;
int N, M, root{1};
vector<vector<int>> v;
vector<pair<int, int>> tar;
int depth[100001];
int parent[100001][MAX];

void setNodesDepth(int cur) {
    for (int p: v[cur]) {
        int node = p;
        if (depth[node] == -1) {
            parent[node][0] = cur;
            depth[node] = depth[cur] + 1;
            setNodesDepth(node);
        }
    }
}

void setNodesParent() {
    for (int k = 1; k < MAX; k++) {
        for (int cur = 1; cur <= N; cur++) {
            parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
        }
    }
}

void update(int &cur, int diff) {
    if (!diff) {
        return;
    }
    int lim = floor(log2(diff));
    diff -= pow(2, lim);
    cur = parent[cur][lim];
    update(cur, diff);
}

void func(int &a, int &b) {
    for (int i = MAX - 1; i >= 0; i--) {
        if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
            break;
        }
    }
}

int LCA(int a, int b) {
    //deeperNode = a
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    update(a, diff);

    if (a == b) {
        return a;
    }

    while (parent[a][0] != parent[b][0]) {
        func(a, b);
    }

    return parent[a][0];
}

void solve() {
    setNodesDepth(root);
    setNodesParent();
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
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
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
