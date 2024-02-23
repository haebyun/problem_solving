#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, arr[21][21], res{1000000000};
bool visited[21];

void calc() {
	int cmpA{0};
	int cmpB{0};
	for(int i=1; i<=N; i++) {
		for(int j=i+1; j<=N; j++) {
			if(visited[i]&&visited[j]) {
				cmpA += (arr[i][j] + arr[j][i]);
			}
			else if (!visited[i]&&!visited[j]){
				cmpB += (arr[i][j] + arr[j][i]);
			}
		}
	}
	res=min(res, abs(cmpA-cmpB));
}

void BT(int d, int idx) {
	if(d==N/2) {
		calc();
	}
	for(int i=idx; i<=N; i++) {
		if(!visited[i]){
			visited[i]=true;
			BT(d+1, i+1);
			visited[i]=false;
		}
	}
}

void Solve(){
	visited[1]=true;
	BT(1, 2);
	cout<<res<<'\n';
}

void Init(){
	cin>>N;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin >> arr[i][j];
		}
	}
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
