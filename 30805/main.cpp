#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M;
priority_queue<pair<int, int>> qA, qB;
vector<int> res;

void recur(int AIdx, int BIdx) {
    if (qA.empty() || qB.empty()) {
        return;
    }
    int tmpAIdx = -qA.top().second;
    int tmpBIdx = -qB.top().second;
    if (qA.top().first == qB.top().first) {
        if (tmpAIdx > AIdx && tmpBIdx > BIdx) {
            res.push_back(qA.top().first);
            qA.pop();
            qB.pop();
            recur(tmpAIdx, tmpBIdx);
        } else if (tmpAIdx < AIdx) {
            qA.pop();
            recur(AIdx, BIdx);
        } else if (tmpBIdx < BIdx) {
            qB.pop();
            recur(AIdx, BIdx);
        }
    } else if (qA.top().first > qB.top().first) {
        qA.pop();
        recur(AIdx, BIdx);
    } else {
        qB.pop();
        recur(AIdx, BIdx);
    }
}

void Solve() {
    recur(-1, -1);
    cout << res.size() << '\n';
    for (int i: res) {
        cout << i << ' ';
    }
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        qA.push({num, -i});
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        qB.push({num, -i});
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
