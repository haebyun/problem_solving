#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, res;
int arr[10001], parent[10001];
bool visited[10001];

int Find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if(arr[a]<arr[b]) {
		parent[b] = parent[a];
	}
	else{
		parent[a] = parent[b];
	}
}

void Solve() {
	for(int i=1; i<=N; i++) {
		int tmp = Find(i);
		if(!visited[tmp]) {
			visited[tmp] = true;
			res+=arr[tmp];
		}
	}
	if(res>K) {
		cout<<"Oh no"<<'\n';
	}
	else{
		cout<<res<<'\n';
	}
}

void Init() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if(a == b){
			continue;
		}
		Union(a, b);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
