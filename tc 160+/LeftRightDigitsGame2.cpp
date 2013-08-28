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

string D, L;
int n;
int take[51][51][51][2][2];
bool next_isgt[51][51][51][2][2];
bool next_mustgt[51][51][51][2][2];
string reconstruct(int at, int left, int right, bool isgt, bool mustgt) {
    string sol(n, ' ');
    for (int i=at; i<n && left!=0; ++i) {
        sol[i] = D[take[i][left][right][isgt][mustgt]];
        int nleft = take[i][left][right][isgt][mustgt];
        bool nisgt = next_isgt[i][left][right][isgt][mustgt];
        bool nmustgt = next_mustgt[i][left][right][isgt][mustgt];
        for (int j=left-1; j>nleft; --j) {
            sol[right--] = D[j];
        }
        left = nleft;
        isgt = nisgt;
        mustgt = nmustgt;
    }
    return sol;
}
int go(int at, int left, int right, bool isgt, bool mustgt) {
    int &ret = take[at][left][right][isgt][mustgt];
    if (ret != -1) {
        return ret;
    }
    if (left == 0) {
        if (mustgt) {
            ret = isgt ? -3 : -2;
        } else {
            ret = -3;
        }
    } else {
        assert(at < n);
        ret = -2;
        string best(n, 127);
        for (int d=(at==0); d<10; ++d) {
            if (ret != -2) {
                return ret;
            }
            if (!isgt && L[at]-'0'>d) {
                continue;
            }
            for (int pos=0; pos<left; ++pos) {
                if (D[pos]-'0' == d) {
                    bool nisgt = isgt || (L[at]-'0'<d);
                    bool nmustgt = mustgt;
                    if (!nisgt) {
                        for (int i=pos+1, j=(left-pos-1); i<left; ++i, --j) {
                            if (L[right-j+1] > D[i]) {
                                nmustgt = true;
                                break;
                            }
                            if (L[right-j+1] < D[i]) {
                                nmustgt = false;
                                break;
                            }
                        }
                    }
                    if (go(at+1, pos, right-(left-pos-1), nisgt, nmustgt) != -2) {
                        string cand = reconstruct(at+1, pos, right-(left-pos-1), nisgt, nmustgt);
                        for (int i=pos+1, j=(left-pos-1); i<left; ++i, --j) {
                            cand[right-j+1] = D[i];
                        }
                        if (cand < best) {
                            best = cand;
                            ret = pos;
                            next_isgt[at][left][right][isgt][mustgt] = nisgt;
                            next_mustgt[at][left][right][isgt][mustgt] = nmustgt;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

class LeftRightDigitsGame2 {
public:
    string minNumber(string digits, string lowerBound) {
        D = digits;
        L = lowerBound;
        n = D.size();
        memset(take, 0xff, sizeof take);
        if (go(0, n, n-1, 0, 0) == -2) {
            return string();
        }
        return reconstruct(0, n, n-1, 0, 0);
    }
};
