#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,S,res{100001};
vector<int> v;

void Solve(){
	if(v[0]>=S) {
		cout<<1<<'\n';
		return;
	}
	int l, r, sum;
	l=0;
	r=1;
	sum = v[l] + v[r];
	while(true) {
		if(r>=N) {
			break;
		}
		if(sum<S) {
			r++;
			sum += v[r];
		}
		else{
			res = min(res, r-l+1);
			if(res==1) {
				break;
			}
			sum-=v[l];
			l++;
		}
	}
	if(res==100001) {
		cout<<0<<'\n';
	}
	else{
		cout<<res<<'\n';
	}
}

void Init(){
	cin>>N>>S;
	v.resize(N+1);
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
