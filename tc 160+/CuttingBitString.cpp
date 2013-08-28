#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<long long> p5;
const int inf = 1234;
int best[51];
bool is_p5(const string &s) {
    if (s[0] == '0') {
        return false;
    }
    long long val = 1;
    for (int i=1; i<(int)s.size(); ++i) {
        val = 2*val + (s[i]-'0');
    }
    return p5.count(val);
}
class CuttingBitString {
public:
    int getmin(string S) {
        long long p = 1;
        do {
            p5.insert(p);
            p *= 5;
        } while (p < (1ll<<50));
        best[0] = 0;
        int n = S.size();
        for (int i=0; i<n; ++i) {
            best[i+1] = inf;
            for (int j=0; j<=i; ++j) {
                if (best[j]<inf && is_p5(S.substr(j, i-j+1))) {
                    best[i+1] = min(best[i+1], best[j]+1);
                }
            }
        }

        return best[n]==inf ? -1 : best[n];
    }
};
