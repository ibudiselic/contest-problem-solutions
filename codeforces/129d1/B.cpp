#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int calc(int x, int y, int n) {
    int nmistakes = 0;
    while (n>=0 && x!=y && y>0) {
        int cnt = (x-1)/y;
        nmistakes += cnt - 1;
        n -= cnt;
        x -= cnt * y;
        assert(x <= y);
        swap(x, y);
    }
    if (n!=1 || x!=1 || y!=1) {
        return 123456789;
    }
    return nmistakes;
}
void output(int x, int y) {
    string sol;
    bool T = true;
    while (x != y) {
        int cnt = (x-1)/y;
        sol += string(cnt, T ? 'T' : 'B');
        x -= cnt * y;
        swap(x, y);
        T = !T;
    }
    assert(x==1 && y==1);
    sol += (sol[(int)sol.size()-1]=='T' ? 'B' : 'T');
    reverse(sol.begin(), sol.end());
    if (sol[0] != 'T') {
        for (int i=0; i<(int)sol.size(); ++i) {
            sol[i] = (sol[i]=='T' ? 'B' : 'T');
        }
    }
    cout << sol << '\n';
}
int main() {
    cin.sync_with_stdio(false);
    int n, r;
    cin >> n >> r;
    if (r == 1) {
        cout << (n==1 ? "0\nT\n" : "IMPOSSIBLE\n");
        return 0;
    }
    int best = n;
    int best_other = -1;
    for (int other=1; other<r; ++other) {
        int cand = calc(r, other, n);
        if (cand < best) {
            best = cand;
            best_other = other;
        }
    }

    if (best_other == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << best << '\n';
        output(r, best_other);
    }

    return 0;
}
