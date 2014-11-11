//# color, cells, permutations, implementation, brute force
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

class ColorTheCells {
public:
    int minimalTime(vector <int> T) {
        int n = T.size();
        vector<int> order;
        for (int i=0; i<n; ++i) {
            order.push_back(i);
        }

        int sol = 1234567890;
        vector<int> block(n);
        do {
            for (int lr=0; lr<(1<<n); ++lr) {
                vector<int> cells;
                int cand = 0;
                int at = 0;
                for (int i=0; i<n; ++i) {
                    int c = order[i];
                    bool right = (lr>>c)&1;
                    if ((c==n-1 && right) || (c==0 && !right)) goto NEXT;
                    cells.push_back(c - 1 + right*2);
                }
                fill(begin(block), end(block), 0);
                for (int i=0; i<n && cand<sol; ++i) {
                    int to = cells[i];
                    while (at < to) {
                        cand = max(cand, block[++at]) + 1;
                    }
                    while (at > to) {
                        cand = max(cand, block[--at]) + 1;
                    }
                    ++cand;
                    block[order[i]] = cand + T[order[i]];
                }
                sol = min(sol, cand);

                NEXT:;
            }
        } while (next_permutation(begin(order), end(order)));

        return sol;
    }
};
