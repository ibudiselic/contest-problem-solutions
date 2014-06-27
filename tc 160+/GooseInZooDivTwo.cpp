//# easy, dfs, implementation, combinatorics, manhattan distance
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

const int mod = 1000000007;
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}
bool done[55][55];
vector<string> A;
int m, n;
int D;
void dfs(int i, int j) {
    done[i][j] = 1;
    for (int r=0; r<m; ++r) {
        for (int c=0; c<n; ++c) {
            if (A[r][c]=='v' && abs(i-r)+abs(j-c)<=D && !done[r][c]) {
                dfs(r, c);
            }
        }
    }
}
class GooseInZooDivTwo {
public:
    int count(vector <string> field, int dist) {
        A = field;
        m = A.size();
        n = A[0].size();
        D = dist;
        memset(done, 0, sizeof done);
        int sol = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j]=='v' && !done[i][j]) {
                    dfs(i, j);
                    sol = modadd(sol, sol);
                }
            }
        }

        return modadd(sol, mod-1);
    }
};
