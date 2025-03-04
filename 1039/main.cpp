#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string N;
int K, res{-1};
vector<int> v;
set<int> s[10];

int cal_cum(vector<int> &cur) {
    int tmp{0};
    for (int i: cur) {
        tmp = tmp * 10 + i;
    }
    return tmp;
}

void BT(int d, vector<int> cur) {
    int tmp = cal_cum(cur);
    if (d == K) {
        res = max(res, tmp);
        return;
    }
    for (int i = 0; i < cur.size() - 1; i++) {
        for (int j = i + 1; j < cur.size(); j++) {
            if (!i && !cur[j]) {
                continue;
            }
            vector<int> par = cur;
            swap(par[i], par[j]);
            int cmp = cal_cum(par);
            if (s[d].find(cmp) != s[d].end()) {
                continue;
            }
            BT(d + 1, par);
            s[d].insert(cmp);
        }
    }
}

void Solve() {
    BT(0, v);
    cout << res << '\n';
}

void Init() {
    cin >> N >> K;
    for (char c: N) {
        v.push_back(c - '0');
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
