//# dp, mountains, counting, simple dp
//# => figure out the "forced peaks" and the total number of possible peak locations... then count the number of sequences of peaks that are chosen from these available peaks and also cover all the forced peaks
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
int total;
int totmust;
int dp[51][2501];
int go(int rem, int must) {
    int &ret = dp[rem][must];
    if (ret != -1) {
        return ret;
    }
    if (rem == 0) {
        ret = (must==0 ? 1 : 0);
    } else {
        ret = modmul(total-must, go(rem-1, must));
        if (must > 0) {
            ret = modadd(ret, modmul(must, go(rem-1, must-1)));
        }
    }
    return ret;
}
class MountainsEasy {
public:
    int countPlacements(vector <string> picture, int K) {
        int m = picture.size();
        int n = picture[0].size();
        total = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (picture[i][j] == 'X') {
                    ++total;
                }
            }
        }
        int must = 0;
        int rem = total;
        while (rem > 0) {
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (picture[i][j] == 'X') {
                        ++must;
                        for (int r=i; r<m; ++r) {
                            for (int c=max(0, j-(r-i)); c<min(n, j+1+(r-i)); ++c) {
                                if (picture[r][c] == 'X') {
                                    --rem;
                                    picture[r][c] = '.';
                                }
                            }
                        }
                        goto NEXT;
                    }
                }
            }
            NEXT:;
        }
        memset(dp, 0xff, sizeof dp);
        totmust = must;
        return go(K, must);
    }
};
