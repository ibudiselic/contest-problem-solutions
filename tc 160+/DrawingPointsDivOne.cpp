#include <algorithm>
#include <cassert>
#include <cctype>
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

const int N = 300;
int B[N][N];
bool can(int W, vector<int> &x, vector<int> &y) {
    memset(B, 0, sizeof B);
    int n = x.size();
    for (int i=0; i<n; ++i) {
        for (int dx=0; dx<W; ++dx) {
            for (int dy=0; dy<W; ++dy) {
                B[x[i]+dx][y[i]+dy] = 1;
            }
        }
    }
    for (int i=N-2; i>=0; --i) {
        for (int j=N-2; j>=0; --j) {
            B[i][j] += B[i+1][j] + B[i][j+1] - B[i+1][j+1];
        }
    }
    const int need = W*W;
    int num = 0;
    for (int i=N-W-1; i>=0; --i) {
        for (int j=N-W-1; j>=0; --j) {
            if (B[i][j]-B[i+W][j]-B[i][j+W]+B[i+W][j+W] == need) {
                ++num;
            }
        }
    }
    assert(num >= n);
    return num == n;
}
class DrawingPointsDivOne {
public:
    int maxSteps(vector <int> x, vector <int> y) {
        int n = x.size();
        for (int i=0; i<n; ++i) {
            x[i] += 70;
            y[i] += 70;
        }
        int lo = 1;
        int hi = 142;
        while (lo < hi) {
            int mid = lo + (hi-lo+1)/2;
            if (can(mid, x, y)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo==142 ? -1 : lo-1;
    }
};
