#include <iostream>
#include <queue>
using namespace std;

int K,N;
deque<int> dq;
string res;

void Solve(){
    for(int i=0;i<N;i++){
        char ch; cin>>ch;
        int num = ch-'0';
        while(!dq.empty() && dq.back() < num && K) {
            dq.pop_back();
            K--;
        }
        dq.push_back(num);
    }
    while(K) {
        dq.pop_back();
        K--;
    }
    while(!dq.empty()) {
        res+=(dq.front()+'0');
        dq.pop_front();
    }
    cout<<res;
}

void Init(){
    cin>>N>>K;
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    Init();
    Solve();
    return 0;
}
