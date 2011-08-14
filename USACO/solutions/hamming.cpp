/*
ID: ivan.bu1
PROG: hamming
LANG: C++
*/
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

int bc[1<<8];
int main() {
	ifstream fin("hamming.in");
    int n, b, d;
    fin >> n >> b >> d;
    fin.close();
    vector<int> v(1, 0);
    int lim = 1<<b;
    bc[0] = 0;
    for (int i=1; i<lim; ++i) {
        bc[i] = bc[i>>1] + (i&1);
    }
    
    while (v.size() < n) {
        int x = v.back() + 1;
        bool got_one = false;
        while (x < lim) {
            bool ok = true;
            for (int i=0; i<(int)v.size(); ++i) {
                int t = v[i]^x;
                if (bc[t] < d) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                v.push_back(x);
                got_one = true;
                break;
            }
            ++x;
        }
        assert(got_one);
    }
    
    ofstream fout("hamming.out");
    int i = 0;
    while (i < (int)v.size()) {
        for (int j=0; j<10 && i+j<(int)v.size(); ++j) {
            if (j > 0) {
                fout << ' ';
            }
            fout << v[i+j];
        }
        fout << '\n';
        i += 10;
    }
    fout.close();

	return 0;
}
