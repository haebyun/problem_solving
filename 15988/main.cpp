#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MOD 1000000009

int T, N, Max{0};
long long dp[1000001] = {0, 1, 2, 4, };
vector<int> order;

void DP() {
    for(int i=4; i<=Max; i++) {
        dp[i] = (dp[i-1] % MOD + dp[i-2] % MOD + dp[i-3] % MOD) % MOD;
    }
}

void Solve() {
    DP();
    for (int n: order) {
        cout << dp[n] << '\n';
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N;
        order.push_back(N);
        Max = max(Max, N);
    }
    Solve();
    return 0;
}
