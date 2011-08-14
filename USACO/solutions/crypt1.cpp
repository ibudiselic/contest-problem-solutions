/*
ID: ivan.bu1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

bool have[10];
bool check_digs(int x) {
    int mod = 10;
    while (mod/10 <= x) {
        const int dig = x%mod/(mod/10);
        if (!have[dig]) {
            return false;
        }
        mod *= 10;
    }
    return true;
}
int main() {
	ifstream fin("crypt1.in");
    int n;
    fin >> n;
    vector<int> d(n, 0);
    for (int i=0; i<n; ++i) {
        fin >> d[i];
        have[d[i]] = true;
    }
    fin.close();
    
    int sol = 0;
    for (int i=0; i<n; ++i) {
        int first = 100*d[i];
        for (int j=0; j<n; ++j) {
            first += 10*d[j];
            for (int k=0; k<n; ++k) {
                first += d[k];
                for (int b=0; b<n; ++b) {
                    const int bb = d[b];
                    int res1 = bb * first;
                    if (res1<100 || res1>999 || !check_digs(res1)) {
                        continue;
                    }
                    for (int a=0; a<n; ++a) {
                        const int aa = d[a];
                        int res2 = aa * first;
                        if (res2<100 || res2>999 || !check_digs(res2)) {
                            continue;
                        }
                        int res = res1 + 10*res2;
                        if (res<1000 || res>9999 || !check_digs(res)) {
                            continue;
                        }
                        ++sol;
                    }
                }
                first -= d[k];
            }
            first -= 10*d[j];
        }
    }

    ofstream fout("crypt1.out");
    fout << sol << '\n';
    fout.close();
	return 0;
}
