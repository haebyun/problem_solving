#include <iostream>
#include <vector>
using namespace std;

string W[4];
int K, n, dir, res;
vector<pair<int, int> > order;
bool visited[4];

void rotation(int idx, int dir) {
	visited[idx] = true;
	char rSide = W[idx][2];
	char lSide = W[idx][6];
	int rIdx = idx + 1;
	int lIdx = idx - 1;

	if (dir == 1) {
		for (int i = 7; i >= 1; i--) {
			swap(W[idx][i], W[idx][i - 1]);
		}
	} else {
		for (int i = 0; i < 7; i++) {
			swap(W[idx][i], W[idx][i + 1]);
		}
	}

	if (rIdx < 4 && !visited[rIdx] && rSide != W[rIdx][6]) {
		rotation(rIdx, (-1) * dir);
	}
	if (lIdx >= 0 && !visited[lIdx] && lSide != W[lIdx][2]) {
		rotation(lIdx, (-1) * dir);
	}
}

void Solve() {
	for (pair<int, int> p : order) {
		rotation(p.first, p.second);
		for (int i = 0; i < 4; i++) {
			visited[i] = false;
		}
	}
	W[0][0] == '1' ? res += 1 : res += 0;
	W[1][0] == '1' ? res += 2 : res += 0;
	W[2][0] == '1' ? res += 4 : res += 0;
	W[3][0] == '1' ? res += 8 : res += 0;
	cout << res << '\n';
}

void Init() {
	for (string &i : W) {
		cin >> i;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> n >> dir;
		order.push_back({n - 1, dir});
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
