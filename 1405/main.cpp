#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int N;
double posb[4], res;
bool visited[50][50];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void DFS(int d, int x, int y, double tmp) {
    if(d==N) {
        res+=tmp;
        return;
    }
    for(int i=0; i<4; i++) {
        if(posb[i]==0) {
            continue;
        }
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!visited[ny][nx]) {
            visited[ny][nx] = true;
            DFS(d+1, nx, ny, tmp*posb[i]);
            visited[ny][nx] = false;
        }
    }
}

void Solve(){
    visited[25][25] = true;
    DFS(0, 25, 25, 1);
    cout<<setprecision(15)<<res<<'\n';
}

void Init(){
    cin>>N;
    for(int i=0; i<4; i++) {
        int a; cin>>a;
        posb[i] = (double)a/100;
    }
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
