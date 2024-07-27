#include <iostream>
using namespace std;

int N;
long long res;

void Solve(){
    for(int i=1; i<=N; i++) {
        res += i * (N / i);
    }
    cout<<res<<'\n';
}

void Init(){
	cin>>N;
}
//g(N) = sum(1~N) {f(i)};

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
