#include <iostream>
using namespace std;

int T, N;
int memo[10001];

void Solve() {
	memo[0]=1;
	for(int i=1; i<=3; i++) {
		for(int j=i; j<=10000; j++) {
			memo[j] += memo[j-i];
		}
	}
}

void Init() {
	cin >> N;
	cout << memo[N] << '\n';
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Solve();
	cin >> T;
	while(T--) {
		Init();
	}
	return 0;
}
