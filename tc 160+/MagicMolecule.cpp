//# brute force, graphs, molecules
//# => The key insight is that at most 16 nodes can be not-selected. We're looking for the minimal weight vertex cover in the complement graph. Process the edges in order - if neither endpoint is taken, try to take one (2 choices), otherwise don't do anything.
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<int> P;
int n;
const int MAXN = 55;
bool used[MAXN];
const int MAXE = MAXN*MAXN;
int A[MAXE], B[MAXE];
int E;
int sol;
void go(int e, int rem) {
    if (e == E) {
        int total = 0;
        for (int i=0; i<n; ++i) {
            if (!used[i]) {
                total += P[i];
            }
        }
        sol = max(sol, total);
    } else {
        if (used[A[e]] || used[B[e]]) {
            go(e+1, rem);
        } else if (rem > 0) {
            used[A[e]] = 1;
            go(e+1, rem-1);
            used[A[e]] = 0;

            used[B[e]] = 1;
            go(e+1, rem-1);
            used[B[e]] = 0;
        }
    }
}
class MagicMolecule {
public:
    int maxMagicPower(vector <int> magicPower, vector <string> magicBond) {
        n = magicPower.size();
        int take = n - (2*n+2)/3;
        assert(take <= 16);
        P = magicPower;
        E = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (magicBond[i][j] == 'N') {
                    A[E] = i;
                    B[E] = j;
                    ++E;
                }
            }
        }
        sol = -1;
        memset(used, 0, sizeof used);
        go(0, take);
        return sol;
    }
};
