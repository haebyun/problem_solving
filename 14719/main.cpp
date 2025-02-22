#include <iostream>
using namespace std;

int H, W, res;
int Map[501][501];

bool pour_right(int x, int y) {
    if (Map[y][x] == 1) {
        return false;
    }
    if (Map[y][x] == 2) {
        return true;
    }
    int nx = x + 1;
    if (nx > W) {
        return false;
    }
    if (pour_right(nx, y)) {
        Map[y][x] = 1;
        res++;
        return true;
    }
    return false;
}

void Solve() {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (Map[i][j] == 2) {
                pour_right(j + 1, i);
            }
        }
    }
    cout << res << '\n';
}

void Init() {
    cin >> H >> W;
    for (int i = 1; i <= W; i++) {
        int h;
        cin >> h;
        for (int j = 1; j <= h; j++) {
            Map[j][i] = 2;
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
