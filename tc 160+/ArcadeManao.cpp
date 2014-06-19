//# bfs, implementation
//# => trivial
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

vector<string> A;
int ti, tj;
typedef pair<int, int> pii;
bool done[55][55];
void upd(int i, int j, queue<pii> &Q) {
    if (i<0 || j<0 || i>=(int)A.size() || j>=(int)A[0].size() || done[i][j] || A[i][j]!='X') return;
    done[i][j] = 1;
    Q.push(pii(i, j));
}
bool can(int L) {
    int m = A.size();
    memset(done, 0, sizeof done);
    done[m-1][0] = 1;
    queue<pii> Q;
    Q.push(pii(m-1, 0));
    while (!Q.empty()) {
        pii at = Q.front();
        Q.pop();
        if (at.first==ti && at.second==tj) {
            return true;
        }
        upd(at.first, at.second-1, Q);
        upd(at.first, at.second+1, Q);
        for (int i=0; i<m; ++i) {
            if (abs(i-at.first) <= L) {
                upd(i, at.second, Q);
            }
        }
    }
    return false;
}
class ArcadeManao {
public:
    int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
        ti = coinRow - 1;
        tj = coinColumn - 1;
        A = level;
        for (int i=0; i<55; ++i) {
            if (can(i)) {
                return i;
            }
        }
        return -1;
    }
};
