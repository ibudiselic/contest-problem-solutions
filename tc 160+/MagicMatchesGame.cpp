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

class MagicMatchesGame {
public:
    long long minimumArea(vector <int> matches, vector <int> red, vector <int> blue) {
        int n = matches.size();
        
        vector<long long> bnum, bdenom;
        bnum.push_back(0); bdenom.push_back(1);
        bnum.push_back(1); bdenom.push_back(0);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                long long a = blue[j] - blue[i];
                long long b = red[i] - red[j];
                if (a>0 && b>0) {
                    bnum.push_back(a);
                    bdenom.push_back(b);
                }
            }
        }
        for (int i=0; i<(int)bnum.size(); ++i) {
            for (int j=i+1; j<(int)bnum.size(); ++j) {
                if (bnum[i]*bdenom[j] > bnum[j]*bdenom[i]) {
                    swap(bnum[i], bnum[j]);
                    swap(bdenom[i], bdenom[j]);
                }
            }
        }
        
        vector<long long> num, denom;
        for (int i=1; i<(int)bnum.size(); ++i) {
            num.push_back(bnum[i]*bdenom[i-1] + bnum[i-1]*bdenom[i]);
            denom.push_back(2*bdenom[i]*bdenom[i-1]);
        }

        long long sol = 0;
        int diamonds = -1;
        for (int factor=0; factor<(int)num.size(); ++factor) {
            long long a = num[factor];
            long long b = denom[factor];
            
            vector<int> order(n, 0);
            for (int i=0; i<n; ++i) {
                order[i] = i;
            }
#define VAL(idx) (a*red[order[(idx)]] + b*blue[order[(idx)]])
            for (int i=0; i<n; ++i) {
                for (int j=i+1; j<n; ++j) {
                    if (VAL(i) > VAL(j)) {
                        swap(order[i], order[j]);
                    }
                }
            }
            vector<int> A(n, 0);
            for (int i=0; i<n; ++i) {
                A[i] = matches[order[i]];
            }
            
            long long u = 0; // red
            long long v = 0; // blue
            int d = 0; // diamonds
            for (int i=0; i<n; ++i) { // Gaussian elim.
                if (A[i] != 0) {
                    u += red[order[i]];
                    v += blue[order[i]];
                    ++d;
                    int val = A[i];
                    int colbit = val ^ (val & (val-1));
                    assert(val & colbit);
                    assert(!(val & (colbit-1)));
                    for (int j=i+1; j<n; ++j) {
                        if (A[j] & colbit) {
                            A[j] ^= val;
                        }
                    }
                }
            }
            if (d>diamonds || (d==diamonds && u*v<sol)) {
                diamonds = d;
                sol = u*v;
            }
        }
        return sol;
    }
};
