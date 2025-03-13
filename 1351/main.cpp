#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long DP(long long n) {
    if(!n) {
        return 1;
    }
    if(m.find(n)!=m.end()) {
        return m[n];
    }
    long long val_P = DP(n / P);
    m.insert({n / P, val_P});
    long long val_Q = DP(n / Q);
    m.insert({n / Q, val_Q});
    return val_P + val_Q;
}

void Solve(){
    cout << DP(N);
}

void Init(){
    cin >> N >> P >> Q;
    m.insert({0, 1});
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
