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

bool can(int F, const vector <int> &str, const vector <int> &enemy, vector <int> eCnt) {
    int j = str.size() - 1;
    int rem = F;
    for (int i=(int)enemy.size()-1; i>=0; --i) {
        while (eCnt[i] > 0) {
            if (rem == 0) {
                --j;
                rem = F;
            }
            if (j<0 || str[j]<enemy[i]) return false;
            int take = min(rem, eCnt[i]);
            rem -= take;
            eCnt[i] -= take;
        }
    }
    return true;
}

class SpaceWarDiv2 {
public:
    int minimalFatigue(vector <int> str, vector <int> enemy, vector <int> eCnt) {
        sort(begin(str), end(str));
        int en = enemy.size();
        for (int i=0; i<en; ++i) {
            for (int j=i+1; j<en; ++j) {
                if (enemy[i] > enemy[j]) {
                    swap(enemy[i], enemy[j]);
                    swap(eCnt[i], eCnt[j]);
                }
            }
        }
        if (str.back() < enemy.back()) {
            return -1;
        }

        int lo = 1;
        int hi = 1000000;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (can(mid, str, enemy, eCnt)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
