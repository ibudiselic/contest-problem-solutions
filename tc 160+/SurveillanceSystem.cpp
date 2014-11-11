//# intervals, simulation, surveillance, implementation
//# => For every position, see if it can be covered and if it can be not covered by brute force. This uniquely determines the answer string.
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool no_surv(string &C, int x, vector<int> &reports, int L) {
    map<int, int> cnts;
    for (int i=L-1; i<x; ++i) {
        int c = 0;
        for (int j=i-L+1; j<=i; ++j) {
            c += (C[j]=='X');
        }
        ++cnts[c];
    }
    for (int i=x+L; i<(int)C.size(); ++i) {
        int c = 0;
        for (int j=i-L+1; j<=i; ++j) {
            c += (C[j]=='X');
        }
        ++cnts[c];
    }
    for (int i=0; i<(int)reports.size(); ++i) {
        if (--cnts[reports[i]] < 0) {
            return false;
        }
    }
    return true;
}
bool yes_surv(string &C, int x, map<int, int> &cnts, int L) {
    map<int, int> cnts2;
    for (int i=0; i+L<=(int)C.size(); ++i) {
        if (i == x) continue;
        int c = 0;
        for (int j=0; j<L; ++j) {
            c += (C[i+j]=='X');
        }
        ++cnts2[c];
    }
    for (auto &p : cnts) {
        if (p.second > cnts2[p.first]) {
            return false;
        }
    }
    return true;
}
bool yes_surv(string &C, int x, vector<int> &reports, int L) {
    map<int, int> cnts;
    for (int i=0; i<(int)reports.size(); ++i) {
        ++cnts[reports[i]];
    }
    for (int i=max(0, x-L+1); i<=x && i+L<=(int)C.size(); ++i) {
        int c = 0;
        for (int j=i; j<i+L; ++j) {
            c += (C[j]=='X');
        }
        if (cnts[c] > 0) {
            --cnts[c];
            if (yes_surv(C, i, cnts, L)) {
                return true;
            }
            ++cnts[c];
        }
    }
    return false;
}
class SurveillanceSystem {
public:
    string getContainerInfo(string C, vector <int> reports, int L) {
        string sol(C.size(), '-');
        for (int i=0; i<(int)sol.size(); ++i) {
            bool no = no_surv(C, i, reports, L);
            bool yes = yes_surv(C, i, reports, L);
            if (no && yes) {
                sol[i] = '?';
            } else if (yes) {
                sol[i] = '+';
            } else {
                assert(no);
                sol[i] = '-';
            }
        }
        return sol;
    }
};
