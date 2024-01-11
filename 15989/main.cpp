#include <iostream>
using namespace std;

int T, N;
int memo[10001][4];

void Solve() {
	memo[1][1] = 1;
	memo[2][1] = 1;
	memo[2][2] = 1;
	memo[3][1] = 1;
	memo[3][2] = 1;
	memo[3][3] = 1;
	for (int i = 4; i <= 10000; i++) {
		memo[i][1] = memo[i - 1][1];
		memo[i][2] = memo[i - 2][1] + memo[i - 2][2];
		memo[i][3] = memo[i - 3][1] + memo[i - 3][2] + memo[i - 3][3];
	}
}

void Init() {
	cin >> N;
	cout << memo[N][1] + memo[N][2] + memo[N][3] << '\n';
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Solve();
	cin >> T;
	while (T--) {
		Init();
	}
	return 0;
}
