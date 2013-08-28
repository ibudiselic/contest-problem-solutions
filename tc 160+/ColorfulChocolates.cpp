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

class ColorfulChocolates {
public:
    int maximumSpread(string C, int nswap) {
        int n = C.size();
        int sol = 0;
        for (int l=n; l>0; --l) {
            for (int i=0; i+l<=n; ++i) {
                bool ok = true;
                for (int j=i+1; j<i+l; ++j) {
                    if (C[j] != C[i]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;

                int sz = l;
                vector<int> cands;
                int have = 0;
                for (int j=i-1; j>=0; --j) {
                    if (C[j] == C[i]) {
                        cands.push_back(i-j-1-have);
                        ++have;
                    }
                }
                have = 0;
                for (int j=i+l; j<n; ++j) {
                    if (C[j] == C[i]) {
                        cands.push_back(j-i-1-have);
                        ++have;
                    }
                }
                sort(cands.begin(), cands.end());
                int k = nswap;
                for (int j=0; j<(int)cands.size() && k>=cands[j]; ++j) {
                    k -= cands[j];
                    ++sz;
                }
                sol = max(sol, sz);
            }
        }

        return sol;
    }
};
