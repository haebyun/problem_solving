#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int> v, res;
stack<int> s;
priority_queue<pair<int, int>> pq;

void Solve() {
    int sum{0};
    for (int i = N; i > 0; i--) {
        if (s.empty()) {
            break;
        }
        sum += v[i];
        if (s.top() == i) {
            pq.push({sum, -i});
            s.pop();
            sum = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        if(pq.empty()) {
            break;
        }
        res.push_back(-pq.top().second);
        pq.pop();
    }
    sort(res.begin(), res.end());
    for (int i: res) {
        cout << i << '\n';
    }
}

void Init() {
    cin >> N >> M >> K;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < K; i++) {
        int n;
        cin >> n;
        s.push(n);
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
