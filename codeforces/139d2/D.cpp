#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct foo {
    int i, j, tail;
    foo(int i_, int j_, int tail_): i(i_), j(j_), tail(tail_) {}
};
int m, n;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
vector<string> A;
bool B[15][15];
bool done[15][15][1<<16];
void put(int i, int j, int tail, int len, bool can) {
    --len;
    while (--len) {
        int d = (tail>>(2*len))&3;
        i += di[d];
        j += dj[d];
        B[i][j] = can;
    }
}
int main() {
    cin >> m >> n;
    for (int i=0; i<m; ++i) {
        string s;
        cin >> s;
        A.push_back(s);
    }
    int ai=-1, aj=-1, hi=-1, hj=-1;
    int len = -1;
    int tail = 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (A[i][j] == '@') {
                ai = i;
                aj = j;
                A[i][j] = '.';
            } else if (A[i][j] == '1') {
                hi = i;
                hj = j;
                int a = i;
                int b = j;
                char need = '2';
                A[i][j] = '.';
                while (true) {
                    bool found = false;
                    for (int d=0; d<4; ++d) {
                        int r = a + di[d];
                        int c = b + dj[d];
                        if (r<0 || c<0 || r>=m || c>=n) {
                            continue;
                        }
                        if (A[r][c] == need) {
                            tail = (tail<<2) | d;
                            a = r;
                            b = c;
                            A[r][c] = '.';
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        break;
                    }
                    ++need;
                }
                len = need - '1';
            }
        }
    }
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            B[i][j] = (A[i][j] == '.');
        }
    }

    queue<foo> Q;
    done[hi][hj][tail] = 1;
    Q.push(foo(hi, hj, tail));
    int layer_sz = 0;
    int dist = 0;
    while (!Q.empty()) {
        if (layer_sz == 0) {
            layer_sz = Q.size();
            ++dist;
        }
        --layer_sz;
        const foo tmp = Q.front();
        Q.pop();
        int i = tmp.i;
        int j = tmp.j;
        int tail = tmp.tail;
        put(i, j, tail, len, 0);
        for (int d=0; d<4; ++d) {
            int r = i + di[d];
            int c = j + dj[d];
            if (r<0 || c<0 || r>=m || c>=n || !B[r][c]) {
                continue;
            }
            if (r==ai && c==aj) {
                cout << dist << '\n';
                return 0;
            }
            int revd = d + 2;
            if (revd > 3) {
                revd -= 4;
            }
            int ntail = (tail>>2) | (revd<<(2*(len-2)));
            if (!done[r][c][ntail]) {
                done[r][c][ntail] = 1;
                Q.push(foo(r, c, ntail));
            }
        }
        put(i, j, tail, len, 1);
    }

    cout << "-1\n";

    return 0;
}
