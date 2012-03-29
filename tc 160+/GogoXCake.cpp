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

int A, B;
bool doit(int i, int j, vector<string> &cake, const vector<string> &cutter, int m, int n, int r, int c) {
    if (i+r-A>m || j+c-B>n || B>j) {
        return false;
    }
    for (int a=A; a<r; ++a) {
        for (int b=0; b<c; ++b) {
            if (cutter[a][b] == '.') {
                if (cake[i+a-A][j+b-B] == 'X') {
                    return false;
                }
                cake[i+a-A][j+b-B] = 'X';
            }
        }
    }
    return true;
}
class GogoXCake {
public:
    string solve(vector <string> cake, vector <string> cutter) {
        int m = cake.size();
        int n = cake[0].size();
        int r = cutter.size();
        int c = cutter[0].size();
        for (int a=0; a<r; ++a) {
            for (int b=0; b<c; ++b) {
                if (cutter[a][b] == '.') {
                    A = a;
                    B = b;
                    goto DONE;
                }
            }
        }
        DONE:;
             
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (cake[i][j] == '.') {
                    if (!doit(i, j, cake, cutter, m, n, r, c)) {
                        return "NO";
                    }
                }
            }
        }
        return "YES";
    }
};
