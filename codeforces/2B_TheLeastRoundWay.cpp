#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

char T[1000][1000];
char F[1000][1000];
int c2[1000][1000], c5[1000][1000];
int i0 = -1, j0 = -1;
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            int x;
            cin >> x;
            if (x == 0) {
                if (i0==-1 || i0<i) {
                    i0 = i;
                    j0 = j;
                }
            } else {
                while (x%2 == 0) {
                    ++T[i][j];
                    x /= 2;
                }
                while (x%5 == 0) {
                    ++F[i][j];
                    x /= 5;
                }
            }
        }
    }
    
    c2[0][0] = T[0][0];
    for (int j=1; j<n; ++j) {
        c2[0][j] = c2[0][j-1] + T[0][j];
    }
    for (int i=1; i<n; ++i) {
        c2[i][0] = c2[i-1][0] + T[i][0];
        for (int j=1; j<n; ++j) {
            c2[i][j] = min(c2[i][j-1], c2[i-1][j]) + T[i][j];
        }
    }

    c5[0][0] = F[0][0];
    for (int j=1; j<n; ++j) {
        c5[0][j] = c5[0][j-1] + F[0][j];
    }
    for (int i=1; i<n; ++i) {
        c5[i][0] = c5[i-1][0] + F[i][0];
        for (int j=1; j<n; ++j) {
            c5[i][j] = min(c5[i][j-1], c5[i-1][j]) + F[i][j];
        }
    }
    
    if (i0>-1 && min(c2[n-1][n-1], c5[n-1][n-1])>1) {
        cout << 1 << '\n';
        cout << string(i0, 'D') << string(j0, 'R') << string(n-i0-1, 'D') << string(n-j0-1, 'R') << '\n';
    } else if (c2[n-1][n-1] <= c5[n-1][n-1]) {
        int i = n-1;
        int j = n-1;
        string sol;
        while (i>0 || j>0) {
            if (j==0 || i>0 && c2[i-1][j]<c2[i][j-1]) {
                --i;
                sol += 'D';
            } else {
                --j;
                sol += 'R';
            }
        }
        reverse(sol.begin(), sol.end());
        cout << c2[n-1][n-1] << '\n' << sol << '\n';
    } else {
        int i = n-1;
        int j = n-1;
        string sol;
        while (i>0 || j>0) {
            if (j==0 || i>0 && c5[i-1][j]<c5[i][j-1]) {
                --i;
                sol += 'D';
            } else {
                --j;
                sol += 'R';
            }
        }
        reverse(sol.begin(), sol.end());
        cout << c5[n-1][n-1] << '\n' << sol << '\n';
    }

    return 0;
}
