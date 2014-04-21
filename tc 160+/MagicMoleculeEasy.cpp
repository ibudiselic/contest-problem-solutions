//# brute force, graph, molecules, clique, vertex cover, complement graph
//# => See the MagicMolecule problem (this is the same except we're working with the graph itself rather than the complement).
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

const int MAXE = 2000;
int a[MAXE], b[MAXE];
int n;
int E;
typedef pair<int, int> pii;
vector<pii> P;
const int MAXN = 55;
bool used[MAXN];
int sol;
void go(int e, int need) {
    if (e == E) {
        int total = 0;
        for (int i=0; i<n; ++i) {
            if (used[i]) {
                total += P[i].first;
            } else if (need > 0) {
                total += P[i].first;
                --need;
            }
        }
        if (need == 0) {
            sol = max(sol, total);
        }
    } else {
        if (used[a[e]] || used[b[e]]) {
            go(e+1, need);
        } else if (need > 0) {
            used[a[e]] = 1;
            go(e+1, need-1);
            used[a[e]] = 0;

            used[b[e]] = 1;
            go(e+1, need-1);
            used[b[e]] = 0;
        }
    }
}
class MagicMoleculeEasy {
public:
    int maxMagicPower(vector <int> magicPower, vector <string> magicBond, int k) {
        n = magicPower.size();
        P.clear();
        for (int i=0; i<n; ++i) {
            P.push_back(pii(magicPower[i], i));
        }
        sort(begin(P), end(P));
        reverse(begin(P), end(P));
        E = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (magicBond[P[i].second][P[j].second] == 'Y') {
                    a[E] = i;
                    b[E] = j;
                    ++E;
                }
            }
        }

        sol = -1;
        go(0, k);
        return sol;
    }
};
