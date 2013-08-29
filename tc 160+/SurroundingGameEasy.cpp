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

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
class SurroundingGameEasy {
public:
    int score(vector <string> cost, vector <string> benefit, vector <string> stone) {
        int m = cost.size();
        int n = cost[0].size();
        int sol = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (stone[i][j] == 'o') {
                    sol += benefit[i][j] - cost[i][j];
                } else {
                    bool ok = true;
                    for (int d=0; d<4; ++d) {
                        int r = i + di[d];
                        int c = j + dj[d];
                        if (r<0 || c<0 || r>=m || c>=n) continue;
                        if (stone[r][c] != 'o') {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        sol += benefit[i][j] - '0';
                    }
                }
            }
        }

        return sol;
    }
};
