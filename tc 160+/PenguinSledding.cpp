//# math, implementation, case analysis
//# => notice there are only two valid shapes - stars and triangles
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

bool G[55][55];
class PenguinSledding {
public:
    long long countDesigns(int n, vector <int> checkpoint1, vector <int> checkpoint2) {
        long long sol = 0;
        vector<int> deg(n);
        memset(G, 0, sizeof G);
        for (int i=0; i<(int)checkpoint1.size(); ++i) {
            ++deg[checkpoint1[i]-1];
            ++deg[checkpoint2[i]-1];
            G[checkpoint1[i]-1][checkpoint2[i]-1] = 1;
            G[checkpoint2[i]-1][checkpoint1[i]-1] = 1;
        }
        for (int i=0; i<n; ++i) {
            sol += 1ll<<deg[i];
            sol -= 1 + deg[i];
        }
        sol += 1 + (int)checkpoint1.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (!G[i][j]) continue;
                for (int k=j+1; k<n; ++k) {
                    if (G[i][k] && G[j][k]) {
                        ++sol;
                    }
                }
            }
        }

        return sol;
    }
};
