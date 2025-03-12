#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K, A, B;
vector<int> node[1001];
bool visited[1001];
string codes[1001];

int get_hamming(const string &a, const string &b) {
    int dist = 0;
    for (int i = 0; i < K; i++) {
        if (a[i] != b[i]) dist++;
    }
    return dist;
}

void Solve() {
    queue<pair<int, vector<int>>> q;
    q.push({A, vector<int>(1, A)});
    visited[A] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        vector<int> cur_v = q.front().second;
        q.pop();

        if (cur == B) {
            for (int i: cur_v) {
                cout << i << " ";
            }
            return;
        }
        for (int i = 0; i < node[cur].size(); i++) {
            int next = node[cur][i];
            if (visited[next]) {
                continue;
            }
            vector<int> next_v = cur_v;
            next_v.push_back(next);
            q.push({next, next_v});
            visited[next] = true;
        }
    }
    cout << -1 << '\n';
}

void Init() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> codes[i];
    }
    cin >> A >> B;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (get_hamming(codes[i], codes[j]) == 1) {
                node[i].push_back(j);
                node[j].push_back(i);
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
