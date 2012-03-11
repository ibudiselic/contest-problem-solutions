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

string S;
bool done[2][1<<14];
bool A[2][1<<14];
bool go(bool a, int mask) {
    if (done[a][mask]) {
        return A[a][mask];
    }
    done[a][mask] = 1;
    bool &ret = A[a][mask];
    int cnt = 0;
    char c;
    for (int i=0; i<(int)S.size(); ++i) {
        if (!(mask & (1<<i))) {
            ++cnt;
            c = S[i];
        }
    }
    if (cnt == 1) {
        return ret = (c=='A');
    }
    for (int i=0; i<(int)S.size(); ++i) {
        if (!(mask & (1<<i))) {
            int t = 0;
            for (int j=i; j<(int)S.size() && !(mask & (1<<j)); ++j) {
                t |= (1<<j);
                if ((mask|t) == (1<<(int)S.size())-1) {
                    break;
                }
                if (a && go(0, mask | t)) {
                    return ret = true;
                }
                if (!a && !go(1, mask | t)) {
                    return ret = false;
                }
            }
        }
    }
    return (ret = !a);
}
class RowAndCoins {
public:
    string getWinner(string cells) {
        S = cells;
        memset(done, 0, sizeof done);
        return go(1, 0) ? "Alice" : "Bob";
    }
};
