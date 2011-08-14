/*
ID: ivan.bu1
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>

using namespace std;
int X[150], Y[150];
double D[150][150];
vector<string> C;
double sqr(double x) {
    return x*x;
}
double dist(int i, int j) {
    return sqrt(sqr(X[i]-X[j]) + sqr(Y[i]-Y[j]));
}
const double INF = 1e32;
int main() {
	ifstream fin("cowtour.in");
    int n;
    fin >> n;
    for (int i=0; i<n; ++i) {
        fin >> X[i] >> Y[i];
    }
    copy(istream_iterator<string>(fin), istream_iterator<string>(), back_inserter(C));
    fin.close();
    
    for (int i=0; i<n; ++i) {
        C[i][i] = '1';
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            D[i][j] = (C[i][j]=='1' ? dist(i, j) : INF);
        }
    }
    
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    
    double orig = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (D[i][j] < 1e31) {
                orig = max(orig, D[i][j]);
            }
        }
    }
    double best = INF;
    for (int i=0; i<n; ++i) {
        double d = 0;
        for (int j=0; j<n; ++j) {
            if (D[i][j] < 1e31) {
                d = max(d, D[i][j]);
            }
        }
        for (int j=0; j<n; ++j) {
            if (D[i][j] > 1e31) {
                double dd = 0;
                for (int k=0; k<n; ++k) {
                    if (D[j][k] < 1e31) {
                        dd = max(dd, D[j][k]);
                    }
                }
                best = min(best, d + dd + dist(i, j));
            }
        }
    }
    
    char buff[20];
    sprintf(buff, "%.6f", max(orig, best));
    ofstream fout("cowtour.out");
    fout << buff << '\n';
    fout.close();

	return 0;
}
