#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, dp[100001], Max;
vector<int> v;

void Solve() {
    for (int i = 1; i <= Max; i++) {
        if (!dp[i]) {
            continue;
        }
        int tmp = i + i;
        while (tmp <= Max) {
            dp[tmp] += dp[i];
            tmp += i;
        }
    }
    for (int i = 0; i < M; i++) {
        cout << dp[v[i]] << ' ';
    }
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        dp[num]++;
    }
    cin >> M;
    v.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> v[i];
        Max = max(Max, v[i]);
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
