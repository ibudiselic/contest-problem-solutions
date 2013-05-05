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

struct sol_repr {
    int len;
    int digcnt[10];
    sol_repr(): len(0) {
        memset(digcnt, 0, sizeof digcnt);
    }
    void output() {
        if (len == -1) {
            puts("-1");
        } else {
            bool ok = false;
            for (int i=9; i>0; --i) {
                if (digcnt[i] > 0) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                puts("0\n");
            } else {
                for (int i=9; i>=0; --i) {
                    for (int j=0; j<digcnt[i]; ++j) {
                        putchar(char('0' + i));
                    }
                }
                putchar('\n');
            }
        }
    }
};
bool operator<(const sol_repr &a, const sol_repr &b) {
    if (a.len != b.len) {
        return a.len < b.len;
    } else {
        for (int i=9; i>=0; --i) {
            if (a.digcnt[i] != b.digcnt[i]) {
                return a.digcnt[i] < b.digcnt[i];
            }
        }
        return false;
    }
}
int D[10];
int seq[] = {1, 4, 7, 2, 5, 8};
int chosen[] = {0, 0, 0, 0, 0, 0};
sol_repr sol;
void update() {
    sol_repr cand;
    for (int i=0; i<6; ++i) {
        int d = seq[i];
        int dmod = chosen[i];
        int take = (D[d]-1)/3*3 + dmod;
        if (take+3 <= D[d]) {
            take += 3;
        }
        if (take > D[d]) {
            take -= 3;
        }
        assert(take%3 == dmod);
        assert(take >= 0);
        assert(take <= D[d]);
        cand.len += take;
        cand.digcnt[d] = take;
    }
    if (sol < cand) {
        sol = cand;
    }
}
void go(int at, int modsum=0) {
    if (at == 6) {
        if (modsum%3 == 0) {
            update();
        }
    } else {
        int d = seq[at];
        for (int i=0; i<=min(2, D[d]); ++i) {
            chosen[at] = i;
            go(at+1, modsum + (at<3 ? 1 : 2)*i);
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        int d;
        scanf("%d", &d);
        ++D[d];
    }
    sol.len = -1;
    if (D[0] != 0) {
        go(0);
    }
    for (int i=0; i<10; ++i) {
        if (i%3 == 0) {
            sol.digcnt[i] = D[i];
        }
    }
    sol.output();
    return 0;
}
