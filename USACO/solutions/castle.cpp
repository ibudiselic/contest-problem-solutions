/*
ID: ivan.bu1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <queue>
#include <utility>
#include <cassert>
#include <cstring>

using namespace std;

int m, n;
int C[50][50];
bool valid(int i, int j) {
    return i>=0 && j>=0 && i<m && j<n;
}

int A[50][50];
int SZ[2501];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const int N = 2;
const int E = 4;
const int S = 8;
const int W = 1;
const int mask[] = { 2, 4, 8, 1 };

int get_size(int i, int j, int color) {
    C[i][j] = color;
    queue< pair<int, int> > Q;
    Q.push(make_pair(i, j));
    int sz = 0;
    while (!Q.empty()) {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        ++sz;
        
        for (int d=0; d<4; ++d) {
            const int r = i + di[d];
            const int c = j + dj[d];
            if (valid(r, c) && C[r][c]==-1 && !(A[i][j]&mask[d])) {
                C[r][c] = color;
                Q.push(make_pair(r, c));
            }
        }
    }
    SZ[color] = sz;
    return sz;
}
pair<int, int> go() {
    int cnt = 0;
    int largest = 0;
    memset(C, 0xff, sizeof C);
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (C[i][j] == -1) {
                largest = max(largest, get_size(i, j, cnt++));
            }
        }
    }
    
    return make_pair(cnt, largest);
}
int main() {
	ifstream fin("castle.in");
    fin >> n >> m;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            fin >> A[i][j];
        }
    }
    fin.close();
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            cerr << A[i][j] << ' ';
        }
        cerr << '\n';
    }
    
    pair<int, int> t = go();
    int cnt = t.first;
    int largest = t.second;
    ofstream fout("castle.out");
    fout << cnt << '\n' << largest << '\n';
    
    int besti=0, bestj=0;
    char bestdir=0;
    for (int j=0; j<n; ++j) {
        for (int i=m-1; i>=0; --i) {
            if (i>0 && (A[i][j]&N) && C[i][j]!=C[i-1][j]) {
                assert(A[i-1][j] & S);
                t.second = SZ[C[i][j]] + SZ[C[i-1][j]];
                if (t.second > largest) {
                    largest = t.second;
                    besti = i;
                    bestj = j;
                    bestdir = 'N';
                }
            }
            if (j<n-1 && (A[i][j]&E) && C[i][j]!=C[i][j+1]) {
                assert(A[i][j+1] & W);
                t.second = SZ[C[i][j]] + SZ[C[i][j+1]];
                if (t.second > largest) {
                    largest = t.second;
                    besti = i;
                    bestj = j;
                    bestdir = 'E';
                }
            }
        }
    }
    
    fout << largest << '\n' << besti+1 << ' ' << bestj+1 << ' ' << bestdir << '\n';
    fout.close();

	return 0;
}
