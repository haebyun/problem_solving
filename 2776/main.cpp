#include <iostream>
#include <set>

using namespace std;

int T, N, M;
set<int> s;

void Solve() {
    for (int i = 0; i < M; i++) {
        int tar;
        cin >> tar;
        s.find(tar) != s.end() ? cout << 1 << '\n' : cout << 0 << '\n';
    }
}

void Init() {
    s = set<int>();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    cin >> M;
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
