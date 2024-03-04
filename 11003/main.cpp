#include <iostream>
#include <queue>
using namespace std;

int N, L;
deque<pair<int,int>> dq;

void solve() {
	for (int i = 1; i <= N; i++) {
		if(!dq.empty()) {
			if(dq.front().second<i-L+1) {
				dq.pop_front();
			}
		}
		int num;
		cin >> num;
		while(!dq.empty()&&dq.back().first>num) {
			dq.pop_back();
		}
		dq.push_back({num, i});
		cout<<dq.front().first<<' ';
	}
}

void init() {
	cin >> N >> L;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	init();
	solve();
	return 0;
}
