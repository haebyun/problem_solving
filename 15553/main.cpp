#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, T, res;
priority_queue<int> pq;

void Solve() {
    while (T > 1) {
        res++;
        pq.pop();
        T--;
    }
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res + 1 << '\n';
}

void Init() {
    cin >> N >> T;
    int a;
    cin >> a;
    for (int i = 1; i < N; i++) {
        int b;
        cin >> b;
        pq.push(b - a);
        a = b;
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
