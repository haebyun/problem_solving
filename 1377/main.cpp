#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int,int>> v;

void Solve(){
    stable_sort(v.begin(), v.end());
    int Max{-1};
    for(int i=0; i<N; i++) {
        Max = max(Max, v[i].second - i);
    }
    cout<<Max+1<<'\n';
}

void Init(){
    cin>>N;
    v.resize(N);
    for(int i=0; i<N;i++) {
        int n;
        cin>>n;
        v[i] = {n, i};
    }
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
