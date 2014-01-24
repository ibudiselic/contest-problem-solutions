//# implementation, brute force
//# => fix goto buckets for each color (O(n^3)) and then greedily remove the lower two counts from all other buckets...
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

class BallsSeparating {
public:
    int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
        int n = red.size();
        const int inf = 1234567890;
        int sol = inf;
        for (int r=0; r<n; ++r) {
            for (int g=0; g<n; ++g) {
                if (g == r) continue;
                for (int b=0; b<n; ++b) {
                    if (b==r || b==g) continue;
                    int cand = 0;
                    for (int i=0; i<n; ++i) {
                        if (i == r) cand += green[i]+blue[i];
                        else if (i == g) cand += red[i]+blue[i];
                        else if (i == b) cand += green[i]+red[i];
                        else cand += red[i]+green[i]+blue[i] - max(red[i], max(green[i], blue[i]));
                    }
                    sol = min(sol, cand);
                }
            }
        }
        return sol==inf ? -1 : sol;
    }
};
