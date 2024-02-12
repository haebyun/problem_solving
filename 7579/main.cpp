#include <iostream>
#include <algorithm>
using namespace std;

int N, M, sum, memory[101], cost, dp[10001];

void Solve() {
	for (int i = 1; i <= N; i++) {
		cin >> cost;
		for (int j = 10000; j >= cost; j--) {
			dp[j] = max(dp[j], dp[j - cost] + memory[i]);
		}
		sum += cost;
	}
	for (int i = 0; i <= sum; i++) {
		if (dp[i] >= M) {
			cout << i << '\n';
			return;
		}
	}
}

void Init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> memory[i];
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
