/*
ID: ivan.bu1
PROG: rockers
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

int T[20];
int max_songs[21][21][21];
int main() {
    int n, dur, disks;
	ifstream fin("rockers.in");
    fin >> n >> dur >> disks;
    copy(istream_iterator<int>(fin), istream_iterator<int>(), T);
    fin.close();

    for (int i=1; i<=disks; ++i) {
        for (int s=1; s<=n; ++s) {
            max_songs[i][0][s] = max_songs[i-1][dur][s];
        }
        for (int t=1; t<=dur; ++t) {
            for (int s=1; s<=n; ++s) {
                max_songs[i][t][s] = max(max_songs[i][t-1][s], max_songs[i][t][s-1]);
                if (T[s-1] <= t) {
                    max_songs[i][t][s] = max(max_songs[i][t][s], 1 + max_songs[i][t-T[s-1]][s-1]);
                }
            }
        }
    }

    ofstream fout("rockers.out");
    fout << max_songs[disks][dur][n] << '\n';
    fout.close();

	return 0;
}
