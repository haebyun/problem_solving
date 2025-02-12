#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, par[51], handleTime[51], d[51];
vector<int> v[51], sort_v;

bool cmp(int a, int b) {
	return a > b;
}

void Solve() {
	if (N == 1) {
		cout << 0 << '\n';
		return;
	}
	int tar{0};
	for (int i = 1; i < N; i++) {
		d[i] = d[par[i]] + 1;
		tar = max(tar, d[i]);
	}
	while (tar >= 0) {
		for (int i = N - 1; i >= 0; i--) {
			if (d[i] != tar) {
				continue;
			}
			if (v[i].empty()) {
				handleTime[i] = 0;
				continue;
			}
			int tmp_max{0};
			sort_v = vector<int>();
			for (int j: v[i]) {
				sort_v.push_back(handleTime[j]);
			}
			sort(sort_v.begin(), sort_v.end(), cmp);
			for (int j = 0; j < sort_v.size(); j++) {
				tmp_max = max(tmp_max, sort_v[j] + j + 1);
			}
			handleTime[i] = tmp_max;
		}
		tar--;
	}
	cout << handleTime[0];
}

void Init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> par[i];
		v[par[i]].push_back(i);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
