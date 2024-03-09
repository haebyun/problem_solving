#include <iostream>
#include <vector>

using namespace std;

string T, P;
vector<int> arr, res;
int cnt{0};

void solve() {
	int i{0}, j{0};
	while (i <= T.size() && j <= P.size()) {
		if (j == P.size()) {
			cnt++;
			res.push_back(i - P.size() + 1);
			j = arr[j - 1] + 1;
			if (i == T.size()) {
				break;
			}
			continue;
		}
		if (T[i] == P[j]) {
			i++;
			j++;
		} else if (j == 0) {
			i++;
		} else {
			j = arr[j - 1] + 1;
		}
	}
	cout << cnt << '\n';
	for (int n : res) {
		cout << n << ' ';
	}
}

void init() {
	getline(cin, T);
	getline(cin, P);
	arr.resize(P.size());
	arr[0] = -1;
	for (int i = 1; i < P.size(); i++) {
		int j = arr[i - 1];
		while (P[i] != P[j + 1] && j >= 0) {
			j = arr[j];
		}
		if (P[i] == P[j + 1]) {
			arr[i] = j + 1;
		} else {
			arr[i] = -1;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	init();
	solve();
	return 0;
}
