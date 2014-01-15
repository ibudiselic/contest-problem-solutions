//# implementation, trivial
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

class PenguinTiles {
public:
    int minMoves(vector <string> tiles) {
        int m = tiles.size();
        int n = tiles[0].size();
        int si, sj;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (tiles[i][j] == '.') {
                    si = i;
                    sj = j;
                }
            }
        }
        if (si==m-1 && sj==n-1) return 0;
        if (si==m-1 || sj==n-1) return 1;
        return 2;
    }
};
