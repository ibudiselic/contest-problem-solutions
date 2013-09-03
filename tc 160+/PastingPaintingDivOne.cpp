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

class PastingPaintingDivOne {
public:
    vector<long long> countColors(vector <string> B, int T) {
        int m = B.size();
        int n = B[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                switch(B[i][j]) {
                    case 'R': B[i][j] = 0; break;
                    case 'G': B[i][j] = 1; break;
                    case 'B': B[i][j] = 2; break;
                    default: B[i][j] = 3; break;
                }
            }
        }
        vector<string> A(m+1, string(n+1, 3));

        vector<long long> sol(4);
        for (int t=0; t<T; ++t) {
            vector<long long> delta(4);
            vector<string> An(m+1, string(n+1, 3));
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (B[i][j] != 3) {
                        --delta[A[i+1][j+1]];
                        --sol[A[i+1][j+1]];
                        ++delta[B[i][j]];
                        ++sol[B[i][j]];
                        An[i][j] = B[i][j];
                    } else {
                        An[i][j] = A[i+1][j+1];
                    }
                }
            }
            if (An == A) {
                for (int i=0; i<3; ++i) {
                    sol[i] += (T-t-1)*delta[i];
                }
                sol.pop_back();
                return sol;
            }
            A.swap(An);
        }
        sol.pop_back();
        return sol;
    }
};
