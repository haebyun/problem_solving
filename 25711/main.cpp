#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int N, M;
vector<pair<int, int>> v, cmp;
vector<double> Sum, reverseSum;

double getUpDis(double dx, double dy) {
    return sqrt(pow(dx, 2) + pow(dy, 2)) * 3;
}

double getLinerDis(double dx) {
    return dx * 2;
}

double getDownDis(double dx, double dy) {
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

void Solve() {
    for (int i = 0; i < M; i++) {
        int start = cmp[i].first;
        int end = cmp[i].second;
        if (start < end) {
            cout << Sum[end] - Sum[start] << '\n';
        } else {
            cout << reverseSum[end] - reverseSum[start] << '\n';
        }
    }
}

void Init() {
    cin >> N >> M;
    v.resize(N + 1);
    cmp.resize(M + 1);
    Sum.resize(N + 1);
    reverseSum.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        v[i].first = x;
    }
    for (int i = 1; i <= N; i++) {
        int y;
        cin >> y;
        v[i].second = y;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cmp[i] = {a, b};
    }
    for (int i = 1; i < N; i++) {
        double dx = v[i + 1].first - v[i].first;
        double dy = v[i + 1].second - v[i].second;
        double tmp;
        if (dy > 0) {
            tmp = getUpDis(dx, dy);
        } else if (dy == 0) {
            tmp = getLinerDis(dx);
        } else {
            tmp = getDownDis(dx, -dy);
        }
        Sum[i + 1] = Sum[i] + tmp;
    }
    for (int i = N - 1; i >= 1; i--) {
        double dx = v[i + 1].first - v[i].first;
        double dy = v[i + 1].second - v[i].second;
        double tmp;
        if (dy > 0) {
            tmp = getDownDis(dx, dy);
        } else if (dy == 0) {
            tmp = getLinerDis(dx);
        } else {
            tmp = getUpDis(dx, -dy);
        }
        reverseSum[i] = reverseSum[i + 1] + tmp;
    }
    cout << fixed << setprecision(15);
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
