#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, N;
char Map[210][210];
vector<pair<int,int>> loc;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void printAns() {
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            cout<<Map[i][j];
        }
        cout<<'\n';
    }
}

void explode() {
    for(pair<int,int> p : loc) {
        int x = p.first;
        int y = p.second;
        Map[y][x] = '.';

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            Map[ny][nx] = '.';
        }
    }
    loc = vector<pair<int, int>>();
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(Map[i][j] =='O') {
                loc.push_back({j,i});
            }
        }
    }
}

void Solve(){
    if(N==1) {
        printAns();
        return;
    }
    if(N%2==0) {
        for(int i=1; i<=R; i++) {
            for(int j=1; j<=C; j++) {
                cout<<'O';
            }
            cout<<'\n';
        }
        return;
    }
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            Map[i][j] = 'O';
        }
    }
    explode();
    if(N%4 == 3) {
        printAns();
        return;
    }
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            Map[i][j] = 'O';
        }
    }
    explode();
    printAns();
}

void Init(){
	cin>>R>>C>>N;
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            cin>>Map[i][j];
            if(Map[i][j] == 'O') {
                loc.push_back({j,i});
            }
        }
    }
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
	Init();
	Solve();
	return 0;
}
