#include <iostream>
#include <stack>
using namespace std;
#define ll long long

int N;
ll res{0};
stack<ll> s;

ll func(int k) {
    ll n = s.top();
    ll cnt{0};
    while (!s.empty() && n == s.top()) {
        cnt++;
        s.pop();
    }
    if (s.empty()) {
        return ((cnt - k) * (cnt + 1 - k)) / 2;
    }
    return ((cnt + 1 - k) * (cnt + 2 - k)) / 2 - (1 - k);
}

void solve() {
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (s.empty()) {
            s.push(num);
            continue;
        }
        if (s.top() < num) {
            while (!s.empty() && s.top() < num) {
                res += func(0);
            }
        }
        s.push(num);
    }
    while (!s.empty() && s.size() != 1) {
        res += func(1);
    }
    cout << res << '\n';
}

void init() {
    cin >> N;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    init();
    solve();
    return 0;
}
