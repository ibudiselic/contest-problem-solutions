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

int m, n;
inline bool valid(int i, int j) {
    return i>=0 && j>=0 && i<m && j<n;
}
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
inline int encode(int i, int j) {
    return i*n + j;
}
inline void decode(int code, int &i, int &j) {
    i = code/n;
    j = code - i*n;
}

int to[1024][4];
int cpos[2];
class CoinsGameEasy {
public:
    int minimalSteps(vector <string> board) {
        m = board.size();
        n = board[0].size();
        int nc = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'o') {
                    cpos[nc++] = encode(i, j);
                    board[i][j] = '.';
                }
            }
        }
        assert(nc == 2);

        const int OUT = m*n;
        for (int d=0; d<4; ++d) {
            to[OUT][d] = OUT;
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int at = encode(i, j);
                for (int d=0; d<4; ++d) {
                    int r = i + di[d];
                    int c = j + dj[d];
                    if (!valid(r, c)) {
                        to[at][d] = OUT;
                    } else if (board[r][c] == '#') {
                        to[at][d] = at;
                    } else {
                        to[at][d] = encode(r, c);
                    }
                }
            }
        }

        for (int steps=1; steps<=10; ++steps) {
            for (int mask=0; mask<(1<<(2*steps)); ++mask) {
                int p[2] = {cpos[0], cpos[1]};
                int dirs = mask;
                for (int step=0; step<steps; ++step) {
                    for (int i=0; i<2; ++i) {
                        p[i] = to[p[i]][dirs&3];
                    }
                    dirs >>= 2;
                    if ((p[0]==OUT)^(p[1]==OUT)) {
                        return steps;
                    }
                }
            }
        }
        return -1;
    }
};
