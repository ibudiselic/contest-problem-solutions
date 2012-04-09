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

vector<int> W;
int go(int l, int r) {
    if (l+1 == r) {
        return 0;
    }
    int ret = 0;
    for (int i=l+1; i<r; ++i) {
        ret = max(ret, go(l, i) + go(i, r));
    }
    ret += W[l]*W[r];
    return ret;
}
class CasketOfStarEasy {
public:
    int maxEnergy(vector <int> weight) {
        W = weight;
        return go(0, W.size()-1);
    }
};
