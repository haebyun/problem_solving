#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, cmp;
vector<int> v[1001], cnt, res;
queue<int> q;

void Solve(){
    cmp=2;
	while(!q.empty()) {
        int q_size = q.size();
        for(int i=0; i<q_size; i++) {
            int x = q.front();
            q.pop();

            for(int j=0; j<v[x].size(); j++) {
                int next = v[x][j];
                cnt[next]--;
                if(!cnt[next]) {
                    q.push(next);
                    res[next]=cmp;
                }
            }
        }
        cmp++;
    }
    for(int i=1; i<=N; i++) {
       cout<<res[i]<<' ';
    }
}

void Init(){
	cin>>N>>M;
    res.resize(N+1);
    cnt.resize(N+1);
    for(int i=0; i<M;i++) {
        int a, b; cin>>a>>b;
        v[a].push_back(b);
        cnt[b]++;
    }
    for(int i=1; i<=N; i++) {
        if(!cnt[i]) {
            res[i]=1;
            q.push(i);
        }
    }
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
