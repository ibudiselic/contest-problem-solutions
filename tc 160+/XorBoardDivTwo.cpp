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

using namespace std;

inline void flip(char &c) {
    c = (c=='0' ? '1' : '0');
}
class XorBoardDivTwo {
public:
    int theMax(vector <string> board) {
        int m = board.size();
        int n = board[0].size();
        int sol = 0;
        for (int r=0; r<m; ++r) {
            for (int j=0; j<n; ++j) {
                flip(board[r][j]);
            }
            for (int c=0; c<n; ++c) {
                for (int i=0; i<m; ++i) {
                    flip(board[i][c]);
                }
                int cand = 0;
                for (int i=0; i<m; ++i) {
                    for (int j=0; j<n; ++j) {
                        cand += (board[i][j]=='1');
                    }
                }
                sol = max(sol, cand);
                
                for (int i=0; i<m; ++i) {
                    flip(board[i][c]);
                }
            }
            for (int j=0; j<n; ++j) {
                flip(board[r][j]);
            }
        }
        return sol;
    }
};
