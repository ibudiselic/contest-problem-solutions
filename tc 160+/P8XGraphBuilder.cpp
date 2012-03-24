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

vector<int> S;
int treedp[52][2];
int nodedp[50][51][51];
int tree(int, bool);
int node(int distribute, int at, int need) {
    int &ret = nodedp[distribute][at][need];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    if (at != need) {
        for (int i=0; i<=distribute; ++i) {
            ret = max(ret, tree(i+1, 0) + node(distribute-i, at+1, need));
        }
    }
    return ret;
}
int tree(int n, bool root) {
    int &ret = treedp[n][root];
    if (ret != -1) {
        return ret;
    }
    if (n == 1) {
        assert(!root);
        ret = S[0];
    } else {
        ret = 0;
        for (int deg=1; deg<n; ++deg) {
            ret = max(ret, S[!root + deg - 1] + node(n-1-deg, 0, deg));
        }
    }
    return ret;
}
class P8XGraphBuilder {
public:
    int solve(vector <int> scores) {
        S = scores;
        memset(treedp, 0xff, sizeof treedp);
        memset(nodedp, 0xff, sizeof nodedp);
        return tree(S.size() + 1, 1);
    }
};
