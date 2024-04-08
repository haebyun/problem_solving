#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, res, cnt[27];
string str[11];
vector<int> v;

bool cmp(int a, int b) {
    return a > b;
}

void Solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < str[i].size(); j++) {
            char c = str[i][j];
            cnt[c - 'A'] += (int) pow(10, str[i].size() - j - 1);
        }
    }
    for (int i = 0; i < 27; i++) {
        if (cnt[i] > 0) {
            v.push_back(cnt[i]);
        }
    }
    sort(v.begin(), v.end(), cmp);
    int n{9};
    for (int i: v) {
        res += (i * n);
        n--;
    }
    cout << res << '\n';
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> str[i];
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
