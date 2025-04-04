#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, K;
long long res;
unordered_map<int, int> m;

void Solve() {
    int prefix{0};
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        prefix += n;
        if (prefix == K) {
            res++;
        }
        res += m[prefix - K];
        m[prefix]++;
    }
    cout << res << '\n';
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
