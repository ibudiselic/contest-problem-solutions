/*
ID: ivan.bu1
PROG: fact4
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

const long long mod = 1000000000;
int main() {
    int n;
	ifstream fin("fact4.in");
    fin >> n;
    fin.close();

    long long d = 1;
    for (int i=0; i<n; ++i) {
        d *= i+1;
        while (d%10 == 0) {
            d /= 10;
        }
        d %= mod;
    }
    ofstream fout("fact4.out");
    fout << d%10 << '\n';
    fout.close();

	return 0;
}
