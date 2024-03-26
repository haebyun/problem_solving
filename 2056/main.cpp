#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, ans;
vector<int> v[10002], cnt, task, res;
queue<int> q;

void Solve(){
    for(int i=1; i<=N; i++) {
        if(!cnt[i]) {
            q.push(i);
            res[i] = task[i];
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans = max(ans, res[cur]);
        for(int next : v[cur]) {
            cnt[next]--;
            res[next] = max(res[next], res[cur]+task[next]);
            if(!cnt[next]) {
                q.push(next);
            }
        }
    }
    cout<<ans<<'\n';
}

void Init(){
    cin>>N;
    cnt.resize(N+2);
    task.resize(N+2);
    res.resize(N+2);
    for(int i=1; i<=N; i++) {
        int M;
        cin>>task[i]>>M;
        for(int j=0; j<M; j++) {
            int tar; cin>>tar;
            v[i].push_back(tar);
            cnt[tar]++;
        }
    }
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
