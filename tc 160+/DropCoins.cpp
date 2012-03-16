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

int S[31][31];
inline int cnt(int r1, int c1, int r2, int c2) {
    return S[r2+1][c2+1] - S[r1][c2+1] - S[r2+1][c1] + S[r1][c1];
}
class DropCoins {
public:
    int getMinimum(vector <string> board, int K) {
        memset(S, 0, sizeof S);
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                S[i+1][j+1] = S[i][j+1] + S[i+1][j] - S[i][j] + (board[i][j]=='o');
            }
        }
        
        int sol = 1234567890;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int a=i; a<m; ++a) {
                    for (int b=j; b<n; ++b) {
                        if (cnt(i, j, a, b) == K) {
                            sol = min(sol, 2*min(i, m-1-a) + max(i, m-1-a) + 2*min(j, n-1-b) + max(j, n-1-b));
                        }
                    }
                }
            }
        }
        return sol==1234567890 ? -1 : sol;
    }
};
