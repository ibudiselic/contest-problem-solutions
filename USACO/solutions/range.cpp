/*
ID: ivan.bu1
PROG: range
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

using namespace std;

int F[250][250];
int up[250][250], left_[250][250], sz[250][250];
int cnt[251];
int main() {
	ifstream fin("range.in");
    int n;
    fin >> n;
    char c;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            fin >> c;
            F[i][j] = c-'0';
        }
    }
    fin.close();
    
    for (int i=0; i<n; ++i) {
        up[0][i] = F[0][i];
        left_[i][0] = F[i][0];
    }
    for (int i=1; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            up[i][j] = (F[i][j] ? up[i-1][j]+1 : 0);
        }
    }
    for (int i=0; i<n; ++i) {
        for (int j=1; j<n; ++j) {
            left_[i][j] = (F[i][j] ? left_[i][j-1]+1 : 0);       
        }
    }
    
    for (int i=0; i<n; ++i) {
        sz[i][0] = F[i][0];
        sz[0][i] = F[0][i];
    }

    for (int i=1; i<n; ++i) {
        for (int j=1; j<n; ++j) {
            sz[i][j] = min(sz[i-1][j-1] + 1, min(up[i][j], left_[i][j]));
            for (int k=2; k<=sz[i][j]; ++k) {
                ++cnt[k];
            }
        }
    }

    ofstream fout("range.out");
    for (int i=2; i<=n; ++i) {
        if (cnt[i]) {
            fout << i << ' ' << cnt[i] << '\n';
        }
    }
    fout.close();

	return 0;
}
