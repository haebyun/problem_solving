#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Infor {
 public:
  int x;
  int y;
  int cmp;
};

int N, M;
int Map[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[501][501];
deque<Infor> dq;

void Solve() {
  dq.push_back({0, 0, 0});
  visited[0][0] = true;
  while (!dq.empty()) {
	int x = dq.front().x;
	int y = dq.front().y;
	int cmp = dq.front().cmp;
	dq.pop_front();

	if (x == 500 && y == 500) {
	  cout << cmp << '\n';
	  return;
	}

	for (int i = 0; i < 4; i++) {
	  int nx = x + dx[i];
	  int ny = y + dy[i];
	  if(nx<0||ny<0||nx>500||ny>500) {
		continue;
	  }
	  if(visited[ny][nx]) {
		continue;
	  }
	  visited[ny][nx]=true;
	  if(!Map[ny][nx]) {
		dq.push_front({nx, ny, cmp});
	  }
	  else{
		dq.push_back({nx, ny, cmp + 1});
	  }
	}
  }
  cout<<-1<<'\n';
}

void Init() {
  cin >> N;
  for (int i = 0; i < N; i++) {
	int X1, Y1, X2, Y2;
	cin >> X1 >> Y1 >> X2 >> Y2;
	for (int j = min(Y1, Y2); j <= max(Y1, Y2); j++) {
	  for (int k = min(X1, X2); k <= max(X1, X2); k++) {
		Map[j][k] = 1;
	  }
	}
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
	int X1, Y1, X2, Y2;
	cin >> X1 >> Y1 >> X2 >> Y2;
	for (int j = min(Y1, Y2); j <= max(Y1, Y2); j++) {
	  for (int k = min(X1, X2); k <= max(X1, X2); k++) {
		visited[j][k] = true;
	  }
	}
  }
}

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  Init();
  Solve();
  return 0;
}
