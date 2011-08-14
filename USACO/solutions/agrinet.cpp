/*
ID: ivan.bu1
PROG: agrinet
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
#include <cstdlib>
#include <queue>

using namespace std;

int G[100][100];

int p_[100];
void init() {
    memset(p_, 0xff, sizeof p_);
}
int root(int x) {
    if (p_[x] != -1) {
        return p_[x] = root(p_[x]);
    } else {
        return x;
    }
}
bool flip() {
    return (int)((rand()/(RAND_MAX+1.0))*2.0);
}
bool join(int x, int y) {
    int a = root(x);
    int b = root(y);
    if (a == b) {
        return false;
    }
    
    if (flip()) {
        p_[a] = b;
    } else {
        p_[b] = a;
    }
    return true;
}

struct S {
    int i, j, d;
    S(int i_, int j_, int d_): i(i_), j(j_), d(d_) {}
};
bool operator<(const S &a, const S &b) {
    if (a.d != b.d) {
        return a.d > b.d;
    } else if (a.i != b.i) {
        return a.i < b.i;
    } else {
        return a.j < b.j;
    }
}

int main() {
	ifstream fin("agrinet.in");
    int n;
    fin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            fin >> G[i][j];
        }
    }
    fin.close();
    
    priority_queue<S> PQ;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            PQ.push(S(i, j, G[i][j]));
        }
    }
    
    init();
    int sol = 0;
    while (n > 1) {
        S tmp = PQ.top();
        PQ.pop();
        if (join(tmp.i, tmp.j)) {
            sol += tmp.d;
            --n;
        }
    }

    ofstream fout("agrinet.out");
    fout << sol << '\n';
    fout.close();

	return 0;
}

