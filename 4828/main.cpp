#include <iostream>
#include <regex>
#include <string>
#include <stack>
using namespace std;

string input;
bool flag;
regex invalidTagPattern("<[^/a-z0-9]");
regex entityPattern("&(lt|gt|amp);");
regex hexEntityPattern("&x([a-fA-F0-9]{2})+;");
regex selfClosingTagPattern("<[a-z0-9]+/>");
regex openCloseTagPattern("</?[a-z0-9]+>");

bool Solve(){
    stack<string> s;
    flag = false;

    if (regex_search(input, invalidTagPattern)) {
        flag = true;
    }
    input = regex_replace(input, entityPattern, "");
    input = regex_replace(input, hexEntityPattern, "");

    input = regex_replace(input, selfClosingTagPattern, "");

    sregex_iterator it(input.begin(), input.end(), openCloseTagPattern);
    sregex_iterator end;

    while (it != end) {
        string tag = it->str();
        if (tag[1] == '/') { // 닫는 태그
            string tagName = tag.substr(2, tag.size() - 3);
            if (s.empty() || s.top() != tagName) {
                flag = true;
                break;
            }
            s.pop();
        } else { // 여는 태그
            string tagName = tag.substr(1, tag.size() - 2);
            s.push(tagName);
        }
        ++it;
    }
    input = regex_replace(input, openCloseTagPattern, "");
    if (regex_search(input, regex("[<&>]"))) {
        flag = true;
    }

    if (flag || !s.empty()) {
        return false;
    } else {
        return true;
    }
}

void Init(){
    while (getline(cin, input)) {
        cout << (Solve() ? "valid" : "invalid") << "\n";
    }
}

int main(){
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	Init();
	return 0;
}
