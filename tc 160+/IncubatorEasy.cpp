#include <algorithm>
#include <cassert>
#include <cctype>
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

int bc[1<<10];
class IncubatorEasy {
public:
    int maxMagicalGirls(vector <string> love) {
        int n = love.size();
        for (int mask=1; mask<(1<<n); ++mask) {
            bc[mask] = bc[mask>>1] + (mask&1);
        }
        
        vector<int> G(n);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (love[i][j] == 'Y') {
                    G[i] |= 1<<j;
                }
            }
        }
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                if (G[i] & (1<<k)) {
                    G[i] |= G[k];
                }
            }
        }

        int sol = 0;
        for (int magical=1; magical<(1<<n); ++magical) {
            int prot = 0;
            for (int i=0; i<n; ++i) {
                if (magical & (1<<i)) {
                    prot |= G[i];
                }
            }
            sol = max(sol, bc[magical&~prot]);
        }
        return sol;
    }
};
