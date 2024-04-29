#include <iostream>
#include <cstring>

using namespace std;

string tar, br[2];
int dp[101][2][21];

int DP(int cur, int curBridge, int cnt) {
    if (cnt == tar.size()) {
        return 1;
    }
    if (dp[cur][curBridge][cnt] != -1) {
        return dp[cur][curBridge][cnt];
    }
    dp[cur][curBridge][cnt] = 0;
    for (int i = cur; i < br[0].size(); i++) {
        if (br[curBridge][i] == tar[cnt]) {
            dp[cur][curBridge][cnt] += DP(i + 1, !curBridge, cnt + 1);
        }
    }
    return dp[cur][curBridge][cnt];
}

void Solve() {
    cout << DP(0, 0, 0) + DP(0, 1, 0);
}

void Init() {
    cin >> tar >> br[0] >> br[1];
    memset(dp, -1, sizeof(dp));
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
