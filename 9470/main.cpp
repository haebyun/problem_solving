#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, K, M, P, res_cnt;
vector<int> v[1001];
int in[1001], Strahler[1001], cnt[1001];
queue<int> q;

void Solve() {
    for (int i = 1; i <= M; i++) {
        if (!in[i]) {
            q.push(i);
            Strahler[i] = 1;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next: v[cur]) {
            if (Strahler[next] < Strahler[cur]) {
                Strahler[next] = Strahler[cur];
                cnt[next]=1;
            }
            else if(Strahler[next]==Strahler[cur]) {
                cnt[next]++;
            }
            in[next]--;
            if (!in[next]) {
                if(cnt[next]>=2) {
                    Strahler[next]++;
                }
                q.push(next);
            }
        }
    }
    cout << res_cnt << ' ' << Strahler[M] << '\n';
}

void Init() {
    cin >> K >> M >> P;
    for (int i = 1; i <= M; i++) {
        v[i] = vector<int>();
        in[i] = 0;
        cnt[i] = 0;
        Strahler[i] = 0;
    }
    res_cnt++;
    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
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
