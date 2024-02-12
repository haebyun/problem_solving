#include <iostream>
#include <algorithm>
using namespace std;

int C, N;
int dp[100001];
pair<int, int> city[1001];

void Solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 100000; j++) {
			if (j - city[i].first >= 0) {
				dp[j] = max(dp[j], dp[j - city[i].first] + city[i].second);
			}
		}
	}
	for (int i = 1; i <= 100000; i++) {
		if (dp[i] >= C) {
			cout << i << '\n';
			exit(0);
		}
	}
}

void Init() {
	cin >> C >> N;
	for (int i = 1; i <= N; i++) {
		int exp, cos;
		cin >> exp >> cos;
		city[i] = {exp, cos};
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
