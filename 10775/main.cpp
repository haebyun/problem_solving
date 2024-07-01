#include <iostream>
#include <vector>
using namespace std;

int G, P, res;
vector<int> parent;

int Find(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

void Solve() {
    for(int i=0; i<P; i++) {
        int n; cin>>n;
        int par = Find(n);
        if (!par) {
            break;
        }
        Union(par, par - 1);
        res++;
    }
    cout << res << '\n';
}

void Init() {
    cin >> G >> P;
    parent.resize(G + 1);
    for (int i = 1; i <= G; i++) {
        parent[i] = i;
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
