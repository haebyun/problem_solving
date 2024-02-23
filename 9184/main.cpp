#include <iostream>
using namespace std;

int A, B, C, dp[21][21][21];

int DP(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return DP(20, 20, 20);
	}
	if (dp[a][b][c]) {
		return dp[a][b][c];
	}
	if (a < b && b < c) {
		return dp[a][b][c] = DP(a, b, c - 1) + DP(a, b - 1, c - 1) - DP(a, b - 1, c);
	}
	return dp[a][b][c] = DP(a - 1, b, c) + DP(a - 1, b - 1, c) + DP(a - 1, b, c - 1) - DP(a - 1, b - 1, c - 1);
}

void Solve() {
	cout << "w(" << A << ", " << B << ", " << C << ") = " << DP(A, B, C) << '\n';
}

void Init() {
	while (true) {
		cin >> A >> B >> C;
		if (A == -1 && B == -1 && C == -1) {
			return;
		}
		Solve();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Init();
	return 0;
}
