#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int want, N, M, res;
unordered_map<int, int> m_a;
vector<int> v_a, v_b;

void InitPrefix(int n, vector<int>& arr, vector<int>& v) {
	for(int i=0; i<n; i++) {
		int cur{0}, idx{i};
		for(int j=1; j<n; j++) {
			cur += arr[idx];
			v.push_back(cur);
			idx = (idx + 1) % n;
		}
	}
}

void Solve() {
	for(int n : v_a) {
		m_a[n]++;
	}
	for(int n : v_b) {
		if(n == want) {
			res++;
			continue;
		}
		res += m_a[want - n];
	}
	res += m_a[want];
	cout<<res<<'\n';
}

void Init() {
	cin >> want >> N >> M;
	vector<int> arr(N, 0);
	int tmp{0};
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		tmp += arr[i];
	}
	v_a.push_back(tmp);
	InitPrefix(N, arr, v_a);

	tmp = 0;
	arr = vector<int>(M, 0);
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
		tmp += arr[i];
	}
	v_b.push_back(tmp);
	InitPrefix(M, arr, v_b);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
