#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, S;
long long res{0};
vector<int> v, a, b, sum;
int Size;

void setSum(int d,int tmp) {
    if(d>=Size) {
        sum.push_back(tmp);
        return;
    }
    setSum(d + 1, tmp);
    setSum(d + 1, tmp + b[d]);
}

void Func(int d, int cmp) {
    if(d>=N/2) {
        int cnt = upper_bound(sum.begin(), sum.end(), S-cmp)-lower_bound(sum.begin(), sum.end(), S-cmp);
        res += cnt;
        return;
    }
    Func(d + 1, cmp);
    Func(d + 1, cmp + a[d]);
}

void Solve(){
    for(int i=0; i<N/2; i++) {
        a.push_back(v[i]);
    }
    for(int i=N/2; i<N; i++) {
        b.push_back(v[i]);
    }
    Size = b.size();
    setSum(0, 0);
    sort(sum.begin(), sum.end());
    Func(0, 0);
    if(S==0) {
        res--;
    }
    cout<<res<<'\n';
}

void Init(){
	cin>>N>>S;
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
