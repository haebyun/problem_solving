#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

int N, M, dis_min[201][201], dis_max[201][201];

void FloydWarshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dis_min[i][j] = min(dis_min[i][j], dis_min[i][k] + dis_min[k][j]);
				dis_min[j][i] = min(dis_min[j][i], dis_min[j][k] + dis_min[k][i]);
			}
		}
	}
}

double getResult() {
	double res = INF;
	for (int k = 1; k <= N; k++) {
		double cmp = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dis_max[i][j] != INF) {
					cmp = max(cmp, ((double)(dis_min[k][i] + dis_min[k][j] + dis_max[i][j]) / 2));
				}
			}
		}
		res = min(res, cmp);
	}
	return res;
}

void Solve() {
	FloydWarshall();
	cout << fixed;
	cout.precision(1);
	cout << getResult() << '\n';
}

void Init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				dis_min[i][j] = INF;
			}
			dis_max[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (dis_min[a][b] == INF) {
			dis_min[a][b] = c;
			dis_min[b][a] = c;
		} else {
			dis_min[a][b] = min(dis_min[a][b], c);
			dis_min[b][a] = min(dis_min[b][a], c);
		}
		if (dis_max[a][b] == INF) {
			dis_max[a][b] = c;
			dis_max[b][a] = c;
		} else {
			dis_max[a][b] = max(dis_max[a][b], c);
			dis_max[b][a] = max(dis_max[b][a], c);
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
