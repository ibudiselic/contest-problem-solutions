/*
ID: ivan.bu1
PROG: numtri
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

int A[1000][1000];
int main() {
	ifstream fin("numtri.in");
    int n;
    fin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<=i; ++j) {
            fin >> A[i][j];
        }
    }
    fin.close();
    for (int i=1; i<n; ++i) {
        for (int j=0; j<=i; ++j) {
            A[i][j] += max(A[i-1][j], (j==0 ? 0 : A[i-1][j-1]));
        }
    }
    ofstream fout("numtri.out");
    fout << *max_element(A[n-1], A[n-1]+n) << '\n';
    fout.close();

	return 0;
}
