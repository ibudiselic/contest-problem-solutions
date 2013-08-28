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

using namespace std;

bool used[50];
vector<int> H;
int n;
pair<int, int> calc() {
    int m = 123456;
    int sum = 0;
    for (int i=0; i<n; ++i) {
        if (!used[i]) {
            sum += H[i];
            m = min(m, H[i]);
        }
    }
    return make_pair(sum-m, m);
}
class TheBrickTowerMediumDivOne {
public:
    vector <int> find(vector <int> heights) {
        H = heights;
        n = int(heights.size());
        if (n == 0) {
            return vector<int> (1, 0);
        }
        memset(used, 0, sizeof used);
        int best = calc().first;
        int cur = 0;
        vector<int> sol;
        for (int iter=0; iter<n-1; ++iter) {
            for (int i=0; i<n; ++i) {
                if (!used[i]) {
                    used[i] = 1;
                    int add = 0;
                    if (iter > 0) {
                        add = max(H[i], H[sol.back()]);
                    }
                    pair<int, int> next = calc();
                    if (cur+add+next.first+max(H[i], next.second) == best) {
                        sol.push_back(i);
                        cur += add;
                        break;
                    }
                    used[i] = 0;
                }
            }
        }
        for (int i=0; i<n; ++i) {
            if (!used[i]) {
                sol.push_back(i);
                break;
            }
        }
        return sol;
    }
};
