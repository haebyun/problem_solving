#include <iostream>
#include <queue>

using namespace std;

int N, tmp, res;
priority_queue<int> pq;

void Solve() {
    if (N == 1) {
        cout << 0 << '\n';
        return;
    }
    while (pq.top() >= tmp) {
        int cmp = pq.top();
        pq.pop();
        tmp++;
        pq.push(cmp - 1);
        res++;
    }
    cout << res << '\n';
}

void Init() {
    cin >> N >> tmp;
    for (int i = 0; i < N - 1; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
