#include <iostream>
#include <vector>
using namespace std;

int N, M, r, c, d, Map[51][51];
int dx[4] = {0,  1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool visited[51][51];

void DFS(int x, int y, int dir, int res) {
	visited[y][x]=true;
	for(int i=0; i<4; i++) {
		int nDir = (dir+3-i)%4;
		int nx = x+dx[nDir];
		int ny = y+dy[nDir];
		if(visited[ny][nx]){
			continue;
		}
		if(Map[ny][nx]==0){
			DFS(nx,ny,nDir, res+1);
		}
	}
	int nx = x+dx[(dir+2)%4];
	int ny = y+dy[(dir+2)%4];
	if(Map[ny][nx]==1) {
		cout<<res<<'\n';
		exit(0);
	}
	else{
		DFS(nx,ny,dir,res);
	}
}

void Solve() {
	DFS(c, r, d, 1);
}

void Init() {
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
