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

const long long mod = 1000000007ll;
vector< vector<long long> > mul(const vector< vector<long long> > &A, const vector< vector<long long> > &B) {
    vector< vector<long long> > ret(2, vector<long long>(2, 0));
    for (int i=0; i<2; ++i) {
        for (int j=0; j<2; ++j) {
            for (int k=0; k<2; ++k) {
                ret[i][j] = (ret[i][j] + A[i][k]*B[k][j]%mod)%mod;
            }
        }
    }
    return ret;
}
void fastexp(vector< vector<long long> > &A, long long n) {
    vector< vector<long long> > ret(2, vector<long long>(2, 0));
    ret[0][0] = ret[1][1] = 1;
    while (n > 0) {
        if (n & 1) {
            ret = mul(ret, A);
        }
        A = mul(A, A);
        n >>= 1;
    }
    A = ret;
}
class Chimney {
public:
    int countWays(long long n) {
        vector< vector<long long> > A(2, vector<long long>(2, 0));
        A[0][0] = 8; A[0][1] = -8+mod;
        A[1][0] = 1; A[1][1] = 0;
        fastexp(A, 2*n-1);
        return (A[0][0]*4%mod + A[0][1])%mod;
    }
};
