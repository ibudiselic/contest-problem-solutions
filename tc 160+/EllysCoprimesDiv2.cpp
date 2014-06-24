//# coprimes, primes, dp
//# => Sort the numbers and solve each pair independently. The key insight is that you will never need to add more than a few numbers (turns out only 2 for the constraints) for each pair because primes are pretty dense... There is a better solution in the editorial.
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

const int MAXN = 100000+2;
vector<int> pfacts[MAXN];
int D[MAXN];
vector<int> primes;
void init(int n) {
    memset(D, 0, (n+1)*(sizeof *D));
    D[1] = 1;
    primes.clear();
    for (int i=2; i<=n; ++i) {
        if (D[i] == 0) {
            primes.push_back(i);
            D[i] = i;
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=D[i] && primes[j]<=n/i; ++j) {
            D[i*primes[j]] = primes[j];
        }
    }

    for (int i=2; i<=n; ++i) {
        pfacts[i].clear();
        int x = i;
        while (x > 1) {
            if (pfacts[i].size()==0 || pfacts[i].back()!=D[x]) {
                pfacts[i].push_back(D[x]);
            }
            x /= D[x];
        }
    }
}
bool intersect(int x, int y) {
    const vector<int> &a = pfacts[x];
    const vector<int> &b = pfacts[y];
    int i = 0;
    int j = 0;
    while (i<(int)a.size() && j<(int)b.size()) {
        if (a[i] == b[j]) return true;
        else if (a[i] < b[j]) ++i;
        else ++j;
    }
    return false;
}

vector<int> A;
int dp[51][MAXN];
const int inf = 123456789;
int go(int at, int last) {
    int &ret = dp[at][last];
    if (ret != -1) {
        return ret;
    }
    if (at == (int)A.size()) {
        ret = 0;
    } else {
        if (!intersect(A[at], last)) {
            ret = go(at+1, A[at]);
        } else {
            ret = inf;
            for (int x=last+1; x<A[at]; ++x) {
                if (!intersect(x, last)) {
                    ret = min(ret, 1+go(at, x));
                    if (!intersect(x, A[at])) {
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
class EllysCoprimesDiv2 {
public:
    int getCount(vector <int> numbers) {
       sort(begin(numbers), end(numbers));
       init(numbers.back());
       A = numbers;
       memset(dp, 0xff, sizeof dp);
       return go(0, 0);
    }
};
