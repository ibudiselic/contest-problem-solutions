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

using namespace std;

int left_value(const string &s) {
    int v = 0;
    for (int i=0; i<3 && s[i]!='.'; ++i) {
        v += s[i] - '0';
    }
    return v;
}
int right_value(string s) {
    reverse(s.begin(), s.end());
    return left_value(s);
}
int any(const string &s) {
    int ret = 0;
    int cur = 0;
    for (int i=0; i<3; ++i) {
        if (s[i] == '.') {
            ret = max(ret, cur);
            cur = 0;
        } else {
            cur += s[i] - '0';
        }
    }
    ret = max(ret, cur);
    return ret;
}
bool used[51];
class DengklekMakingChains {
public:
    int maxBeauty(vector <string> chains) {
        int n = chains.size();
        int one = 0;
        for (int i=0; i<n; ++i) {
            one = max(one, any(chains[i]));
        }
        int mid = 0;
        memset(used, 0, sizeof used);
        for (int i=0; i<n; ++i) {
            if (chains[i].find('.') == string::npos) {
                used[i] = true;
                mid += left_value(chains[i]);
            }
        }
        chains.push_back("..."); // dummy
        ++n;
        int add = 0;
        for (int i=0; i<n; ++i) {
            if (used[i]) continue;
            for (int j=0; j<n; ++j) {
                if (used[j] || i==j) continue;
                add = max(add, left_value(chains[i]) + right_value(chains[j]));
            }
        }
        return max(one, mid + add);
    }
};
