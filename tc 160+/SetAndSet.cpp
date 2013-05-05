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
#include <ctime>

using namespace std;

struct undo_t {
    int *p;
    int val;
    undo_t(int *p_): p(p_), val(*p) {}
    void operator()() const { *p = val; }
};
class UndoableUnionFind {
public:
    UndoableUnionFind(int n_): n(n_), ncomps(n) {
        for (int i=0; i<n; ++i) {
            P.push_back(i);
        }
    }
    int root(int x) {
        if (P[x] == x) {
            return x;
        } else {
            undo.push_back(undo_t(&P[x]));
            return (P[x] = root(P[x]));
        }
    }
    bool join(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (rand()&1) {
                undo.push_back(undo_t(&P[x]));
                P[x] = y;
            } else {
                undo.push_back(undo_t(&P[y]));
                P[y] = x;
            }
            undo.push_back(undo_t(&ncomps));
            --ncomps;
            return true;
        }
        return false;
    }
    int components_count() const {
        return ncomps;
    }
    int checkpoint() const {
        return undo.size();
    }
    void rewind(int undo_token) {
        while ((int)undo.size() > undo_token) {
            undo.back()();
            undo.pop_back();
        }
    }
private:
    int n;
    int ncomps;
    vector<int> P;
    vector<undo_t> undo;
};

const int MAXBITS = 20;
int bc[1<<MAXBITS];
vector< vector<int> > zeros;
int n;
long long calc(int b, int diffmask, UndoableUnionFind &UF) {
    if (b == MAXBITS) {
        return ((bc[diffmask]&1) ? -1 : +1) * (1ll<<UF.components_count());
    }
    
    int zcnt = zeros[b].size();
    long long ret = calc(b+1, diffmask, UF);
    if (zcnt==0 || zcnt==n) {
        return ret;
    }
    int undo_token = UF.checkpoint();
    for (int i=1; i<zcnt; ++i) {
        UF.join(zeros[b][i-1], zeros[b][i]);
    }
    ret += calc(b+1, diffmask|(1<<b), UF);
    UF.rewind(undo_token);
    return ret;
}
class SetAndSet {
public:
    long long countandset(vector <int> A) {
        n = A.size();
        zeros.assign(MAXBITS, vector<int>());
        for (int i=0; i<(int)A.size(); ++i) {
            for (int j=0; j<MAXBITS; ++j) {
                if (!(A[i] & (1<<j))) {
                    zeros[j].push_back(i);
                }
            }
        }
        for (int diffmask=1; diffmask<(1<<MAXBITS); ++diffmask) {
            bc[diffmask] = bc[diffmask>>1] + (diffmask&1);
        }
        UndoableUnionFind UF(n);
        long long sol = calc(0, 0, UF);
        return sol==(1ll<<n) ? sol-2 : sol;
    }
};
