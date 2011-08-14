/*
ID: ivan.bu1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <set>
#include <cstring>

using namespace std;

bool done[21][21][21];
int A, B, C;
int SZ[3];
set<int> sol;
void go(int *state) {
    done[state[0]][state[1]][state[2]] = 1;
    if (state[0] == 0) {
        sol.insert(state[2]);
    }
    int next[3];
    
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            if (i != j) {
                memcpy(next, state, sizeof next);
                if (next[i]==0 || next[j]==SZ[j]) {
                    continue;
                }
                const int change = min(next[i], SZ[j]-next[j]);
                next[i] -= change;
                next[j] += change;
                if (!done[next[0]][next[1]][next[2]]) {
                    go(next);
                }
            }
        }
    }
}
int main() {
	ifstream fin("milk3.in");
    fin >> A >> B >> C;
    fin.close();
    SZ[0] = A;
    SZ[1] = B;
    SZ[2] = C;
    int state[3];
    state[0] = 0;
    state[1] = 0;
    state[2] = C;
    go(state);
    ofstream fout("milk3.out");
    for (set<int>::const_iterator it=sol.begin(); it!=sol.end(); ++it) {
        fout << (it==sol.begin() ? "" : " ") << *it;
    }
    fout << '\n';
    fout.close();

	return 0;
}
