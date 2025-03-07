#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string str;
stack<string> a, b;

void process_err() {
    cout << 0 << '\n';
    exit(0);
}

string cal_process(string cur) {
    if (b.empty()) {
        return cur;
    }
    int val = stoi(cur);
    int tmp{0};
    while (!b.empty()) {
        if (b.top() != "+") {
            tmp += stoi(b.top());
        }
        b.pop();
    }
    return to_string(val * tmp);
}

void func(char ch) {
    if (ch == '(' || ch == '[') {
        if (!a.empty()) {
            if (!(a.top() == "(" || a.top() == "[")) {
                a.push("+");
            }
        }
        ch == '(' ? a.push("(") : a.push("[");
    } else {
        if (a.empty()) {
            process_err();
        }
        bool flag{false};
        while (!a.empty()) {
            if (ch == ')' && a.top() == "[") {
                process_err();
            }
            if (ch == ']' && a.top() == "(") {
                process_err();
            }
            if ((a.top() == "(" && ch == ')') || (a.top() == "[" && ch == ']')) {
                a.pop();
                ch == ')' ? a.push(cal_process("2")) : a.push(cal_process("3"));
                flag = true;
                break;
            }
            b.push(a.top());
            a.pop();
        }
        if (!flag) {
            process_err();
        }
    }
}

void Solve() {
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        func(ch);
    }
    int tmp{0};
    while (!a.empty()) {
        if (a.top() == "(" || a.top() == "[") {
            process_err();
        }
        if (a.top() != "+") {
            tmp += stoi(a.top());
        }
        a.pop();
    }
    cout << tmp << '\n';
}

void Init() {
    cin >> str;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
