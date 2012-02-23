/*
ID: ivan.bu1
PROG: job
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

int A_avail[30], A_len[30], B_avail[30], B_len[30];
int A, B;
int Ta[1000], Tb[1000];

void calc(int n, int A, int *avail, int *len, int *T) {
    for (int t=0; t<n; ++t) {
        int best = 0;
        for (int i=1; i<A; ++i) {
            if (avail[i]+len[i] < avail[best]+len[best]) {
                best = i;
            }
        }
        T[t] = avail[best] + len[best];
        avail[best] += len[best];
    }
}
int main() {
	ifstream fin("job.in");
    int n;
    fin >> n;
    fin >> A >> B;
    for (int i=0; i<A; ++i) {
        fin >> A_len[i];
    }
    for (int i=0; i<B; ++i) {
        fin >> B_len[i];
    }
    fin.close();
    
    calc(n, A, A_avail, A_len, Ta);
    calc(n, B, B_avail, B_len, Tb);
    
    int sol = Ta[0] + Tb[n-1];
    for (int i=1; i<n; ++i) {
        sol = max(sol, Ta[i] + Tb[n-1-i]);
    }

    ofstream fout("job.out");
    fout << Ta[n-1] << ' ' << sol << '\n';
    fout.close();

	return 0;
}
