#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, L, res;
vector<int> v;

void Solve(){
    int left{1}, right{L};
    while(left<=right) {
        int mid = (left + right)/2;
        int cnt{0};

        for(int i=1; i<v.size(); i++) {
            int gap = v[i] - v[i-1];
            cnt+=(gap-1)/mid;
        }

        if(cnt <= M) {
            res = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout<<res<<'\n';
}

void Init(){
    cin>>N>>M>>L;
    v.resize(N);
    for(int i=0; i<N; i++) {
        cin>>v[i];
    }
    v.push_back(0);
    v.push_back(L);
    sort(v.begin(), v.end());
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
