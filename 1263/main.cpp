#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
priority_queue<pair<int,int>> pq;

void Solve(){
    int cur = pq.top().first;
    while(!pq.empty()) {
        int due = pq.top().first;
        int take = pq.top().second;
        pq.pop();

        if(cur < due) {
            cur -= take;
        } else {
            cur = due - take;
        }
        if(cur < 0) {
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<cur<<'\n';
}

void Init(){
    cin>>N;
    for(int i=0; i<N; i++) {
        int T, S; cin>>T>>S;
        pq.push({S, T});
    }
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
