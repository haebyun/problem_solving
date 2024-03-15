#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll Min, Max;
vector<bool> isNoNo;

void Solve(){
    for(ll i=2; i*i<=Max; i++){
        ll n = Min/(i*i);
        if(Min%(i*i)!=0) {
            n++;
        }
        while(n*i*i<=Max) {
            isNoNo[n*i*i-Min]=true;
            n++;
        }
    }
    int res{0};
    for(int i=0; i<=Max-Min; i++) {
        if(!isNoNo[i]) {
            res++;
        }
    }
    cout<<res<<'\n';
}

void Init(){
    cin>>Min>>Max;
    isNoNo.resize(Max-Min+1);
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
