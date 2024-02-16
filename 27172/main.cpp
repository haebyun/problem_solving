#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans[1000001];
bool cmp[1000001];
vector<int> v;

void factor(int a) {
	for (int i = a * 2; i <= 1000000; i += a) {
		if(cmp[i]) {
			ans[a]++;
			ans[i]--;
		}
	}
}

void Solve() {
	for (int i = 0; i < N; i++) {
		factor(v[i]);
	}
	for (int i = 0; i < N; i++) {
		cout << ans[v[i]] << ' ';
	}
}

void Init() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		cmp[v[i]] = true;
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	Init();
	Solve();
	return 0;
}
