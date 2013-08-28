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

using namespace std;

long long A[145][145];
long long ret[145][145];
long long tmp[145][145];
long long foo[145][145];
const long long mod = 1000000007;

void mul(long long (*A)[145], long long (*B)[145]) {
    memcpy(foo, A, sizeof foo);
    for (int i=0; i<145; ++i) {
        for (int j=0; j<145; ++j) {
            A[i][j] = 0;
            for (int k=0; k<145; ++k) {
                A[i][j] += foo[i][k]*B[k][j];
                if (A[i][j] >= mod) {
                    A[i][j] %= mod;
                }
            }
        }
    }
}
void raise(long long k) {
    memset(ret, 0, sizeof ret);
    for (int i=0; i<145; ++i) {
        ret[i][i] = 1;
    }
    while (k > 0) {
        if (k & 1) mul(ret, A);
        memcpy(tmp, A, sizeof tmp);
        mul(A, tmp);
        k /= 2;
    }
    memcpy(A, ret, sizeof A);
}

class ConversionMachine {
public:
    int countAll(string word1, string word2, vector <int> costs, int maxCost) {
        long long base_cost = 0;
        long long steps = 0;
        for (int i=0; i<(int)word1.size(); ++i) {
            if (word1[i] < word2[i]) {
                steps += word2[i]-word1[i];
                base_cost += costs[word1[i]-'a'];
                if (word2[i] - word1[i] == 2) {
                    assert(word2[i] == 'c');
                    base_cost += costs[1];
                }
            } else if (word1[i] > word2[i]) {
                steps += word2[i]-word1[i]+3;
                base_cost += costs[word1[i]-'a'];
                if (word1[i] - word2[i] == 1) {
                    base_cost += (word2[i]=='b') ? costs[0] : costs[2];
                }
            }
        }

        if (maxCost < base_cost) {
            return 0;
        }
        maxCost -= int(base_cost);

        long long C = (long long)costs[0] + costs[1] + costs[2];
        steps += maxCost/C*3;

        int n = word1.size();
        memset(A, 0, sizeof A);
        for (int d1=0; d1<=n; ++d1) {
            for (int d2=0; d1+d2<=n; ++d2) {
                if (d1+d2 < n) {
                    A[d1*12+d2][d1*12+(d2+1)] = n-(d1+d2);
                }
                if (d1 > 0) {
                    A[d1*12+d2][(d1-1)*12+d2] = d1;
                }
                if (d2 > 0) {
                    A[d1*12+d2][(d1+1)*12+(d2-1)] = d2;
                }
            }
        }
        A[0][144] = 1;
        A[144][144] = 1;
        raise(steps+1);

        int d1 = 0;
        int d2 = 0;
        for (int i=0; i<n; ++i) {
            int d = word2[i] - word1[i];
            if (d < 0) {
                d += 3;
            }
            if (d == 1) {
                ++d1;
            } else if (d == 2) {
                ++d2;
            }
        }
        
        return int(A[d1*12+d2][144]);
    }
};
