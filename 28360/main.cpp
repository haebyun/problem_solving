#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
float res;
vector<int> v[51];
vector<float> tmp;

void Solve() {
    for (int cur = 1; cur <= N; cur++) {
        int total = v[cur].size();
        if (!total) {
            continue;
        }
        float cmp = tmp[cur] / (float) total;
        tmp[cur] = 0;
        for (int i = 0; i < total; i++) {
            int child = v[cur][i];
            tmp[child] += cmp;
        }
    }
    for (int i = 1; i <= N; i++) {
        res = max(res, tmp[i]);
    }
    cout << res << '\n';
}

void Init() {
    cin >> N >> M;
    tmp.resize(N + 1);
    tmp[1] = 100;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
