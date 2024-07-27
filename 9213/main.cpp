#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int v[1000001];

void Solve(){
    int cnt{1};
    while (true) {
        int start, stop, badness, res{0};
        cin >> start >> stop >> badness;

        if (start == 0 && stop == 0 && badness == 0) {
            break;
        }
        for(int i=start; i<=stop; i++) {
            if(v[i]<=badness) {
                res++;
            }
        }
        cout<<"Test "<<cnt<<": "<<res<<'\n';
        cnt++;
    }
}

void Init() {
    for(int i=1; i<=1000000; i++) {
        for(int j=i; j<=1000000; j+=i) {
            v[j] += i;
        }
        v[i]-=i;
    }
    for(int i=1; i<=1000000; i++) {
        v[i] = abs(i-v[i]);
    }
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
