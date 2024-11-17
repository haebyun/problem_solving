#include <iostream>

using namespace std;

int T, cap[12][12], res;
bool visited[12];

void BT(int d, int cur) {
    if (d > 11) {
        res = max(res, cur);
    }
    for (int i = 1; i <= 11; i++) {
        if (!visited[i] && cap[d][i]) {
            visited[i] = true;
            cur += cap[d][i];
            BT(d + 1, cur);
            cur -= cap[d][i];
            visited[i] = false;
        }
    }
}

void Solve() {
    BT(1, 0);
    cout << res << '\n';
}

void Init() {
    res = 0;
    for (int i = 1; i <= 11; i++) {
        for (int j = 1; j <= 11; j++) {
            cin >> cap[i][j];
        }
        visited[i] = false;
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}
