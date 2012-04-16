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

int H[50][50];
int V[50][50];
int A[50][50];
class PasswordXGrid {
public:
    int minSum(vector <string> horizontal, vector <string> vertical) {
        int m = (int)horizontal.size() - 1;
        int n = horizontal[0].size();
        
        for (int i=0; i<=m; ++i) {
            for (int j=0; j<=n; ++j) {
                if (j < n) {
                    H[i][j] = horizontal[i][j] - '0';
                }
                if (i < m) {
                    V[i][j] = vertical[i][j] - '0';
                }
            }
        }
        
        A[0][0] = 0;
        for (int j=1; j<=n; ++j) {
            A[0][j] = A[0][j-1] + H[0][j-1];
        }
        for (int i=0; i<m; ++i) {
            A[i+1][0] = A[i][0] + V[i][0];
            for (int j=1; j<=n; ++j) {
                A[i+1][j] = max(A[i+1][j-1] + H[i+1][j-1], A[i][j] + V[i][j]);
            }
        }
        
        return A[m][n];
    }
};
