//# binary search, implementation
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

bool can(vector <int> &girlStr, vector <int> &eStr, vector<long long> cnt, long long F) {
    int girl = 0;
    long long fatigue = 0;
    for (int i=0; i<(int)eStr.size(); ++i) {
        while (cnt[i] > 0) {
            while (girl<(int)girlStr.size() && girlStr[girl]<eStr[i]) {
                ++girl;
                fatigue = 0;
            }
            if (fatigue == F) {
                ++girl;
                fatigue = 0;
            }
            if (girl >= (int)girlStr.size()) {
                return false;
            }
            long long take = min(F-fatigue, cnt[i]);
            fatigue += take;
            cnt[i] -= take;
        }
    }
    return true;
}
class SpaceWarDiv1 {
public:
    long long minimalFatigue(vector <int> girlStr, vector <int> eStr, vector<long long> cnt) {
        for (int i=0; i<(int)eStr.size(); ++i) {
            for (int j=i+1; j<(int)eStr.size(); ++j) {
                if (eStr[i] > eStr[j]) {
                    swap(eStr[i], eStr[j]);
                    swap(cnt[i], cnt[j]);
                }
            }
        }
        sort(begin(girlStr), end(girlStr));
        if (girlStr.back() < eStr.back()) {
            return -1;
        }

        long long lo = 1;
        long long hi = 10000000000000000ll;
        while (lo < hi) {
            long long F = lo + (hi-lo)/2;
            if (can(girlStr, eStr, cnt, F)) {
                hi = F;
            } else {
                lo = F + 1;
            }
        }

        return lo;
    }
};
