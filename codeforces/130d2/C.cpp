#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

long long G[101][100][100];
long long A[100][101], B[100][101];
int n, m;
int main() {
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[1][a][b] = G[1][b][a] = 1;
    }
    
    for (int len=2; len<n; ++len) {
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                for (int k=0; k<n; ++k) {
                    if (G[1][i][k]) {
                        G[len][i][j] += G[len-1][k][j];
                    }
                }
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                G[len][j][i] = G[len][i][j];
            }
        }
    }
    
    for (int len=1; len<n; ++len) {
        for (int i=0; i<n; ++i) {
            A[i][len] = G[len][0][i];
            B[i][len] = G[len][i][n-1];
        }
    }
    
    int slen = n+1;
    for (int len=1; len<n; ++len) {
        if (G[len][0][n-1]) {
            slen = len;
            break;
        }
    }

    double sol = 1.0;
    long long numspaths = G[slen][0][n-1];
    for (int i=1; i<n-1; ++i) {
        for (int alen=1; alen<slen; ++alen) {
            sol = max(sol, 2.0*A[i][alen]/numspaths*B[i][slen-alen]);
        }
    }
    printf("%.12lf\n", sol);
    return 0;
}
