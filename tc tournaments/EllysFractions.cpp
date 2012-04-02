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
#include <map>

using namespace std;

map<int, int> repr(int n) {
    assert(n > 1);
    map<int, int> ret;
    int d = 2;
    while (d*d <= n) {
        if (n%d == 0) {
            int cnt = 0;
            do {
                ++cnt;
                n /= d;
            } while (n%d == 0);
            ret[d] = cnt;
        }
        ++d;
    }
    if (n > 1) {
        ret[n] = 1;
    }
    return ret;
}
void mul(map<int, int> &r, const map<int, int> &other) {
    for (map<int, int>::const_iterator it=other.begin(); it!=other.end(); ++it) {
        r[it->first] += it->second;
    }
}
class EllysFractions {
public:
    long long getCount(int N) {
        long long sol = 0;
        map<int, int> r;
        for (int i=2; i<=N; ++i) {
            mul(r, repr(i));
            sol += (1ll<<(r.size()-1));
        }
        return sol;
    }
};
