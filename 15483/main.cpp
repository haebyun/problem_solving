#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];
string from, to;

void Solve() {
    for (int i = 1; i <= from.size(); i++) {
        for (int j = 1; j <= to.size(); j++) {
            if (from[i-1] == to[j-1]) {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    cout << dp[from.size()][to.size()];
}

void Init() {
    cin >> from >> to;
    for (int i = 1; i <= max(from.size(), to.size()); i++) {
        dp[0][i] = i;
        dp[i][0] = i;
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
