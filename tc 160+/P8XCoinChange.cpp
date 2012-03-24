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

const int mod = 1000003;
typedef vector< vector<int> > matrix;

inline matrix empty(int n) {
    return matrix(n, vector<int>(n, 0));
}
matrix I(int n) {
    matrix ret = empty(n);
    for (int i=0; i<n; ++i) {
        ret[i][i] = 1;
    }
    return ret;
}
void inc(int &x) {
    if (++x >= mod) {
        x -= mod;
    }
}
matrix mul(const matrix &A, const matrix &B) {
    int n = A.size();
    matrix ret = empty(n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            long long val = 0;
            for (int k=0; k<n; ++k) {
                val += (long long)A[i][k]*B[k][j];
            }
            ret[i][j] = int(val%mod);
        }
    }
    return ret;
}
matrix fastexp(matrix A, long long n) {
    matrix ret = I(A.size());
    while (n > 0) {
        if (n & 1) {
            ret = mul(ret, A);
        }
        A = mul(A, A);
        n >>= 1;
    }
    return ret;
}

class P8XCoinChange {
public:
    int solve(long long coins_sum, vector<long long> values) {
        int n = values.size();
        vector<matrix> ways;
        ways.push_back(empty(n));
        for (int i=0; i<n; ++i) {
            ways.back()[i][0] = 1;
        }
        
        for (int i=1; i<n; ++i) {
            long long cnt = values[i]/values[i-1];
            ways.push_back(fastexp(ways.back(), cnt));
            for (int j=i; j<n; ++j) {
                inc(ways.back()[j][i]);
            }
        }
        
        matrix total = I(n);
        for (int i=n-1; i>=0; --i) {
            long long cnt = coins_sum / values[i];
            coins_sum %= values[i];
            total = mul(total, fastexp(ways[i], cnt));
        }
    
        long long sol = 0;
        for (int i=0; i<n; ++i) {
            sol += total[n-1][i];
        }
        
        return int(sol%mod);
    }
};
