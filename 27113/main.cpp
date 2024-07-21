#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cur{1};

void terminateOnImpossibility() {
    cout << "NO" << '\n';
    exit(0);
}

void moveCur(int k) {
    if (k == 0) {
        return;
    } else if (k == 1) {
        int start;
        char dir;
        cin >> start >> dir;
        if (dir == 'R') {
            if (cur > start - 1) {
                terminateOnImpossibility();
            }
        } else {
            if (start == M) {
                terminateOnImpossibility();
            }
            cur = max(cur, start + 1);
        }
    } else {
        int start1, start2;
        char dir1, dir2;
        cin >> start1 >> dir1 >> start2 >> dir2;
        if (dir1 == dir2) {
            int start;
            if (dir1 == 'R') {
                start = min(start1, start2);
                if (cur > start - 1) {
                    terminateOnImpossibility();
                }
            } else {
                start = max(start1, start2);
                if (start == M) {
                    terminateOnImpossibility();
                }
                cur = max(cur, start + 1);
            }
        } else {
            if (dir1 == 'L' && dir2 == 'R') {
                swap(start1, start2);
            }
            if (start1 <= start2) { //센서 사이만 통과 불가
                if (cur >= start1) {
                    if (start2 == M) {
                        terminateOnImpossibility();
                    }
                    cur = max(cur, start2 + 1);
                }
            } else if (start1 > start2) { //센서 사이만 통과 가능
                if (cur >= start1 || start1 - start2 == 1) {
                    terminateOnImpossibility();
                }
                cur = max(cur, start2 + 1);
            }
        }
    }
}

void Solve() {
    for (int i = 1; i < N; i++) {
        int k;
        cin >> k;
        moveCur(k);
    }
    cout << "YES" << '\n';
}

void Init() {
    cin >> N >> M;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
