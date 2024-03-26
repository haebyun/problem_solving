#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, M;
vector<int> Rank;
vector<pair<int,int>> v;
queue<pair<int,int>> q;

void Solve(){
	while(!q.empty()) {
		queue<pair<int,int>> cmp = q;
		int q_size = q.size();
		for(int i=0; i<q_size; i++) {
			int a = q.front().first; //4
			int b = q.front().second; //5
			q.pop();

			if(v[a].second==b) {
				swap(v[a], v[b]);
				swap(v[b].second, v[a].first);
				v[v[a].second].first = a;
				v[v[b].first].second = b;
				continue;
			}
			if(v[a].first==b) {
				swap(v[a], v[b]);
				swap(v[b].first, v[a].second);
				v[v[a].first].second = a;
				v[v[b].second].first = b;
				continue;
			}
			q.push({a,b});
		}
		if(cmp==q&&!q.empty()) {
			cout<<"IMPOSSIBLE"<<'\n';
			q = queue<pair<int,int>>();
			return;
		}
	}
	int start{0};
	for(int i=1; i<=N; i++) {
		if(v[i].first==0) {
			start=i;
			cout<<i<<' ';
			break;
		}
	}
	while(v[start].second!=0) {
		cout<<v[start].second<<' ';
		start = v[start].second;
	}
	cout<<'\n';
}

void Init(){
	cin>>N;
	v.assign(N+2,{0,0});
	Rank.assign(N+2, 0);
	for(int i=1; i<=N; i++) {
		cin>>Rank[i];
	}
	for(int i=1; i<=N; i++) {
		v[Rank[i]] = {Rank[i-1], Rank[i+1]};
	}
	for(cin>>M; M>0; M--) {
		int a, b; cin>>a>>b;
		q.push({a,b});
	}
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	cin>>T;
   	while(T--){
	    Init();
	    Solve();
	}
	return 0;
}
