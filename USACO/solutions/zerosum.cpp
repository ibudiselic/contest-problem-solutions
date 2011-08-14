/*
ID: ivan.bu1
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

string cur;
int n;
void output(ofstream &fout) {
    fout << 1;
    for (int i=2; i<=n; ++i) {
        fout << cur[i-2] << i;
    }
    fout << '\n';
}
void go(int d, int num, int sum, int sgn, ofstream &fout) {
    if (d > n) {
        sum += sgn*num;
        if (sum == 0) {
            output(fout);
        }
        return;
    }
    cur[d-2] = ' ';
    go(d+1, num*10+d, sum, sgn, fout);
    sum += sgn*num;
    cur[d-2] = '+';
    go(d+1, d, sum, +1, fout);
    cur[d-2] = '-';
    go(d+1, d, sum, -1, fout);
}

int main() {
	ifstream fin("zerosum.in");
    fin >> n;
    fin.close();

    cur = string(n-1, ' ');
    ofstream fout("zerosum.out");
    go(2, 1, 0, +1, fout);
    fout.close();

	return 0;
}

