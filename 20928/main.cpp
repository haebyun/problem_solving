#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, res, Max;
vector<pair<int, int>> v;

void Solve() {
    if (Max < M) {
        cout << -1 << '\n';
        return;
    }
    pair<int, int> cur = v[0];
    int idx{1};
    bool flag{false};
    while (cur.second < M) {
        if (idx >= N || flag) {
            cout << -1 << '\n';
            return;
        }
        pair<int, int> cmp = v[idx];
        flag = true;
        while (idx < N && cur.second >= v[idx].first) {
            flag = false;
            if (v[idx].second > cmp.second) {
                cmp = v[idx];
            }
            idx++;
        }
        cur = cmp;
        res++;
    }
    if (flag) {
        cout << -1 << '\n';
        return;
    }
    cout << res << '\n';
}

void Init() {
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v[i].second = v[i].first + x;
        Max = max(Max, v[i].second);
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
