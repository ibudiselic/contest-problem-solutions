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
#include <cmath>

using namespace std;

bool done[50][1001];
double dp[50][1001];
vector<int> A;
int N;
double go(int at, int heads) {
    if (at == (int)A.size()) {
        return heads;
    }
    if (done[at][heads]) {
        return dp[at][heads];
    }
    done[at][heads] = 1;
    double &ret = dp[at][heads];
    int lo = max(0, A[at]-(N-heads));
    int hi = min(heads, A[at]);
    double prob = 1.0;
    for (int ch=0; ch<lo; ++ch) {
        prob *= double(A[at]-ch)/(ch+1);
        prob *= double(heads-ch)/(N-ch);
    }
    for (int ct=0; ct<A[at]-lo; ++ct) {
        prob *= double(N-heads-ct)/(N-lo-ct);
    }
    
    ret = 0.0;
    for (int ch=lo; ch<=hi; ++ch) {
        ret += prob * go(at+1, heads-ch+(A[at]-ch));
        prob *= double(A[at]-ch)/(ch+1);
        prob *= double(heads-ch)/(N-heads-A[at]+ch+1);
    }
    return ret;
}
class CoinReversing {
public:
    double expectedHeads(int N, vector <int> a) {
        memset(done, 0, sizeof done);
        A = a;
        ::N = N;
        return go(0, N);
    }
};
