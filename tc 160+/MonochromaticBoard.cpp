#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class MonochromaticBoard {
public:
    int theMin(vector<string> board) {
        int cnt = 0;
        int m = board.size();
        int n = board[0].size();
        vector<string> cur(m, string(n, 'W'));
        bool found = false;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'W') {
                    found = true;
                    for (int k=0; k<m; ++k) {
                        if (board[k][j]=='B' && cur[k][j]=='W') {
                            ++cnt;
                            for (int l=0; l<n; ++l) {
                                cur[k][l] = 'B';
                            }
                        }
                    }
                    for (int l=0; l<n; ++l) {
                        if (board[i][l]=='B' && cur[i][l]=='W') {
                            ++cnt;
                            for (int k=0; k<m; ++k) {
                                cur[k][l] = 'B';
                            }
                        }
                    }
                }
            }
        }
        return found ? cnt : min(m, n);
    }
};
