#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M, start, tar;
vector<vector<pair<int, int>>> v, in;
vector<int> cnt, cmp;
queue<int> q;
set<pair<int, int>> s;

void Solve() {
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int cost = v[cur][i].second;
			if (cmp[cur] + cost > cmp[next]) {
				cmp[next] = cmp[cur] + cost;
			}
			cnt[next]--;
			if (!cnt[next]) {
				q.push(next);
			}
		}
	}
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < in[cur].size(); i++) {
			int next = in[cur][i].first;
			int cost = in[cur][i].second;
			if (cmp[next] == cmp[cur] - cost && s.find({cur, next}) == s.end()) {
				q.push(next);
				s.insert({cur, next});
			}
		}
	}
	cout << cmp[tar] << '\n' << s.size();
}

void Init() {
	cin >> N >> M;
	cnt.resize(N + 1);
	cmp.resize(N + 1);
	v.resize(N + 1);
	in.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		in[b].push_back({a, c});
		cnt[b]++;
	}
	cin >> start >> tar;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
