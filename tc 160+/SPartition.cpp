#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n;
long long A, B;
long long dp[22][22];
long long go(int l, int r) {
    long long &ret = dp[l][r];
    if (ret != -1) {
        return ret;
    }
    if (l>n/2 || r>n/2) {
        return (ret = 0);
    }
    if (l==n/2 && r==n/2) {
        return (ret = 1);
    }
    ret = 0;
    if (((B>>l)&1) == ((A>>(r+l))&1)) {
        ret += go(l+1, r);
    }
    if (((B>>r)&1) == ((A>>(r+l))&1)) {
        ret += go(l, r+1);
    }
    return ret;
}
long long ways(long long B) {
    ::B = B;
    memset(dp, 0xff, sizeof dp);
    return go(0, 0);
}
int bc(long long x) {
    return x==0 ? 0 : bc(x>>1) + (x&1);
}
class SPartition {
public:
    long long getCount(string s) {
        n = s.size();
        A = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == 'o') {
                A |= (1ll<<i);
            }
        }
        int cnt = bc(A);
        long long sol = 0;
        for (int i=0; i<(1<<(n/2)); ++i) {
            if (2*bc(i) == cnt) {
                sol += ways(i);
            }
        }
        return sol;
    }
};
