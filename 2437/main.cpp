#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

void Solve(){
    sort(v.begin(), v.end());
    int sum{0};
    for(int i=0; i<N; i++) {
        if(sum+1<v[i]) {
            cout<<sum+1<<'\n';
            return;
        }
        sum += v[i];
    }
    cout<<sum+1<<'\n';
}

void Init(){
    cin>>N;
    v.resize(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
