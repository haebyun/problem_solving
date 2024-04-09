#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, res;
priority_queue<int> pqMax, pqMin;

void Solve() {
    while (pqMax.size() > 1) {
        int a = pqMax.top();
        pqMax.pop();
        int b = pqMax.top();
        pqMax.pop();
        if (a * b > a + b) {
            res += (a * b);
        } else {
            res += (a + b);
        }
    }
    while (pqMin.size() > 1) {
        int a = -pqMin.top();
        pqMin.pop();
        int b = -pqMin.top();
        pqMin.pop();
        if (a * b > a + b) {
            res += (a * b);
        } else {
            res += (a + b);
        }
    }
    if (!pqMax.empty() && !pqMin.empty()) {
        int a = pqMax.top();
        pqMax.pop();
        int b = -pqMin.top();
        pqMin.pop();
        if (a * b > a + b) {
            res += (a * b);
        } else {
            res += (a + b);
        }
    } else if (!pqMax.empty()) {
        res += pqMax.top();
        pqMax.pop();
    } else if (!pqMin.empty()) {
        res -= pqMin.top();
        pqMin.pop();
    }
    cout << res;
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num > 0) {
            pqMax.push(num);
        } else {
            pqMin.push(-num);
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
