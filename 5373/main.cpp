#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

int T, N;
int adjacent[6][4] = {{1, 2, 3, 4},
                      {0, 4, 5,2},
                      {0, 1, 5, 3},
                      {0, 2, 5, 4},
                      {0, 3, 5, 1},
                      {1, 4, 3, 2}};
char dice[6][3][3], temp[3][3];
char color[6] = {'w','r','g','o','b','y'};
map<char, int> m = {{'U', 0},
                    {'F', 1},
                    {'L', 2},
                    {'B', 3},
                    {'R', 4},
                    {'D', 5}};
vector<pair<char, char>> v;

void spin(char dir, int curDice) {
    if(dir=='+') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp[i][j] = dice[curDice][2 - j][i];
            }
        }
        memmove(dice[curDice], temp, sizeof(dice[curDice]));
    } else {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                temp[i][j] = dice[curDice][j][2-i];
            }
        }
        memmove(dice[curDice], temp, sizeof(dice[curDice]));
    }
}

void rotate(char dir, int curDice) {
    spin(dir, curDice);
    if (curDice == 0 || curDice==5) {
        int ud = (curDice == 0) ? 0 : 2;
        if (dir == '+') {
            for (int i = 3; i > 0; i--) {
                for (int j = 0; j < 3; j++) {
                    swap(dice[adjacent[curDice][i]][ud][j], dice[adjacent[curDice][i - 1]][ud][j]);
                }
            }
        } else if (dir == '-') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    swap(dice[adjacent[curDice][i]][ud][j], dice[adjacent[curDice][i + 1]][ud][j]);
                }
            }
        }
    } else if (curDice == 1) {
        if (dir == '+') {
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][0]][2][i], dice[adjacent[curDice][3]][2-i][2]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][3]][i][2], dice[adjacent[curDice][2]][0][i]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][2]][0][i], dice[adjacent[curDice][1]][2-i][0]);
            }
        } else if (dir == '-') {
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][0]][2][i], dice[adjacent[curDice][1]][i][0]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][1]][i][0], dice[adjacent[curDice][2]][0][2-i]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][2]][0][i], dice[adjacent[curDice][3]][i][2]);
            }
        }
    } else if (curDice == 2) {
        if (dir == '+') {
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][0]][i][0], dice[adjacent[curDice][3]][2-i][2]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][3]][2-i][2], dice[adjacent[curDice][2]][i][0]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][2]][i][0], dice[adjacent[curDice][1]][i][0]);
            }
        } else if (dir == '-') {
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][0]][i][0], dice[adjacent[curDice][1]][i][0]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][1]][i][0], dice[adjacent[curDice][2]][i][0]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][2]][i][0], dice[adjacent[curDice][3]][2-i][2]);
            }
        }
    } else if (curDice == 3) {
        if (dir == '+') {
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][0]][0][i], dice[adjacent[curDice][3]][i][2]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][3]][i][2], dice[adjacent[curDice][2]][2][2-i]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][2]][2][i], dice[adjacent[curDice][1]][i][0]);
            }
        } else if (dir == '-') {
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][0]][0][2-i], dice[adjacent[curDice][1]][i][0]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][1]][i][0], dice[adjacent[curDice][2]][2][i]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][2]][2][i], dice[adjacent[curDice][3]][2-i][2]);
            }
        }
    } else if (curDice == 4) {
        if (dir == '+') {
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][0]][i][2], dice[adjacent[curDice][3]][i][2]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][3]][i][2], dice[adjacent[curDice][2]][i][2]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][2]][i][2], dice[adjacent[curDice][1]][2-i][0]);
            }
        } else if (dir == '-') {
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][0]][i][2], dice[adjacent[curDice][1]][2-i][0]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][1]][2-i][0], dice[adjacent[curDice][2]][i][2]);
            }
            for(int i=0; i<3; i++) {
                swap(dice[adjacent[curDice][2]][i][2], dice[adjacent[curDice][3]][i][2]);
            }
        }
    }
}

void Solve() {
    for (pair<char, char> p: v) {
        int curDice = m[p.first];
        char dir = p.second;
        rotate(dir, curDice);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dice[0][i][j];
        }
        cout << '\n';
    }
}

void setDice() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                dice[i][j][k] = color[i];
            }
        }
    }
}

void Init() {
    setDice();
    cin >> N;
    v.resize(N, {});
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}
