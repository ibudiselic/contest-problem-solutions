/*
ID: ivan.bu1
PROG: fence9
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

long long cross(long long x, long long y, long long xp, long long yp) {
    return x*yp - y*xp;
}
int calc(int x, int y, int xp, bool on_line) {
    int lo = 0;
    int hi = y;
    while (lo < hi) {
        int yp = lo + (hi-lo+1)/2;
        long long t = cross(x, y, xp, yp);
        if (!on_line && t<0 || on_line && t<=0) {
            lo = yp;
        } else {
            hi = yp - 1;
        }
    }
    return lo;
}
int calc(int x, int y, bool on_line=false) {
    int ret = 0;
    for (int i=1; i<x; ++i) {
        ret += calc(x, y, i, on_line);
    }
    return ret;
}
int main() {
    int n, m, p;
	ifstream fin("fence9.in");
    fin >> n >> m >> p;
    fin.close();
    
    int sol = 0;
    if (n > 0) {
        sol += calc(n, m);
    }
    if (p < n) {
        sol -= calc(n-p, m, true);
    } else if (p > n) {
        sol += calc(p-n, m) + (n>0)*(m - 1);
    }
    
    ofstream fout("fence9.out");
    fout << sol << '\n';
    fout.close();

	return 0;
}
