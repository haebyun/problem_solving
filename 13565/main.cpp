#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
char per[1001][1001];
queue<pair<int,int>> q;
bool visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int start_x) {
    q.push({start_x, 1});
    visited[1][start_x]=true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<1||ny<1||nx>M) {
                continue;
            }
            if(ny>N) {
                cout<<"YES"<<'\n';
                exit(0);
            }
            if(per[ny][nx] == '1') {
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

void Solve(){
    for(int i=1; i<=M; i++) {
        if(per[1][i] == '0') {
            BFS(i);
        }
    }
    cout<<"NO"<<'\n';
}

void Init(){
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> per[i][j];
        }
    }
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
