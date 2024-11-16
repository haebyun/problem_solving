#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, res;
vector<int> v;

void Solve() {
    for(int i=1; i<N-1; i++) {
        res = max(res, max(abs((v[0] + v[i] + v[i + 1]) - v[i] * 3), abs((v[i-1] + v[i] + v[N-1]) - v[i] * 3)));
    }
    cout << res << '\n';
}

void Init() {
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}