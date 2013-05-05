#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n;
int A[300][300];
int best[301][301][301];
const int di[] = { 0, 1 };
const int dj[] = { 1, 0 };

const int inf = 987654321;
bool valid(int i, int j) {
    return (i>=0 && i<n && j>=0 && j<n);
}
bool done[301][301][301];
int calc(int i, int j, int r, int c) {
    if (!valid(i, j) || !valid(r, c)) {
        return -inf;
    }
    int &ret = best[i][j][r];
    if (done[i][j][r]) {
        return ret;
    }
    done[i][j][r] = 1;
    if (i==n-1 && j==n-1) {
        assert(r==n-1 && c==n-1);
        ret = A[i][j];
    } else {
        ret = -inf;
        for (int d=0; d<2; ++d) {
            for (int e=0; e<2; ++e) {
                ret = max(ret, calc(i+di[d], j+dj[d], r+di[e], c+dj[e]));
            }
        }
        ret += A[i][j];
        if (r!=i || j!=c) {
            ret += A[r][c];
        }
    }
    return ret;
}
int main() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> A[i][j];
        }
    }

    memset(done, 0, sizeof done);
    cout << calc(0, 0, 0, 0) << '\n';
    return 0;
} 
