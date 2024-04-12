#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, K, res;
bool use[101];
vector<int> order;
set<int> s;
int cnt[101];
int fir[101];

void Solve() {
    for (int i = 0; i < order.size(); i++) {
        int cur = order[i];
        if (use[cur]) {
            cnt[cur]--;
            continue;
        }
        if (N) {
            N--;
            use[cur] = true;
            cnt[cur]--;
            continue;
        }
        res++;
        int tmp{0};
        int idx{0};
        for (auto item: s) {
            if (!cnt[item] && use[item]) {
                tmp = item;
                break;
            }
        }
        if (tmp) {
            use[tmp] = false;
            use[cur] = true;
            cnt[cur]--;
            continue;
        }
        for (int j = i; j < order.size(); j++) {
            int cmp = order[j];
            if (!fir[cmp] && use[cmp]) {
                fir[cmp] = j;
                idx = max(idx, j);
            }
        }
        tmp = order[idx];
        use[tmp] = false;
        use[cur] = true;
        cnt[cur]--;
        for(int j=1; j<=100; j++) {
            fir[j]=false;
        }
    }
    cout << res << '\n';
}

//5 2 3

void Init() {
    cin >> N >> K;
    order.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> order[i];
        s.insert(order[i]);
        cnt[order[i]]++;
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
