#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
vector<pair<int,int>> v[101];
vector<int> ans;
int cnt[101], val[101];
queue<int> q;

void Solve(){
	q.push(N);
	cnt[N]=1;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		if(v[cur].empty()) {
			ans.push_back(cur);
		}
		for(pair<int,int> p : v[cur]) {
			cnt[p.first] += cnt[cur]*p.second;
			if(!--val[p.first]) {
				q.push(p.first);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(int i : ans) {
		cout << i << ' ' << cnt[i]<<'\n';
	}
}

void Init(){
	cin>>N>>M;
	for(int i=0; i<M;i++) {
		int X,Y,K; cin>>X>>Y>>K;
		v[X].push_back({Y, K});
		val[Y]++;
	}
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
