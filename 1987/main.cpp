#include <iostream>
#include <algorithm>
using namespace std;

int N, M, res;
char ch[21][21];
bool ascii[100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func(int d, int x, int y) {
    res = max(res, d);
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        char c = ch[ny][nx];

        if(nx<0||nx>=M||ny<0||ny>=N) {
            continue;
        }
        if(ascii[c]){
            continue;
        }
        ascii[c]=true;
        func(d + 1, nx, ny);
        ascii[c]=false;
    }
}

void Solve(){
    ascii[ch[0][0]]=true;
    func(1, 0, 0);
    cout<<res<<'\n';
}

void Init(){
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> ch[i][j];
        }
    }
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
