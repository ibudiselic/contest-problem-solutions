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

bool ok(const string &s) {
    vector<int> cnt(26);
    for (int i=0; i<(int)s.size(); ++i) {
        if (++cnt[s[i]-'a'] > 1) {
            return false;
        }
    }
    return true;
}
class ChocolateBar {
public:
    int maxLength(string letters) {
        int sol = 0;
        for (int i=0; i<(int)letters.size(); ++i) {
            for (int j=i; j<(int)letters.size(); ++j) {
                if (ok(letters.substr(i, j-i+1))) {
                    sol = max(sol, j-i+1);
                }
            }
        }
        return sol;
    }
};
