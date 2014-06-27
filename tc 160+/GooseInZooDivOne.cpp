//# combinatorics, dfs, connected components, manhattan distance
//# => Find connected components and the parity of their sizes. Then compute the number of ways to pick the components so that the total size is even (via dp or using binomial coefficients).
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

vector<string> A;
int m, n;
int D;
bool done[50][50];
int dfs(int i, int j) {
    int ret = 1;
    done[i][j] = 1;
    for (int r=0; r<m; ++r) {
        for (int c=0; c<n; ++c) {
            if (A[r][c]=='v' && !done[r][c] && abs(r-i)+abs(c-j)<=D) {
                ret += dfs(r, c);
            }
        }
    }

    return ret;
}

const int mod = 1000000007;
int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}

class GooseInZooDivOne {
public:
    int count(vector <string> field, int dist) {
        A = field;
        m = A.size();
        n = A[0].size();
        D = dist;
        memset(done, 0, sizeof done);
        vector<int> sizes;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j]=='v' && !done[i][j]) {
                    sizes.push_back(dfs(i, j));
                }
            }
        }

        int ways[2][2];
        memset(ways, 0, sizeof ways);
        ways[1][0] = 1;
        for (int i=0; i<(int)sizes.size(); ++i) {
            int cur = i&1;
            int prev = 1-cur;
            ways[cur][0] = modadd(ways[prev][0], ways[prev][sizes[i]&1]);
            ways[cur][1] = modadd(ways[prev][1], ways[prev][1 - (sizes[i]&1)]);
        }

        return modadd(ways[int(sizes.size()+1)&1][0], mod-1);
    }
};
