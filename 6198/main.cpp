#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

long long N;
stack<int> s;
long long res{0};

void Solve() {
    cin>>N;
    for(int i=0; i<N; i++) {
        int h; cin>>h;
        if (s.empty()) {
            s.push(h);
        } else {
            if(s.top() > h) {
                s.push(h);
            }
            else{
                while(s.top()<=h) {
                    s.pop();
                    if(s.empty()) break;
                    res+=s.size();
                }
                s.push(h);
            }
        }
    }
    while(!s.empty()) {
        s.pop();
        res+=s.size();
    }
    cout<<res<<'\n';
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Solve();
    return 0;
}
