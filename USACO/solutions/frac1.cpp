/*
ID: ivan.bu1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <set>

using namespace std;

int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
struct frac {
    int n, d;
    frac(int n_, int d_): n(n_), d(d_) { const int g = gcd(n, d); n /= g; d /= g; }
};
bool operator<(const frac &a, const frac &b) {
    return a.n*b.d < a.d*b.n;
}
int main() {
    int n;
	ifstream fin("frac1.in");
    fin >> n;
    fin.close();
    
    set<frac> S;
    for (int j=1; j<=n; ++j) {
        for (int i=0; i<=j; ++i) {
            S.insert(frac(i, j));
        }
    }
    ofstream fout("frac1.out");
    for (set<frac>::const_iterator it=S.begin(); it!=S.end(); ++it) {
        fout << it->n << '/' << it->d << '\n';
    }
    fout.close();

	return 0;
}
