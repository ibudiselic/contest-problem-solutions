//# greedy, strings, permutations
//# => solve the subproblem for each string... the key observation is that if we can pick several letters to be the next letter in the alphabet and still remain the smallest string, it doesn't matter which letter we pick... this is because if we can eliminate some string s by using some character c1, but this string remains in contention if we pick c0, we will be able to eliminate it using c1 in the next step (or some step after that)
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

bool can(int x, vector< vector<int> > &cnts) {
    int n = cnts.size();
    vector<char> dead(n);
    vector<char> used(26);
    dead[x] = 1;
    while (1) {
        bool change = false;
        for (int c=0; c<26; ++c) {
            if (used[c]) continue;
            bool ok = true;
            for (int i=0; i<n; ++i) {
                if (dead[i]) continue;
                if (cnts[i][c] > cnts[x][c]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                change = true;
                used[c] = 1;
                for (int i=0; i<n; ++i) {
                    if (cnts[i][c] < cnts[x][c]) {
                        dead[i] = 1;
                    }
                }
                break;
            }
        }
        if (!change) {
            break;
        }
    }
    for (int i=0; i<n; ++i) {
        if (!dead[i]) {
            return false;
        }
    }
    return true;
}
class StringGame {
public:
    vector <int> getWinningStrings(vector <string> S) {
        int n = S.size();
        vector<vector<int> > cnts(n, vector<int>(26));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<(int)S[i].size(); ++j) {
                ++cnts[i][S[i][j]-'a'];
            }
        }

        vector<int> sol;
        for (int i=0; i<n; ++i) {
            if (can(i, cnts)) {
                sol.push_back(i);
            }
        }
        return sol;
    }
};
