#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 1000000000

int N;
string str;
vector<int> dp;

bool canStep(char a, char b) {
    if (a == 'B') {
        return b == 'O';
    }
    if (a == 'O') {
        return b == 'J';
    }
    if (a == 'J') {
        return b == 'B';
    }
    return false;
}

int DP(int a) {
    if (dp[a] < INF) {
        return dp[a];
    }
    for (int i = a + 1; i < N; i++) {
        if (canStep(str[a], str[i])) {
            dp[a] = min(dp[a], (i - a) * (i - a) + DP(i));
        }
    }
    return dp[a];
}

void Solve() {
    for (int i = N - 1; i >= 0; i--) {
        DP(i);
    }
    if (dp[0] >= INF) {
        cout << -1 << '\n';
        return;
    }
    cout << dp[0] << '\n';
}

void Init() {
    cin >> N >> str;
    dp.resize(N + 1, INF);
    dp[N - 1] = 0;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
