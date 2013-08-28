#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

char base[32][64];
void go(char c) {
    char other = c=='A' ? 'B' : 'A';
    bool change = false;
    for (int y=0; y<32; ++y) {
        for (int x=0; x<64; ++x) {
            if (base[y][x] == '.') {
                if (x>0 && y>0 && base[y-1][x-1]==other && (x<2 || base[y][x-2]=='.')) {
                    base[y][x] = c;
                    change = true;
                }
                if (x>1 && base[y][x-2]==other && (x<1 || y<1 || base[y-1][x-1]=='.')) {
                    base[y][x] = c;
                    change = true;
                }
            }
        }
    }
    if (change) {
        go(other);
    }
}

bool pattern[8][16];
char get(long long r, long long c, long long t) {
    if (r+c > 2*(t-1)) {
        return '.';
    }
    if (r>=32 || c>=64) {
        long long side = 4;
        while (r/side>=8 || c/side>=16) {
            side *= 8;
        }
        while (side > 4) {
            if (!pattern[r/side][c/side]) {
                return '.';
            }
            c = (c+((r/side)&1)*side)%(side*2);
            r %= side;
            side /= 8;
        }
    }
    return base[r%32][c%64];
}
class CheckerExpansion {
public:
    vector <string> resultAfter(long long t, long long c0, long long r0, int w, int h) {
        memset(base, '.', sizeof base);
        base[0][0] = 'A';
        go('B');
        for (int i=0; i<8; ++i) {
            for (int j=0; j<16; ++j) {
                for (int r=i*4; r<(i+1)*4; ++r) {
                    for (int c=j*4; c<(j+1)*4; ++c) {
                        if (base[r][c] != '.') {
                            pattern[i][j] = true;
                            goto SKIP;
                        }
                    }
                }
                SKIP:;
            }
        }

        vector<string> sol(h, string(w, '.'));
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                sol[i][j] = get(r0+h-1-i, c0+j, t);
            }
        }

        return sol;
    }
};
