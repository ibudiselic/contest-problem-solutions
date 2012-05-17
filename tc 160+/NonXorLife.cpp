#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int BASE = 1500;
bool A[3050][3050];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
class NonXorLife {
public:
    int countAliveCells(vector <string> field, int K) {
        memset(A, 0, sizeof A);
        int m = field.size();
        int n = field[0].size();
        queue< pair<int, int> > Q;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (field[i][j] == 'o') {
                    Q.push(make_pair(i, j));
                    A[i+BASE][j+BASE] = 1;
                }
            }
        }
        int sol = 0;
        int layer_sz = 0;
        int dist = 0;
        while (!Q.empty()) {
            if (layer_sz == 0) {
                layer_sz = Q.size();
                ++dist;
            }
            --layer_sz;
            pair<int, int> tmp = Q.front();
            Q.pop();
            int i = tmp.first;
            int j = tmp.second;
            ++sol;
            if (dist <= K) {
                for (int d=0; d<4; ++d) {
                    int r = i + di[d];
                    int c = j + dj[d];
                    if (!A[r+BASE][c+BASE]) {
                        A[r+BASE][c+BASE] = 1;
                        Q.push(make_pair(r, c));
                    }
                }
            }
        }

        return sol;
    }
};
