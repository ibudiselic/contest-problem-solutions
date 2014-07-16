//# undo, strings, prefix
//# => There are two options at every new word - either reuse the buffer from the previous word or use the longest prefix from any of the previous words.
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

int prefixlen(string &a, string &b) {
    for (int i=0; i<(int)a.size() && i<(int)b.size(); ++i) {
        if (a[i] != b[i]) {
            return i;
        }
    }
    return min(a.size(), b.size());
}
class UndoHistory {
public:
    int minPresses(vector <string> lines) {
        int sol = 0;
        for (int i=0; i<(int)lines.size(); ++i) {
            int prev = (i==0 ? 0 : prefixlen(lines[i-1], lines[i]));
            int prefix = 0;
            for (int j=0; j<i - 1; ++j) {
                int cand = prefixlen(lines[i], lines[j]);
                prefix = max(prefix, cand);
            }
            sol += min((i>0&&prev==(int)lines[i-1].size() ? 0 : 2) + (int)lines[i].size()-prev, 2 + (int)lines[i].size()-prefix) + 1;
        }
        return sol - 2;
    }
};
