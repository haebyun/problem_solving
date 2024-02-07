#include <iostream>
#include <vector>
using namespace std;

int T, V, E;
vector<vector<int>> v;
int label[20001] = {0, };
bool res;

void DFS(int cur){
	int tmp = label[cur];
	for (int next : v[cur]) {
		int next_label = label[next];
		if(next_label!=0 && next_label!=tmp) {
			continue;
		}
		if(next_label==tmp) {
			res=false;
			continue ;
		}
		if(next_label==0) {
			tmp == 1 ? label[next] = 2 : label[next] = 1;
			DFS(next);
		}
	}
}

void Solve(){
	res = true;
	for(int i=1; i<=V; i++) {
		if(label[i]==0) {
			label[i]=1;
			DFS(i);
		}
	}
	if(res){
		cout<<"YES"<<'\n';
	}
	else{
		cout<<"NO"<<'\n';
	}
	v = vector<vector<int>>();
	for(int i=0; i<=V; i++) {
		label[i] = 0;
	}
}

void Init(){
	cin>>V>>E;
	v.resize(V + 1);
	for(int i=0; i<E; i++) {
		int a, b; cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
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
