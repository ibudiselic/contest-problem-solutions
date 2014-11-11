//# trees, merging, cycles, combinatorics, permutations, brute force, distance, shortest paths
//# => Try all permutations.
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

vector<vector<int>> dist(vector<string> &T) {
    int n = T.size();
    vector<vector<int>> D(n, vector<int>(n, 12345));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (T[i][j] == 'X') {
                D[i][j] = 1;
            }
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
    return D;
}
class TreeUnionDiv2 {
public:
    int maximumCycles(vector <string> tree1, vector <string> tree2, int K) {
        int n = tree1.size();
        vector<vector<int>> D1 = dist(tree1);
        vector<vector<int>> D2 = dist(tree2);

        vector<int> order;
        for (int i=0; i<n; ++i) {
            order.push_back(i);
        }

        int sol = 0;
        do {
            int cand = 0;
            for (int a=0; a<n; ++a) {
                for (int b=a+1; b<n; ++b) {
                    cand += (2+D1[a][b]+D2[order[a]][order[b]]==K);
                }
            }
            sol = max(sol, cand);
        } while(next_permutation(begin(order), end(order)));

        return sol;
    }
};
