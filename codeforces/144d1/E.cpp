#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <bitset>

using namespace std;

const int MAXN = 500;

bool board[MAXN][MAXN];
bool readchar() {
    int c;
    while (1) {
        c = getchar();
        if (c == '.') return true;
        if (c == '#') return false;
    }
}

vector< vector< vector< bitset<MAXN> > > > dp_top(1024), dp_bot(1024);
void init(int node, int r1, int r2, int n) {
    if (r1 == r2) {
        return;
    }
    vector< vector< bitset<MAXN> > > &top = dp_top[node];
    vector< vector< bitset<MAXN> > > &bot = dp_bot[node];
    int mid = (r1+r2)/2;
    top.assign(mid-r1+1, vector< bitset<MAXN> >(n));
    bot.assign(r2-mid, vector< bitset<MAXN> >(n));

    for (int j=n-1; j>=0; --j) {
        if (board[mid][j]) {
            if (j+1 < n) {
                top[mid-r1][j] = top[mid-r1][j+1];
            }
            top[mid-r1][j].set(j);
        }
    }
    for (int i=mid-1; i>=r1; --i) {
        for (int j=n-1; j>=0; --j) {
            if (board[i][j]) {
                if (j+1 < n) {
                    top[i-r1][j] = top[i-r1][j+1];
                }
                top[i-r1][j] |= top[i+1-r1][j];
            }
        }
    }

    for (int j=0; j<n; ++j) {
        if (board[mid][j]) {
            if (j > 0) {
                bot[0][j] = bot[0][j-1];
            }
            bot[0][j].set(j);
        }
    }
    for (int i=mid+1; i<r2; ++i) {
        for (int j=0; j<n; ++j) {
            if (board[i][j]) {
                if (j > 0) {
                    bot[i-mid][j] = bot[i-mid][j-1];
                }
                bot[i-mid][j] |= bot[i-1-mid][j];
            }
        }
    }

    if (r1+1 < r2) {
        init(2*node, r1, mid, n);
        init(2*node+1, mid, r2, n);
    }
}
bool query(int node, int i1, int i2, int n, int r1, int c1, int r2, int c2) {
    int mid = (i1+i2)/2;
    if (r1<=mid && r2>=mid) {
        return (dp_top[node][r1-i1][c1] & dp_bot[node][r2-mid][c2]).any();
    }
    if (r2 < mid) {
        return query(2*node, i1, mid, n, r1, c1, r2, c2);
    } else {
        return query(2*node + 1, mid, i2, n, r1, c1, r2, c2);
    }
}
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            board[i][j] = readchar();
        }
    }
    init(1, 0, m, n);

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        --r1; --c1; --r2; --c2;
        puts(query(1, 0, m, n, r1, c1, r2, c2) ? "Yes" : "No");
    }

    return 0;
}
