/*
ID: ivan.bu1
PROG: concom
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

int G[100][100];
bool C[100][100];
int main() {
	ifstream fin("concom.in");
    int n;
    fin >> n;
    for (int i=0; i<n; ++i) {
        int a, b, c;
        fin >> a >> b >> c;
        G[a-1][b-1] = c;
        C[a-1][b-1] = (c>50);
    }
    fin.close();
    for (int i=0; i<100; ++i) {
        C[i][i] = true;
    }
    
    while (true) {
        bool change = false;
        for (int i=0; i<100; ++i) {
            for (int j=0; j<100; ++j) {
                if (C[i][j]) {
                    continue;
                }
                int sum = 0;
                for (int k=0; k<100; ++k) {
                    if (C[i][k]) {
                        sum += G[k][j];
                    }
                }
                if (sum > 50) {
                    C[i][j] = true;
                    change = true;
                }
            }
        }
        if (!change) {
            break;
        }
    }
    ofstream fout("concom.out");
    for (int i=0; i<100; ++i) {
        for (int j=0; j<100; ++j) {
            if (i!=j && C[i][j]) {
                fout << i+1 << ' ' << j+1 << '\n';
            }
        }
    }
    fout.close();

	return 0;
}
