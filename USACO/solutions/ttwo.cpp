/*
ID: ivan.bu1
PROG: ttwo
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

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
struct S {
    int ai, aj, bi, bj, da, db;
};
vector<string> G;
bool done[10][10][10][10][4][4];
int main() {
	ifstream fin("ttwo.in");
    copy(istream_iterator<string>(fin), istream_iterator<string>(), back_inserter(G));
    fin.close();

    S s;
    s.da = 0;
    s.db = 0;
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            if (G[i][j] == 'F') {
                s.ai = i;
                s.aj = j;
            } else if (G[i][j] == 'C') {
                s.bi = i;
                s.bj = j;
            }
        }
    }
    int sol = 0;
    ofstream fout("ttwo.out");
    while (!done[s.ai][s.aj][s.bi][s.bj][s.da][s.db]) {
        done[s.ai][s.aj][s.bi][s.bj][s.da][s.db] = 1;
        ++sol;
        
        int r = s.ai + di[s.da];
        int c = s.aj + dj[s.da];
        if (r<0 || c<0 || r>=10 || c>=10 || G[r][c]=='*') {
            if (++s.da == 4) {
                s.da = 0;
            }
        } else {
            s.ai = r;
            s.aj = c;
        }

        r = s.bi + di[s.db];
        c = s.bj + dj[s.db];
        if (r<0 || c<0 || r>=10 || c>=10 || G[r][c]=='*') {
            if (++s.db == 4) {
                s.db = 0;
            }
        } else {
            s.bi = r;
            s.bj = c;
        }
        if (s.ai==s.bi && s.aj==s.bj) {
            fout << sol << '\n';
            fout.close();
            return 0;
        }
    }

    fout << 0 << '\n';
    fout.close();

	return 0;
}
