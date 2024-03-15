#include <iostream>
#include <vector>
using namespace std;

int N, res{0};
vector<bool> isPrime;
vector<int> primes;

void Solve() {
    if(N==1){
        cout<<0<<'\n';
        return;
    }
    int l{0}, r{0}, sum{0};
    int last_idx = primes.size()-1;
    while (true) {
        if (sum == N) {
            res++;
            if(r>last_idx) {
                break;
            }
            sum+=primes[r++];
        }
        else if (sum > N) {
            sum -= primes[l++];
        }
        else if (sum < N) {
            if(r>last_idx) {
                break;
            }
            sum += primes[r++];
        }
    }
    cout<<res<<'\n';
}

void Init() {
    cin >> N;
    isPrime.resize(N + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int k = i + i; k <= N; k += i) {
                isPrime[k] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    Init();
    Solve();
    return 0;
}
