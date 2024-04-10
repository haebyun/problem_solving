#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
long long res;
vector<pair<int, int>> v;
vector<int> w;
priority_queue<int> pq;

void Solve() {
    sort(w.begin(), w.end());
    sort(v.begin(), v.end());
    int idx{0};
    for(int i=0; i<K; i++) {
        int tmp = w[i];
        while(idx<N){
            int weight = v[idx].first;
            int value = v[idx].second;
            if (weight > tmp) {
                break;
            }
            idx++;
            pq.push(value);
        }
        if(!pq.empty()){
            res+=(long long)pq.top();
            pq.pop();
        }
    }
    cout<<res<<'\n';
}

void Init() {
    cin >> N >> K;
    v.resize(N);
    w.resize(K);
    for (int i = 0; i < N; i++) {
        cin>>v[i].first>>v[i].second;
    }
    for (int i = 0; i < K; i++) {
        cin>>w[i];
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
