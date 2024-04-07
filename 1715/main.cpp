#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> pq;
long long res;

void Solve(){
	while(pq.size()>1) {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        int k = a + b;
        res+=(long long)(k);
        pq.push(-k);
    }
    cout<<res<<'\n';
}

void Init(){
	cin>>N;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        pq.push(-num);
    }
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	Solve();
	return 0;
}
