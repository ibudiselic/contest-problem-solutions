/*
ID: ivan.bu1
PROG: comehome
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

int G[52][52];
int to_int(char c) {
    if (c <= 'Z') {
        return c-'A';
    } else {
        return c-'a'+26;
    }
}
const int INF = 987654321;
int main() {
    for (int i=0; i<52; ++i) {
        for (int j=0; j<52; ++j) {
            G[i][j] = INF;
        }
    }
	ifstream fin("comehome.in");
    int n;
    fin >> n;
    for (int i=0; i<n; ++i) {
        char a, b;
        int x;
        fin >> a >> b >> x;
        int aa = to_int(a);
        int bb = to_int(b);
        G[aa][bb] = min(G[aa][bb], x);
        G[bb][aa] = min(G[bb][aa], x);
    }
    fin.close();

    for (int i=0; i<52; ++i) {
        G[i][i] = 0;
    }
    for (int k=0; k<52; ++k) {
        for (int i=0; i<52; ++i) {
            for (int j=0; j<52; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    int besti = -1;
    int sol = INF;
    for (int i=0; i<25; ++i) {
        if (G[i][25] < sol) {
            besti = i;
            sol = G[i][25];
        }
    }

    ofstream fout("comehome.out");
    fout << char('A'+besti) << ' ' << sol << '\n';
    fout.close();

	return 0;
}
