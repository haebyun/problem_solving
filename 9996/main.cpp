#include <iostream>
#include <regex>
#include <vector>
#include <string>

using namespace std;

int N;
string str;
vector<string> v;
char delimiter{'*'};

void Solve() {
    string pat = "^";
    for (char i: str) {
        if (i == delimiter) {
            pat += "[a-z]";
        }
        pat += i;
    }
    pat += '$';
    regex pattern(pat);
    for (const string &s: v) {
        regex_match(s, pattern) ? cout << "DA" << '\n' : cout << "NE" << '\n';
    }
}

void Init() {
    cin >> N >> str;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
