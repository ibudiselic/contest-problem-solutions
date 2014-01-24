//# probability, cards, dp, simple dp, shuffling
//# => count the number of instances of each value and basically dp the total expectation backwards (E = 1 when there's just one card, E(i) = 1 + p*(E(i+1)-1) + (1-p)E(i) otherwise)
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

const int MAXN = 55;
int cnt[MAXN];
int rem[MAXN];
class ShuffleSort {
public:
    double shuffle(vector <int> cards) {
        memset(cnt, 0, sizeof cnt);
        sort(cards.begin(), cards.end());
        int n = cards.size();
        for (int i=0; i<n; ++i) {
            ++cnt[cards[i]];
        }
        for (int i=0; i<n; ++i) {
            rem[i] = cnt[cards[i]]--;
        }
        double sol = 1.0;
        for (int i=n-2; i>=0; --i) {
            double p = double(rem[i])/(n - i);
            sol = (1+p*(sol-1))/p;
        }
        return sol;
    }
};
