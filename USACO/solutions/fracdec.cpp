/*
ID: ivan.bu1
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int ind[100001];
int main() {
	ifstream fin("fracdec.in");
    int n, d;
    fin >> n >> d;
    fin.close();
    
    int whole = n/d;
    n -= whole * d;
    memset(ind, 0xff, sizeof ind);
    string decimal;
    while (n>0 && ind[n]==-1) {
        ind[n] = decimal.size();
        n *= 10;
        int dig = n/d;
        decimal += char(dig + '0');
        n -= dig * d;
    }
    if (ind[n] != -1) {
        decimal = decimal.substr(0, ind[n]) + '(' + decimal.substr(ind[n]) + ')';
    }
    if (decimal.size() == 0) {
        decimal = "0";
    }
    ostringstream os;
    os << whole << '.' << decimal;
    decimal = os.str();
    
    int i = 0;
    ofstream fout("fracdec.out");
    while (i < (int)decimal.size()) {
        fout << decimal.substr(i, 76) << '\n';
        i += 76;
    }
    fout.close();

	return 0;
}

