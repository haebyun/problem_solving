#include <iostream>
#include <regex>
#include <string>
using namespace std;

string document, target;

void Solve(){
    regex pattern(target);
    int cnt{0};
    string::const_iterator search_start = document.cbegin();

    while (search_start != document.cend()) {
        smatch match;
        if (regex_search(search_start, document.cend(), match, pattern)) {
            cnt++;
            search_start = match[0].second;
        } else {
            break;
        }
    }
    cout<<cnt<<'\n';
}

void Init(){
}

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
