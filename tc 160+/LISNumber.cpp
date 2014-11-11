//# increasing subsequence, subsequence, dp
//# => The state space is [i][j] where i is the number of smallest values used and j is the number of increasing subsequences in the current sequence (ways[i][j] counts the number of ways to get to that state). At each state when adding a new value, there are two options. Either the value will be added to the last subsequence (extending it) or it wont. Then we get to choose how many new values we will put before or after the previus sequence and how many groups except the last one we will close. At that point, it becomes a combinatorial problem to figure out the transitions.
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

const int mod = 1000000007;
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
const int MAXC = 2000+2;
int C[MAXC+1][MAXC+1];
const int MAXK = 1300+2;
int ways[2][MAXK];
class LISNumber {
public:
    int count(vector <int> cnt, int K) {
        C[0][0] = 1;
        for (int n=1; n<=MAXC; ++n) {
            C[n][0] = 1;
            for (int k=1; k<=n; ++k) {
                C[n][k] = modadd(C[n-1][k-1], C[n-1][k]);
            }
        }
        memset(ways, 0, sizeof ways);
        ways[0][cnt[0]] = 1;
        int total = cnt[0];
        for (int i=1; i<(int)cnt.size(); ++i) {
            int cur = i&1;
            int prev = 1-cur;
            int x = cnt[i];
            for (int k=1; k<=K; ++k) {
                if (ways[prev][k] == 0) continue;
                int w = ways[prev][k];
                ways[prev][k] = 0;
                // close last group
                for (int baf=0; baf<x; ++baf) { // before or after
                    for (int c=0; c<k && c<x-baf; ++c) { // groups except last to close
                        int pickpos = total - k + c;
                        assert(pickpos >= 0);
                        int nk = k + (x-1-c);
                        if (nk > K) continue;
                        int pickways;
                        if (x-1-baf-c == 0) {
                            pickways = 1;
                        } else if (pickpos < 2) {
                            pickways = pickpos;
                        } else {
                            pickways = C[x-1-baf-c+pickpos-1][pickpos-1];
                        }
                        int closeways = C[k-1][c];
                        int add = modmul(w, pickways);
                        add = modmul(add, baf+1);
                        add = modmul(add, closeways);
                        ways[cur][nk] = modadd(ways[cur][nk], add);
                    }
                }
                // don't close last group (can't put any after)
                for (int b=0; b<=x; ++b) {
                    for (int c=0; c<k && c<=x-b; ++c) {
                        int pickpos = total - k + c;
                        assert(pickpos >= 0);
                        int nk = k + (x-c);
                        if (nk > K) continue;
                        int pickways;
                        if (x-b-c == 0) {
                            pickways = 1;
                        } else if (pickpos < 2) {
                            pickways = pickpos;
                        } else {
                            pickways = C[x-b-c+pickpos-1][pickpos-1];
                        }
                        int closeways = C[k-1][c];
                        int add = modmul(w, pickways);
                        add = modmul(add, closeways);
                        ways[cur][nk] = modadd(ways[cur][nk], add);
                    }
                }
            }
            /*
            for (int k=1; k<=K; ++k) {
                cerr << ways[cur][k] << ' ';
            }
            cerr << '\n';
            */
            total += cnt[i];
        }
        return ways[(cnt.size()+1)&1][K];
    }
};
