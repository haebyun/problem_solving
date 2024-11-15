#include <iostream>
#include <vector>
#include <regex>
using namespace std;

int N;
regex pattern(R"((01|100+1+)+)");

void Solve() {
    for(int i=0; i<N; i++) {
        string str; cin>>str;
        regex_match(str, pattern) ? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';
    }
}

void Init() {
    cin >> N;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
