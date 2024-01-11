#include <iostream>

using namespace std;

int N;
int dp[1001] = {0, 1, 2, 1, 1,};

void Solve() {
    for (int i = 5; i <= N; i++) {
        if (dp[i - 1] == 1 && dp[i - 3] == 1 && dp[i - 4] == 1) {
            dp[i] = 2;
        } else {
            dp[i] = 1;
        }
    }
    dp[N] == 1 ? cout << "SK" << '\n' : cout << "CY" << '\n';
}

void Init() {
    cin >> N;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}