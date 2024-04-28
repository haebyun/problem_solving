#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Order {
public:
	int from;
	int to;
	int val;
};

bool cmp(Order a, Order b) {
	if (a.to == b.to) {
		return a.from > b.from;
	}
	return a.to < b.to;
}

int N, M, C;
vector<Order> v;
vector<long long> wei;
long long ans;

void Solve() {
	sort(v.begin(), v.end(), cmp);
	for (auto a: v) {
		long long Max{0};
		for (int i = a.to - 1; i >= a.from; i--) {
			if (a.val + wei[i] > C) {
				Max = max(Max, wei[i]);
			}
		}
		if (Max + a.val <= C) {
			ans += a.val;
			for (int i = a.from; i < a.to; i++) {
				wei[i] += a.val;
			}
		} else {
			ans += (C - Max);
			for (int i = a.from; i < a.to; i++) {
				wei[i] += (C - Max);
			}
		}
	}
	cout << ans << '\n';
}

void Init() {
	cin >> N >> C >> M;
	wei.resize(N + 1);
	v.resize(M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[i] = {a, b, c};
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
