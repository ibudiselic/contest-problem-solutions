#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <map>

using namespace std;

map<int, int> use;
vector<long long> F;
int need;
void gen(int i, int n, int mask, long long val) {
    if (val > need) {
        return;
    }
    if (use.count(int(val)) == 0) {
        use[int(val)] = mask;
    }
    if (i == n) {
        return;
    }
    gen(i+1, n, mask, val);
    gen(i+1, n, mask|(1<<i), val+F[i]);
}
void output(int a, int A, int b, int B) {
    int cnt = 0;
    for (int i=0; i<a; ++i) {
        if (A & (1<<i)) {
            ++cnt;
        }
    }
    for (int i=0; i<b; ++i) {
        if (B & (1<<i)) {
            ++cnt;
        }
    }
    if (cnt == 1) {
        cout << "2\n0 ";
    } else {
        cout << cnt << '\n';
    }
    bool space = false;
    for (int i=0; i<a; ++i) {
        if (A & (1<<i)) {
            if (space) {
                cout << ' ';
            }
            space = true;
            cout << F[i];
        }
    }
    for (int i=0; i<b; ++i) {
        if (B & (1<<i)) {
            if (space) {
                cout << ' ';
            }
            space = true;
            cout << F[a + i];
        }
    }
    cout << '\n';
}
bool gen2(int i, int a, int b, int mask, long long val) {
    if (val > need) {
        return false;
    }
    int rem = need - int(val);
    map<int, int>::const_iterator it = use.find(rem);
    if (it != use.end()) {
        output(a, it->second, b, mask);
        return true;
    }
    if (i == b) {
        return false;
    }
    if (!gen2(i+1, a, b, mask, val)) {
        return gen2(i+1, a, b, mask|(1<<i), val + F[a+i]);
    }
    return true;
}
int main() {
    int s, k;
    cin >> s >> k;
    need = s;
    F.push_back(0);
    F.push_back(1);
    int n = k + 1;
    long long next = 0;
    while (true) {
        next -= (n-k < k ? 0 : F[n-2*k]);
        next += F.back();
        ++n;
        if (next > s) {
            break;
        }
        F.push_back(next);
    }
    assert(F[1] == F[2]);
    F.erase(F.begin()+1);

    n = F.size();
    int a = n/2;
    int b = n - a;
    gen(0, a, 0, 0);
    gen2(0, a, b, 0, 0);

    return 0;
}
