#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, max_d, res_d, res_v;
vector<pair<int, int>> node, v;
vector<bool> par;

int DFS(int cur, int d, int cmp) {
	max_d = max(max_d, d);
	int x = cmp;
	if (node[cur].first != -1) {
		x = DFS(node[cur].first, d + 1, cmp);
	}
	v[d].first = min(v[d].first, x + 1);
	v[d].second = max(v[d].second, x + 1);
	if (node[cur].second != -1) {
		x = DFS(node[cur].second, d + 1, x + 1) - 1;
	}
	return x + 1;
}

void Solve() {
	int root{1};
	for (int i = 1; i <= N; i++) {
		if (!par[i]) {
			root = i;
			break;
		}
	}
	DFS(root, 1, 0);
	for (int i = 1; i <= max_d; i++) {
		if (res_v < v[i].second - v[i].first + 1) {
			res_d = i;
			res_v = v[i].second - v[i].first + 1;
		}
	}
	cout << res_d << " " << res_v;
}

void Init() {
	cin >> N;
	node.resize(N + 1, {-1, -1});
	v.resize(N + 1, {2000000, 0});
	par.resize(N + 1);
	for (int i = 0; i < N; i++) {
		int root, right, left;
		cin >> root >> left >> right;
		node[root].first = left;
		node[root].second = right;
		if (right != -1) par[right] = true;
		if (left != -1) par[left] = true;
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
