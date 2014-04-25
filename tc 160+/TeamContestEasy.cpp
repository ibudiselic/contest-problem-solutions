//# greedy, teams, rank, implementation
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

bool done[50];
class TeamContestEasy {
public:
    int worstRank(vector <int> S) {
        int n = S.size();
        if (n == 3) return 1;
        vector<int> me(begin(S), begin(S)+3);
        sort(begin(me), end(me));
        vector<int> others(begin(S)+3, end(S));
        n -= 3;
        sort(begin(others), end(others));
        int need = me.back() + me[1];

        int i = n-1;
        int j = 0;
        int k = 0;
        memset(done, 0, sizeof done);
        int sol = 1;
        while (i>=0 && !done[i]) {
            int val = others[i];
            done[i] = 1;
            --i;
            while (j<n && (done[j] || val+others[j]<=need)) {
                ++j;
            }
            if (j == n) {
                return sol;
            }
            done[j] = 1;
            ++j;
            while (k<n && done[k]) {
                ++k;
            }
            if (k == n) {
                return sol;
            }
            done[k] = 1;
            ++k;
            ++sol;
        }
        return sol;
    }
};
