#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, res;
vector<int> v;

void Solve(){
	for(int i=0; i<N-2; i++) {
        while(v[i] && v[i+1] && v[i+1]) {
            if(v[i+1] > v[i+2]) {
                int tmp = min(v[i], v[i+1] - v[i+2]);
                v[i] -= tmp;
                v[i+1] -= tmp;
                res += 5 * tmp;
            } else {
                int tmp = min(v[i], v[i + 1]);
                v[i]-=tmp;
                v[i+1]-=tmp;
                v[i+2]-=tmp;
                res += 7 * tmp;
            }
        }
        res += 3 * v[i];
        v[i] = 0;
    }
    int tmp = min(v[N - 2], v[N - 1]);
    v[N - 2] -= tmp;
    v[N - 1] -= tmp;
    res += 5 * tmp;
    v[N - 2] ? res += 3 * v[N - 2] : res += 3 * v[N - 1];
    cout<<res<<'\n';
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
