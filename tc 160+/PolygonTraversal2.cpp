//# polygon, permutations, brute force
//# => Only 11! possible orders so try them all.
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

bool intersects(int a, int b, int x, int y) {
    if (a > b) swap(a, b);
    for (int iter=0; iter<2; ++iter) {
        if (a<y && y<b && (x<a || x>b)) {
            return true;
        }
        swap(x, y);
    }
    return false;
}

int last;
vector<int> P;
bool ok(int prev, int p, const vector<int> &R) {
    int x = R[p];
    for (int i=1; i<(int)P.size(); ++i) {
        if (intersects(prev, x, P[i-1], P[i])) {
            return true;
        }
    }
    for (int i=0; i<p; ++i) {
        if (intersects(prev, x, R[i], last)) {
            return true;
        }
    }
    return false;
}
class PolygonTraversal2 {
public:
    int count(int N, vector <int> points) {
        int taken = 0;
        for (int i=0; i<(int)points.size(); ++i) {
            --points[i];
            taken |= (1<<points[i]);
        }
        P = points;
        last = P.back();
        vector<int> rem;
        for (int i=0; i<N; ++i) {
            if (!(taken & (1<<i))) {
                rem.push_back(i);
            }
        }
        int sol = 0;
        do {
            for (int i=0; i<(int)rem.size(); ++i) {
                if (!ok(i==0?last:rem[i-1], i, rem)) {
                    goto FAIL;
                }
            }
            if (ok(P[0], int(rem.size())-1, rem)) {
                ++sol;
            }
            FAIL:;
        } while (next_permutation(rem.begin(), rem.end()));
        return sol;
    }
};
