#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<int> W;
int C;
bool can(int T) {
    long long foxes = 1;
    int cur = 0;
    for (int i=0; i<(int)W.size(); ++i) {
        if (foxes==0 || cur+W[i]>T) {
            return false;
        }
        int nsplits = (T-cur-W[i])/C;
        while (i+foxes<(int)W.size() && nsplits--) {
            foxes <<= 1;
            cur += C;
        }
        assert(cur + W[i] <= T);
        --foxes;
    }
    return true;
}
class FoxAndDoraemon {
public:
    int minTime(vector <int> workCost, int splitCost) {
        W = workCost;
        sort(W.begin(), W.end(), greater<int>());
        C = splitCost;
        int lo = 1;
        int hi = 2;
        while (!can(hi)) {
            lo = hi + 1;
            hi <<= 1;
        }
        
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (can(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
