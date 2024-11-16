#include <iostream>
#include <regex>
using namespace std;

string str;
regex pattern(R"((100+1+|01)+)");

void Solve(){
    regex_match(str, pattern) ? cout << "SUBMARINE" : cout << "NOISE";
}

void Init(){
    cin>>str;
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
