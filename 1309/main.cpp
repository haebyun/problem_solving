#include <iostream>
using namespace std;
#define MOD 9901

int N;
int dp[100001];

void Solve(){
  for(int i=5; i<=N; i++) {
	dp[i] = dp[i-1]*2+dp[i-2];
	dp[i] %= MOD;
  }
  cout<<dp[N]<<'\n';
}

void Init(){
  cin>>N;
  dp[1] = 3;
  dp[2] = 7;
  dp[3] = 17;
  dp[4] = 41;
}

int main(){
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  Init();
  Solve();
  return 0;
}
