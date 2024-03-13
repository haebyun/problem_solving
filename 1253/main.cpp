#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, res{0};
vector<int> v;

void Solve() {
    if(v.size()<=2) {
        cout<<0<<'\n';
        return;
    }
    for(int i=0; i<v.size(); i++) {
        int cmp = v[i];
        int l=0;
        int r=N-1;
        while (l<r){
            int tmp = v[l]+v[r];
            if(tmp>cmp) {
                r--;
            }
            else if(tmp<cmp) {
                l++;
            }
            else{
                if(i==l) {
                    l++;
                    continue;
                }
                if(i==r) {
                    r--;
                    continue;
                }
                res++;
                break;
            }
        }
    }
    cout<<res<<'\n';
}

void Init() {
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
