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

class PastingPaintingDivTwo {
public:
    long long countColors(vector <string> B, int T) {
        long long sol = 0;
        long long delta = 0;
        int m = B.size();
        int n = B[0].size();
        vector<string> A(m+1, string(n+1, '.'));
        for (int t=0; t<T; ++t) {
            vector<string> An(m+1, string(n+1, '.'));
            long long old = sol;
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (B[i][j] == '.') {
                        An[i][j] = A[i+1][j+1];
                    } else {
                        if (A[i+1][j+1] == 'B') {
                            --sol;
                        }
                        if (B[i][j] == 'B') {
                            ++sol;
                        }
                        An[i][j] = B[i][j];
                    }
                }
            }
            delta = sol - old;
            if (A == An) {
                return sol + (T-t-1)*delta;
            }
            A.swap(An);
        }
        return sol;
    }
};
