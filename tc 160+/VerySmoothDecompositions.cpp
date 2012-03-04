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

const int mod = 1000000009;
int P[] = {2, 3, 5, 7, 11, 13};
int power[6];
int p2[] = {2, 1, 3, 0, 2, 4}; // 2^p2 * 3^p3 = {4, 6, 8, 9, 12, 16}
int p3[] = {0, 1, 0, 2, 1, 0};

bool div(vector<int> &D, int d) {
    int val = 0;
    for (int i=(int)D.size()-1; i>=0; --i) {
        val = 10*val + D[i];
        D[i] = val/d;
        val %= d;
    }
    while (D.size()>0 && D.back()==0) {
        D.pop_back();
    }
    return val == 0;
}
class VerySmoothDecompositions {
public:
    int solve(vector <string> digits) {
        vector<int> D;
        for (int i=(int)digits.size()-1; i>=0; --i) {
            for (int j=(int)digits[i].size()-1; j>=0; --j) {
                D.push_back(digits[i][j] - '0');
            }
        }
        for (int i=0; i<6; ++i) {
            power[i] = 0;
            while (1) {
                vector<int> tmp = D;
                if (div(tmp, P[i])) {
                    D = tmp;
                    ++power[i];
                } else {
                    break;
                }
            }
        }
        if (D.size()>1 || D[0]>1) {
            return 0;
        }
        
        vector< vector<int> > ways23(power[0]+1, vector<int>(power[1]+1, 1)); // 1 way to use all 2s and 3s
        for (int i=0; i<6; ++i) {
            for (int p=p2[i]; p<=power[0]; ++p) {
                for (int q=p3[i]; q<=power[1]; ++q) {
                    ways23[p][q] += ways23[p-p2[i]][q-p3[i]];
                    if (ways23[p][q] >= mod) {
                        ways23[p][q] -= mod;
                    }
                }
            }
        }
        
        long long sol = 0;
        vector<int> partial(power[0]+2, 0);
        for (int p15=0; p15<=min(power[1], power[2]); ++p15) {
            for (int i=1; i<=power[0]+1; ++i) {
                partial[i] = partial[i-1] + ways23[i-1][power[1]-p15];
                if (partial[i] >= mod) {
                    partial[i] -= mod;
                }
            }
            for (int p14=0; p14<=min(power[0], power[3]); ++p14) {
                sol += partial[power[0]-p14+1] - partial[power[0]-p14-min(power[0]-p14, power[2]-p15)];
            }
        }
        return (sol%mod + mod)%mod;
    }
};
