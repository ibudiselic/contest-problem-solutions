//# shortest paths
//# => trivial
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

int D[50][50];
class Egalitarianism {
public:
    int maxDifference(vector <string> isFriend, int d) {
        int n = isFriend.size();
        int inf = 12345;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                D[i][j] = (isFriend[i][j]=='Y' ? 1 : inf);
            }
            D[i][i] = 0;
        }
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
                }
            }
        }

        int sol = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (D[i][j] == inf) {
                    return -1;
                } else {
                    sol = max(sol, D[i][j]);
                }
            }
        }
        return sol*d;
    }
};
