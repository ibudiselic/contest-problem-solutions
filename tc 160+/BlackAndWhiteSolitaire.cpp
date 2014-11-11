//# easy, implementation, strings
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

class BlackAndWhiteSolitaire {
public:
    int minimumTurns(string cardFront) {
        vector<int> v(cardFront.size(), 0);
        int n = v.size();
        for (int i=0; i<n; ++i) {
            v[i] = (cardFront[i]=='B');
        }
        int sol = n;
        for (int start=0; start<2; ++start) {
            int cand = 0;
            int cur = start;
            for (int i=0; i<n; ++i, cur=1-cur) {
                cand += (v[i]!=cur);
            }
            sol = min(sol, cand);
        }
        return sol;
    }
};
