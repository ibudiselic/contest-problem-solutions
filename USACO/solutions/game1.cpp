/*
ID: ivan.bu1
PROG: game1
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

int n;
int V[100];
int dp[101][101];
int S[101];
int sum(int l, int r) {
    return S[r+1] - S[l];
}
int go(int l, int r) {
    int &ret = dp[l][r];
    if (ret != -1) {
        return ret;
    }
    if (l > r) {
        ret = 0;
    } else if (l == r) {
        ret = V[l];
    } else {
        ret = max(V[l] + sum(l+1, r) - go(l+1, r), 
                  V[r] + sum(l, r-1) - go(l, r-1));
    }
    return ret;
}
int main() {
	ifstream fin("game1.in");
    fin >> n;
    for (int i=0; i<n; ++i) {
        fin >> V[i];
    }
    fin.close();
    
    S[0] = 0;
    for (int i=0; i<n; ++i) {
        S[i+1] = S[i] + V[i];
    }

    memset(dp, 0xff, sizeof dp);
    int p1 = go(0, n-1);
    ofstream fout("game1.out");
    fout << p1 << ' ' << S[n]-p1 << '\n';
    fout.close();

	return 0;
}
