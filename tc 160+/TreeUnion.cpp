//# trees, merging, cycles, combinatorics, distance
//# => The key observation is that any cycle will have two endpoints in one tree and two endpoints in the other tree, with pairs of endpoints being connected during merging. The distances between these endpoints are not changed by merging.
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
#include <sstream>

using namespace std;

using tree_t = vector<vector<int>>;

tree_t maketree(const vector<string> &T) {
    string s = accumulate(begin(T), end(T), string());
    vector<int> v;
    istringstream is(s);
    for (int x; is>>x;) v.push_back(x);
    tree_t G(v.size()+1);
    for (int i=0; i<(int)v.size(); ++i) {
        G[i+1].push_back(v[i]);
        G[v[i]].push_back(i+1);
    }
    return G;
}
void dist_init(int u, int p, int d, vector<int> &D, const vector<vector<int>> &T) {
    D[u] = d;
    for (int i=0; i<(int)T[u].size(); ++i) {
        int v = T[u][i];
        if (v != p) {
            dist_init(v, u, d+1, D, T);
        }
    }
}
vector<vector<int>> distances(const tree_t &T) {
    int n = T.size();
    vector<vector<int>> D(n, vector<int>(n, 0));
    for (int i=0; i<n; ++i) {
        dist_init(i, -1, 0, D[i], T);
    }
    return D;
}
class TreeUnion {
public:
    double expectedCycles(vector <string> tree1, vector <string> tree2, int K) {
        tree_t T1 = maketree(tree1);
        tree_t T2 = maketree(tree2);
        vector<vector<int>> D1 = distances(T1);
        vector<vector<int>> D2 = distances(T2);

        int n = T1.size();
        vector<vector<int>> cnts(n, vector<int>(K, 0));
        for (int a=0; a<n; ++a) {
            for (int b=a+1; b<n; ++b) {
                if (D2[a][b] < K) {
                    ++cnts[a][D2[a][b]];
                }
            }
        }

        double sol = 0.0;
        for (int u=0; u<n; ++u) {
            for (int v=u+1; v<n; ++v) {
                int remdist = K - D1[u][v] - 2;
                if (remdist > 0) {
                    for (int a=0; a<n; ++a) {
                        sol += 2*cnts[a][remdist];
                    }
                }
            }
        }
        sol /= n;
        sol /= n-1;
        return sol;
    }
};
