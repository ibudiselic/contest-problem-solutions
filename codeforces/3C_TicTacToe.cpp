#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

inline int illegal() {
    cout << "illegal\n";
    return 0;
}
inline int first() {
    cout << "first\n";
    return 0;
}
inline int second() {
    cout << "second\n";
    return 0;
}
inline int draw() {
    cout << "draw\n";
    return 0;
}
inline int fwin() {
    cout << "the first player won\n";
    return 0;
}
inline int swin() {
    cout << "the second player won\n";
    return 0;
}
string A[3];
bool is_win(char c) {
    for (int i=0; i<3; ++i) {
        bool ok = true;
        for (int j=0; j<3; ++j) {
            if (A[i][j] != c) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    }
    for (int j=0; j<3; ++j) {
        bool ok = true;
        for (int i=0; i<3; ++i) {
            if (A[i][j] != c) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    }
    int i = 0;
    int j = 0;
    int di = 1;
    int dj = 1;
    int k = 0;
    bool ok = true;
    while (k < 3) {
        if (A[i][j] != c) {
            ok = false;
            break;
        }
        i += di;
        j += dj;
        ++k;
    }
    if (ok) {
        return true;
    }
    dj = -1;
    i = 0;
    j = 2;
    k = 0;
    ok = true;
    while (k < 3) {
        if (A[i][j] != c) {
            ok = false;
            break;
        }
        i += di;
        j += dj;
        ++k;
    }
    return ok;
}
int main() {
    for (int i=0; i<3; ++i) {
        cin >> A[i];
    }
    int x = 0, o = 0;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            if (A[i][j] == 'X') {
                ++x;
            } else if (A[i][j] == '0') {
                ++o;
            }
        }
    }
    if (!(x==o || x==o+1)) {
        return illegal();
    }
    
    bool xwin = x>=3 && is_win('X');
    bool owin = o>=3 && is_win('0');
    
    if (xwin && x==o || owin && x==o+1 || xwin && owin) {
        return illegal();
    }
    
    if (xwin) {
        return fwin();
    }
    if (owin) {
        return swin();
    }
    if (x+o == 9) {
        return draw();
    }

    return x==o ? first() : second();
}
