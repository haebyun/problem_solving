#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, N, M;
vector<int> coin;
int memo[10001];

void Solve() {
	memo[0]=1;
	for(int i=0; i<N; i++) {
		for(int j=coin[i]; j<=M; j++) {
			memo[j] += memo[j - coin[i]];
		}
	}
	cout<<memo[M]<<'\n';
	coin = vector<int>();
	memset(memo, 0, sizeof(memo));
}

void Init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		coin.push_back(a);
	}
	cin >> M;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		Init();
		Solve();
	}
	return 0;
}
