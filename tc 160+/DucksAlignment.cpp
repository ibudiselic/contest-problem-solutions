#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int my_abs(int x) { return x<0 ? -x : x; }

class DucksAlignment {
public:
    int minimumTime(vector <string> grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                cnt += (grid[i][j]=='o');
            }
        }
        if (cnt == 0) {
            return 0;
        }
        int sol = 1234567890;
        for (int iter=0; iter<2; ++iter) {
            for (int i=0; i<m; ++i) {
                for (int j=0; j+cnt<=n; ++j) {
                    int k = 0;
                    int cand = 0;
                    int start = 0;
                    while (k < cnt) {
                        while (start < n) {
                            bool done = false;
                            for (int l=0; l<m; ++l) {
                                if (grid[l][start] == 'o') {
                                    cand += my_abs(l-i) + my_abs(start-(j+k));
                                    done = true;
                                    break;
                                }
                            }
                            ++start;
                            if (done) {
                                break;
                            }
                        }
                        ++k;
                    }
                    sol = min(sol, cand);
                }
            }
            vector<string> other(n, string(m, ' '));
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    other[j][i] = grid[i][j];
                }
            }
            grid.swap(other);
            swap(m, n);
        }
        return sol;
    }
};
