#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, H, W, Sy, Sx, Fy, Fx;
bool Map[1001][1001], visited[1001][1001], cantgo[1001][1001];
queue<pair<int,int>> q;
vector<pair<int,int>> wall;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool can_go(int x, int y) {
    if(x<1 || y<1) {
        return false;
    }
    if(x + W - 1> M || y + H -1 > N) {
        return false;
    }
    if(cantgo[y][x]) {
        return false;
    }
    return true;
}

int BFS() {
    visited[Sy][Sx] = true;
    q.push({Sx, Sy});
    int cnt{-1};
    while(!q.empty()) {
        int q_size = q.size();
        cnt++;
        for(int k=0; k<q_size; k++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == Fx && y == Fy) {
                return cnt;
            }
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(!can_go(nx,ny)) {
                    continue;
                }
                if(visited[ny][nx]) {
                    continue;
                }
                q.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }
    return -1;
}

void Solve(){
    cout<<BFS();
}

void Init(){
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin>>Map[i][j];
            if(Map[i][j]) {
                wall.push_back({j, i});
            }
        }
    }
    cin>>H>>W>>Sy>>Sx>>Fy>>Fx;
    for(pair<int,int> p : wall) {
        int x = p.first;
        int y = p.second;

        for(int i=y; i>=max(1, y-H+1); i--) {
            for(int j=x; j>=max(1, x-W+1); j--) {
                cantgo[i][j] = true;
            }
        }
    }
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
