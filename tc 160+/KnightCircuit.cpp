//# case, graph search
//# => examine cases carefully... solve small cases with brute force, larger ones need to be figured out (parity, gcd)
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

int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
bool can[22][100010];
int bf(int w, int h, int a, int b) {
    if (w < h) swap(w, h);
    int di[] = {-a, -a, a, a, -b, -b, b, b };
    int dj[] = {-b, b, -b, b, -a, a, -a, a };
    memset(can, 0, sizeof can);
    typedef pair<int, int> pii;
    int ret = 0;
    for (int x=0; x<h; ++x) {
        for (int y=0; y<w; ++y) {
            if (can[x][y]) continue;
            int cand = 1;
            queue<pii> Q;
            Q.push(pii(x, y));
            can[x][y] = 1;
            while (!Q.empty()) {
                int i = Q.front().first;
                int j = Q.front().second;
                Q.pop();
                for (int d=0; d<8; ++d) {
                    int r = i+di[d];
                    int c = j+dj[d];
                    if (r<0 || c<0 || r>=h || c>=w || can[r][c]) continue;
                    can[r][c] = 1;
                    Q.push(pii(r, c));
                    ++cand;
                }
            }
            ret = max(ret, cand);
        }
    }

    return ret;
}
class KnightCircuit {
public:
    long long maxSize(int w, int h, int a, int b) {
        int d = gcd(a, b);
        if (d > 1) {
            return maxSize((w-1)/d + 1, (h-1)/d + 1, a/d, b/d);
        }

        if (min(w, h) <= 20) {
            return bf(w, h, a, b);
        } else {
            if ((a+b)%2 == 0) {
                return ((long long)w*h+1)/2;
            } else {
                return (long long)w*h;
            }
        }
    }
};
