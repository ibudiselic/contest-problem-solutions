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
class FlipGame {
public:
    int minOperations(vector <string> board) {
        int sol = 0;
        int i = 0;
        while (i < (int)board.size()) {
            int j = (int)board[i].size()-1;
            while (j>=0 && board[i][j]=='0') {
                --j;
            }
            if (j == -1) {
                ++i;
                continue;
            }
            ++sol;
            for (int k=0; k<=j; ++k) {
                flip(board[i][k]);
            }
            for (int r=i+1; r<(int)board.size(); ++r) {
                int c = (int)board[r].size()-1;
                while (c>j && board[r][c]=='0') {
                    --c;
                }
                j = c;
                for (int k=0; k<=j; ++k) {
                    flip(board[r][k]);
                }
            }
        }

        return sol;
    }
};
