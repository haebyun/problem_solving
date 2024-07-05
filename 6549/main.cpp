#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N;
vector<int> h;
stack<int> s;

void Solve() {
    long long max_product{0};
    for (int i = 0; i <= N; i++) {
        if (i < N) {
            cin >> h[i];
        }
        while (!s.empty() && h[i] < h[s.top()]) {
            int height = h[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            max_product = max(max_product, (long long) height * width);
        }
        s.push(i);
    }
    cout << max_product << '\n';
}

void Init() {
    cin >> N;
    if (!N) {
        return;
    }
    h.resize(N + 1);
    h[N] = 0;
    s = stack<int>();
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    while (true) {
        Init();
        if (!N) {
            break;
        }
        Solve();
    }
    return 0;
}
