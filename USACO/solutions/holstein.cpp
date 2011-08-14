/*
ID: ivan.bu1
PROG: holstein
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

int A, B;
int V[25];
int C[15][25];
vector<int> sol;
vector<int> cur;
int v[25];
void go(int p) {
    if (cur.size() >= sol.size()) {
        return;
    }
    if (p == B) {
        bool ok = true;
        for (int i=0; i<A; ++i) {
            if (v[i] < V[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (cur.size()<sol.size() || cur<sol) {
                sol = cur;
            }
        }
        return;
    }
    for (int i=0; i<A; ++i) {
        v[i] += C[p][i];
    }
    cur.push_back(p);
    go(p+1);
    cur.pop_back();
    for (int i=0; i<A; ++i) {
        v[i] -= C[p][i];
    }
    go(p+1);
}
int main() {
	ifstream fin("holstein.in");
    fin >> A;
    for (int i=0; i<A; ++i) {
        fin >> V[i];
    }
    fin >> B;
    for (int i=0; i<B; ++i) {
        for (int j=0; j<A; ++j) {
            fin >> C[i][j];
        }
    }
    fin.close();
    
    sol.assign(B+1, 123456789);
    go(0);

    ofstream fout("holstein.out");
    fout << sol.size();
    for (int i=0; i<(int)sol.size(); ++i) {
        fout << ' ' << sol[i] + 1;
    }
    fout << '\n';
    fout.close();

	return 0;
}
