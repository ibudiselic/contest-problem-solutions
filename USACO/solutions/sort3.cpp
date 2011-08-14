/*
ID: ivan.bu1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cassert>

using namespace std;

int main() {
    int n;
	ifstream fin("sort3.in");
    fin >> n;
    vector<int> v(n, 0);
    for (int i=0; i<n; ++i) {
        fin >> v[i];
    }
    fin.close();
    
    vector<int> t = v;
    sort(t.begin(), t.end());
    int a[4][4] = {0};
    for (int i=0; i<n; ++i) {
        ++a[v[i]][t[i]];
    }
    int sol = 0;
    int rem = 0;
    for (int i=1; i<4; ++i) {
        for (int j=i+1; j<4; ++j) {
            int direct = min(a[i][j], a[j][i]);
            a[i][j] -= direct;
            a[j][i] -= direct;
            rem += a[i][j] + a[j][i];
            sol += direct;
        }
    }
    assert(rem%3 == 0);
    ofstream fout("sort3.out");
    fout << sol + 2*rem/3 << '\n';
    fout.close();

	return 0;
}
