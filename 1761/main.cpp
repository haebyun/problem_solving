#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 16;
int N, M, res, root {1};
vector<vector<pair<int, int>>> v;
vector<pair<int, int>> tar;
int depth[40001];
int parent[40001][MAX];
int dis[40001];

void setNodesDepth(int cur) {
    for(pair<int, int> p: v[cur]) {
        int node = p.first;
        int distance = p.second;
        if(depth[node]==-1) {
            parent[node][0] = cur;
            depth[node] = depth[cur]+1;
            dis[node] = dis[cur]+distance;
            setNodesDepth(node);
        }
    }
}

void setNodesParent() {
    for(int k = 1; k < MAX; k++) {
        for(int cur = 1; cur <= N; cur++) {
            parent[cur][k] = parent[parent[cur][k-1]][k-1];
        }
    }
}

void update(int& cur, int diff) {
    for(int i=0; i<MAX; i++) {
        if(diff & (1<<i)) {
            cur = parent[cur][i];
        }
    }
}

void func(int& a, int& b) {
    for(int i = MAX-1; i >= 0; i--) {
        if(parent[a][i]!= parent[b][i]) {
            a=parent[a][i];
            b=parent[b][i];
        }
    }
}

int LCA(int a, int b) {
    //deeperNode = a
    if(depth[a] < depth[b]) {
        swap(a, b);
    }
    res = dis[a]+dis[b];
    int diff = depth[a]-depth[b];
    update(a, diff);

    if(a==b) {
        return res-2*dis[a];
    }
    func(a,b);
    a=parent[a][0];
    return res-2*dis[a];
}

void solve() {
    setNodesDepth(root);
    setNodesParent();
    for(pair<int, int> p: tar) {
        cout << LCA(p.first, p.second) << '\n';
    }
}

void init() {
    cin >> N;
    v.resize(N+1);
    for(int i = 0; i <= N; i++) {
        depth[i] = -1;
    }
    depth[root] = 0;
    for(int i = 0; i < N-1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        v[a].push_back({b, d});
        v[b].push_back({a, d});
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
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
