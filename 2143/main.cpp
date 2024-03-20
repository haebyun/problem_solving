#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T,N,M;
long long res{0};
vector<int> A, B, Sum;

void Solve(){
	for(int i=0; i<M; i++) {
        int tmp{0};
        for(int j=i; j<M; j++) {
            tmp+=B[j];
            Sum.push_back(tmp);
        }
    }
    sort(Sum.begin(), Sum.end());
    for(int i=0; i<N; i++) {
        int tmp{0};
        for(int j=i; j<N; j++) {
            tmp+=A[j];
            int cmp = T - tmp;
            res += upper_bound(Sum.begin(), Sum.end(), cmp)
                    - lower_bound(Sum.begin(), Sum.end(), cmp);
        }
    }
    cout<<res<<'\n';
}

void Init(){
	cin>>T;
    cin>>N;
    A.resize(N);
    for(int i=0; i<N; i++) {
        cin>>A[i];
    }
    cin>>M;
    B.resize(M);
    for(int i=0; i<M; i++) {
        cin >> B[i];
    }
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
