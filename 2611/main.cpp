#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<pair<int,int>> v[1001];
int in[1001];
vector<int> parent, dp, res;
queue<int> q;

void Solve(){
	if(N==1) {
		cout<<0<<'\n'<<1<<'\n';
		return;
	}
	parent[1]=1;
	q.push(1);
	while(!q.empty()) {
		int curNode = q.front();
		q.pop();

		for(pair<int,int> p : v[curNode]) {
			int next = p.first;
			int point = p.second;
			if(dp[next] < dp[curNode] + point) {
				dp[next] = dp[curNode] + point;
				parent[next] = curNode;
			}
			if(next==1) {
				continue;
			}
			if(--in[next]==0) {
				q.push(next);
			}
		}
	}
	cout<<dp[1]<<'\n';
	res.push_back(1);
	int cur = parent[1];
	while(cur!=1){
		res.push_back(cur);
		cur = parent[cur];
	}
	res.push_back(1);
	reverse(res.begin(), res.end());
	for(int i : res) {
		cout<<i<<' ';
	}
}

void Init(){
	cin>>N>>M;
	parent.resize(N+1);
	dp.resize(N+1);
	for(int i=0; i<M; i++) {
		int X,Y,K; cin>>X>>Y>>K;
		v[X].push_back({Y,K});
		in[Y]++;
	}
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
