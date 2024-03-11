#include <iostream>
using namespace std;
#define MOD 1000000000

int N,K;
long long dp[201][201];

void Solve(){
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            for(int k=j; k>=1; k--) {
                dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
            }
        }
    }
    cout<<dp[N][K]<<'\n';
}

void Init(){
	cin>>N>>K;
    for(int i=1; i<=K; i++) {
        dp[0][i]=1;
    }
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
