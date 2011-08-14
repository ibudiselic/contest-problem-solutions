/*
ID: ivan.bu1
PROG: rect1
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
#include <cassert>

using namespace std;

int llx[1001], lly[1001], urx[1001], ury[1001], color[1001];
int col_cnt[2500];
bool inside(int x, int y, int i) {
    return llx[i]<x && x<urx[i] && lly[i]<y && y<ury[i];
}
int main() {
	ifstream fin("rect1.in");
    int W, H, n;
    fin >> W >> H >> n;
    W *= 2;
    H *= 2;
    ++n;
    llx[0] = 0;
    lly[0] = 0;
    urx[0] = W;
    ury[0] = H;
    color[0] = 0;
    for (int i=1; i<n; ++i) {
        fin >> llx[i] >> lly[i] >> urx[i] >> ury[i] >> color[i];
        llx[i] *= 2;
        lly[i] *= 2;
        urx[i] *= 2;
        ury[i] *= 2;
        --color[i];
    }
    fin.close();
    
    vector<int> X, Y;
    for (int i=0; i<n; ++i) {
        X.push_back(llx[i]);
        X.push_back(urx[i]);
        Y.push_back(lly[i]);
        Y.push_back(ury[i]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
    
    for (int i=1; i<(int)X.size(); ++i) {
        int x1 = X[i-1];
        int x2 = X[i];
        for (int j=1; j<(int)Y.size(); ++j) {
            int y1 = Y[j-1];
            int y2 = Y[j];
            
            int col = -1;
            for (int k=n-1; k>=0; --k) {
                if (inside(x1+1, y1+1, k)) {
                    col = color[k];
                    break;
                }
            }
            assert(col != -1);
            col_cnt[col] += (x2-x1)*(y2-y1);
        }
    }

    ofstream fout("rect1.out");
    for (int i=0; i<2500; ++i) {
        if (col_cnt[i] > 0) {
            fout << i+1 << ' ' << col_cnt[i]/4 << '\n';
        }
    }
    fout.close();

	return 0;
}
