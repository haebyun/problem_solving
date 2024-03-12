#include <iostream>
#include <algorithm>
using namespace std;

string A,B;
int Min{100};

void comp(int i) {
    int tmp{0};
    for(int j=i; j<i+A.size(); j++) {
        if(A[j-i]!=B[j]) {
            tmp++;
        }
    }
    Min = min(Min, tmp);
}

void Solve(){
    int cmp = B.size()-A.size();
    for(int i=0; i<=cmp; i++) {
        comp(i);
        if(Min==0){
            break;
        }
    }
    cout<<Min<<'\n';
}

void Init(){
    cin>>A>>B;
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
