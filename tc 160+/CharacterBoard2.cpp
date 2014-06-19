//# strings, matrix, seed, counting, combinatorics
//# => See CharacterBoard. The simplification here is that we can simply go through all the possible lengths as there is only 10^4 of them.
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

const int mod = 1000000009;
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}
int modexp(int n, int k) {
    int ret = 1;
    while (k > 0) {
        if (k&1) ret = modmul(ret, n);
        n = modmul(n, n);
        k /= 2;
    }
    return ret;
}
class CharacterBoard2 {
public:
    int countGenerators(vector <string> fragment, int W, int i0, int j0) {
        int m = fragment.size();
        int n = fragment[0].size();
        int sol = 0;
        for (int L=1; L<=W; ++L) {
            vector<char> decided(L, ' ');
            int numdecided = 0;
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    int pos = ((i0+i)*W + j0+j)%L;
                    if (decided[pos] == ' ') {
                        decided[pos] = fragment[i][j];
                        ++numdecided;
                    } else if (decided[pos] != fragment[i][j]) {
                        goto IMPOSSIBLE;
                    }
                }
            }
            sol = modadd(sol, modexp(26, L-numdecided));
            IMPOSSIBLE:;
        }
        return sol;
    }
};
