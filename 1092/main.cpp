#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
queue<int> pq[51];
vector<int> v;

void Solve() {
	int cnt{0};
	while (M) {
		cnt++;
		for (int i = 0; i < N; i++) {
			if (pq[i].empty()) {
				for (int j = i - 1; j >= 0; j--) {
					if (!pq[j].empty()) {
						pq[j].pop();
						M--;
						break;
					}
				}
				continue;
			}
			pq[i].pop();
			M--;
		}
	}
	cout << cnt << '\n';
}

void Init() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		int j;
		for (j = 0; j < N;) {
			if (v[j] >= a) {
				break;
			}
			j++;
		}
		if (j == N) {
			cout << -1 << '\n';
			exit(0);
		}
		pq[j].push(a);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
