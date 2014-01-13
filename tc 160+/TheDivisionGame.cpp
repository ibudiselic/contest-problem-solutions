//# integers, division, xor
//# => this is a nim game with pile sizes equal to the number of prime factors of each number... the key subproblem to solve is factoring a large sequence of very large consecutive integers... the idea here is to cycle through divisors and then through those numbers in the sequenece that are a multiple of that divisor instead of the other way around (only consider prime divisors of course...)
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

const int LIM = 32000;
int D[LIM];
class TheDivisionGame {
public:
    long long countWinningIntervals(int L, int R) {
        vector<int> primes;
        memset(D, 0, sizeof D);
        vector<int> ndivs(R-L+1);
        vector<int> vals(R-L+1);
        for (int i=L; i<=R; ++i) {
            vals[i-L] = i;
        }
        for (int n=2; n<=R/n; ++n) {
            if (D[n] == 0) {
                D[n] = n;
                for (int v=(L+n-1)/n*n; v<=R; v+=n) {
                    do {
                        ++ndivs[v-L];
                        vals[v-L] /= n;
                    } while (vals[v-L]%n == 0);
                }
                primes.push_back(n);
            }
            for (int i=0; i<(int)primes.size() && primes[i]<=D[n] && primes[i]<=R/n/n/primes[i]; ++i) {
                D[primes[i]*n] = primes[i];
            }
        }

        vector<int> xors(1, 0);
        for (int n=L; n<=R; ++n) {
            if (vals[n-L] > 1) ++ndivs[n-L];
            xors.push_back(xors.back() ^ ndivs[n-L]);
        }

        long long sol = (long long)(R-L+2)*(R-L+1)/2;
        map<int, int> prefix_cnt;
        prefix_cnt[0] = 1;
        for (int i=1; i<(int)xors.size(); ++i) {
            sol -= prefix_cnt[xors[i]];
            ++prefix_cnt[xors[i]];
        }

        return sol;
    }
};
