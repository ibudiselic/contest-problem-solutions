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

const int mod = 1000000007;
int cnt[51][51];
int crossBcnt[51][51];
bool eq(int i, int j, const string &a, int l, int r, const string &b) {
    if (j-i != r-l) {
        return false;
    }
    for (int k=0; k<j-i; ++k) {
        if (a[i+k] != b[l+k]) {
            return false;
        }
    }
    return true;
}
int nmatch(const string &b, const string &F) {
    int len = F.size();
    int c = 0;
    for (int i=0; i+len<=(int)b.size(); ++i) {
        if (eq(i, i+len, b, 0, len, F)) {
            ++c;
        }
    }
    return c;
}

inline bool ew(const string &a, const string &b) {
    if (a.size() < b.size()) {
        return false;
    } else {
        return a.substr(a.size()-b.size()) == b;
    }
}
inline bool sw(const string &a, const string &b) {
    if (a.size() < b.size()) {
        return false;
    } else {
        return a.substr(0, b.size()) == b;
    }
}
int getpref(const string &a, const string &b) {
    int len = b.size();
    for (int i=len-1; i>0; --i) {
        if (ew(a, b.substr(0, i))) {
            return i;
        }
    }
    return 0;
}
int getsuf(const string &a, const string &b) {
    int len = b.size();
    for (int i=len-1; i>0; --i) {
        if (sw(a, b.substr(b.size()-i))) {
            return i;
        }
    }
    return 0;
}
int crosscnt(int pref, int suf, const string &a, const string &b) {
    int ret = 0;
    for (int i=0; i<pref; ++i) {
        int j = i + (int)b.size();
        if (j<=(int)a.size() && j+suf>(int)a.size() && eq(i, j, a, 0, j-i, b)) {
            ++ret;
        }
    }
    return ret;
}
int Lsuf[51];
int Rpref[51];
class AkariDaisukiDiv1 {
public:
    int countF(string A, string B, string C, string S, string F, int k) {
        int len = F.size();
        memset(crossBcnt, 0, sizeof crossBcnt);
        for (int pref=0; pref<len; ++pref) {
            string a = F.substr(0, pref);
            for (int suf=0; suf<len; ++suf) {
                string b = a + (suf>0 ? F.substr(len-suf) : string());
                cnt[pref][suf] = nmatch(b, F);
                if (pref && suf) {
                    crossBcnt[pref][suf] = crosscnt(pref, suf, a+B+F.substr(len-suf), F);
                }
            }
        }
        
        int Apref = getpref(A, F);
        int Bsuf = getsuf(B, F);
        int Bpref = getpref(B, F);
        int Csuf = getsuf(C, F);
        int Acnt = nmatch(A, F);
        int Bcnt = nmatch(B, F);
        int Ccnt = nmatch(C, F);
        
        for (int i=0; i<len; ++i) {
            Lsuf[i] = getsuf(A + (i>0 ? F.substr(F.size()-i) : string()), F);
            Rpref[i] = getpref(F.substr(0, i) + C, F);
        }
        
        while (k>0 && S.size()<=2*F.size()) {
            S = A + S + B + S + C;
            --k;
        }
        
        int sol = nmatch(S, F);
        int xsuf = getsuf(S, F);
        int xpref = getpref(S, F);
        while (k-- > 0) {
            sol += sol;
            if (sol >= mod) {
                sol -= mod;
            }
            sol += cnt[Apref][xsuf] + cnt[xpref][Bsuf] + crossBcnt[xpref][xsuf] + cnt[Bpref][xsuf] + cnt[xpref][Csuf] + Acnt + Bcnt + Ccnt;
            sol %= mod;
            xsuf = Lsuf[xsuf];
            xpref = Rpref[xpref];
        }
        
        return sol;
    }
};
