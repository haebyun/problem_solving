#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, res;
vector<int> v;

void Solve(){
    sort(v.begin(), v.end());
    for(int i=0; i<N-K; i++) {
        res += v[i];
    }
    cout<<res;
}

void Init(){
    cin>>N>>K;
    v.resize(N-1);
    int n; cin>>n;
    for(int i=0; i<N-1; i++) {
        int k; cin>>k;
        v[i]=k-n;
        n=k;
    }
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
