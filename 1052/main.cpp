#include <iostream>

using namespace std;

int N, K;

int func(int n) {
    int i = 1;
    for (; i <= n; i *= 2) {}
    return i / 2;
}

void Solve() {
    int cnt{0};
    int tmp;
    while (cnt < K) {
        cnt++;
        tmp = func(N);
        N -= tmp;
    }
    N == 0 ? cout << 0 << '\n' : cout << tmp - N << '\n';
}

void Init() {
    cin >> N >> K;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}

