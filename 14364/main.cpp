#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int T, N, Sum, cnt{0};
priority_queue<pair<int, char>> pq;
vector<string> res;
string str;

void pushProcess(pair<int, char> p) {
    pq.pop();
    str += p.second;
    p.first--;
    if (p.first) {
        pq.push(p);
    }
    Sum--;
}

void Solve() {
    while (!pq.empty()) {
        str = "";
        pushProcess(pq.top());
        if (pq.top().first * 2 > Sum) {
            pushProcess(pq.top());
        }
        res[cnt] += str + " ";
    }
    cout << res[cnt] << '\n';
    cnt++;
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        Sum += n;
        pq.push({n, 'A' + i});
    }
    cout << "Case #" << cnt + 1 << ": ";
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> T;
    res.resize(T, "");
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}
