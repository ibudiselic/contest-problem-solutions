#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
class TheBrickTowerMediumDivTwo {
public:
    vector <int> find(vector <int> heights) {
        vector<pii> H;
        int n = heights.size();
        for (int i=0; i<n; ++i) {
            H.push_back(make_pair(heights[i], i));
        }
        sort(H.begin(), H.end());
        vector<int> sol;
        int sol_len = 1234567;
        do {
            int cand_len = 0;
            for (int i=1; i<n; ++i) {
                cand_len += max(H[i-1].first, H[i].first);
            }
            vector<int> cand;
            for (int i=0; i<n; ++i) {
                cand.push_back(H[i].second);
            }
            if (cand_len<sol_len || (cand_len==sol_len && cand<sol)) {
                sol = cand;
                sol_len = cand_len;
            }
        } while (next_permutation(H.begin(), H.end()));
        return sol;
    }
};
