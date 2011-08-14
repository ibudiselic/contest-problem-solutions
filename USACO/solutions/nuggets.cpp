/*
ID: ivan.bu1
PROG: nuggets
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

const int lim = 70000;
int num[10];
bool can_make[70000];
int main() {
    int n;
	ifstream fin("nuggets.in");
    fin >> n;
    for (int i=0; i<n; ++i) {
        fin >> num[i];
    }
    fin.close();
    
    sort(num, num+n);
    
    ofstream fout("nuggets.out");
    for (int i=0; i<n; ++i) {
        can_make[num[i]] = true;
    }
    for (int i=0; i<lim; ++i) {
        if (can_make[i]) {
            for (int j=0; j<n; ++j) {
                if (i + num[j] < lim) {
                    can_make[i + num[j]] = true;
                }
            }
        }
    }
    for (int i=lim-1; i>=0; --i) {
        if (!can_make[i]) {
            fout << (i>65000 ? 0 : i) << '\n';
            break;
        }
    }
    fout.close();

	return 0;
}
