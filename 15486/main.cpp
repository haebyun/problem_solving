#include <iostream>
#include <algorithm>
using namespace std;

int N, T, P,memo[1500001], res{0};

void Solve(){
  for(int i=0; i<N; i++) {
	cin>>T>>P;
	res = max(res, memo[i]);
	if(i+T<=N) {
	  memo[i + T] = max(memo[i + T], P + res);
	}
  }
  cout<<max(res,memo[N])<<'\n';
}

void Init(){
  cin>>N;
}

int main(){
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  Init();
  Solve();
  return 0;
}
