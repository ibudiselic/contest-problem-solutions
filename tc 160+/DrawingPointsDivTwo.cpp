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

const int MAXN = 110;
bool B[MAXN][MAXN];
bool can(int W, vector<int> &r, vector<int> &c) {
    memset(B, 0, sizeof B);
    for (int i=0; i<(int)r.size(); ++i) {
        for (int dr=0; dr<W; ++dr) {
            for (int dc=0; dc<W; ++dc) {
                B[r[i]+dr][c[i]+dc] = 1;
            }
        }
    }
    int wxw = 0;
    for (int i=0; i+W<=MAXN; ++i) {
        for (int j=0; j+W<=MAXN; ++j) {
            for (int dr=0; dr<W; ++dr) {
                for (int dc=0; dc<W; ++dc) {
                    if (!B[i+dr][j+dc]) {
                        goto SKIP;
                    }
                }
            }
            ++wxw;
            SKIP:;
        }
    }
    assert(wxw >= (int)r.size());
    return wxw == (int)r.size();
}
class DrawingPointsDivTwo {
public:
    int maxSteps(vector <string> points) {
        vector<int> r, c;
        for (int i=0; i<(int)points.size(); ++i) {
            for (int j=0; j<(int)points[i].size(); ++j) {
                if (points[i][j] == '*') {
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        int k = 2;
        while (k < 25) {
            if (!can(k, r, c)) {
                return k-2;
            }
            ++k;
        }
        return -1;
    }
};
