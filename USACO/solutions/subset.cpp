/*
ID: ivan.bu1
PROG: subset
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

long long ways[781];
int main() {
	ifstream fin("subset.in");
    int n;
    fin >> n;
    fin.close();
    
    int tot = n*(n+1)/2;
    if ((tot & 1) == 0) {
        ways[0] = 1;
        for (int i=1; i<=n; ++i) {
            for (int cur=tot/2; cur>=i; --cur) {
                ways[cur] += ways[cur-i];
            }
        }
    }
    ofstream fout("subset.out");
    fout << ways[tot/2]/2 << '\n';
    fout.close();

	return 0;
}
