#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
vector<int> v, cmp;
map<int, int> m;

void switchLoc(int cur, int idx) {
    for (int i = idx; i > cur; i--) {
        m[v[i]] = i - 1;
        m[v[i - 1]] = i;
        swap(v[i], v[i - 1]);
    }
}

void Solve() {
    int cur{0};
    while (cur < N && M) {
        int curVal = v[cur];
        for (int i = 0; i < N; i++) {
            if (cmp[i] == curVal) {
                break;
            }
            if (m[cmp[i]] < cur) {
                continue;
            }
            if (m[cmp[i]] - cur <= M) {
                M -= (m[cmp[i]] - cur);
                switchLoc(cur, m[cmp[i]]);
                break;
            }
        }
        cur++;
    }
    for (int i: v) {
        cout << i << " ";
    }
}

bool sortCmp(int &a, int &b) {
    return a > b;
}

void Init() {
    cin >> N;
    v.resize(N);
    cmp.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        cmp[i] = v[i];
        m.insert({v[i], i});
    }
    cin >> M;
    sort(cmp.begin(), cmp.end(), sortCmp);
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
