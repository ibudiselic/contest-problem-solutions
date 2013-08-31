#include <algorithm>
#include <cassert>
#include <cctype>
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
#include <cmath>

using namespace std;

const int MAXN = 13;
int G[MAXN][MAXN];
class BoundedOptimization {
public:
    double maxValue(vector <string> expr, vector <int> lowerBound, vector <int> upperBound, int maxSum) {
        memset(G, 0, sizeof G);
        string ex = accumulate(expr.begin(), expr.end(), string());
        int n = lowerBound.size();
        int start = 0;
        while (start < (int)ex.size()) {
            int a = ex[start]-'a';
            int b = ex[start+1]-'a';
            G[a][b] = G[b][a] = 1;
            start += 3;
        }
        double sol = 0.0;
        vector<double> val(n);
        for (int Smask=0; Smask<(1<<n); ++Smask) {
            vector<int> S;
            for (int i=0; i<n; ++i) {
                if (Smask & (1<<i)) {
                    S.push_back(i);
                }
            }
            bool isclique = true;
            for (int i=0; i<(int)S.size(); ++i) {
                for (int j=i+1; j<(int)S.size(); ++j) {
                    if (!G[S[i]][S[j]]) {
                        isclique = false;
                        goto CLIQUE_DONE;
                    }
                }
            }
            CLIQUE_DONE: ;
            if (!isclique) {
                continue;
            }
            vector<double> a(S.size());
            for (int lowmask=0; ; lowmask=(lowmask+Smask+1)&~Smask) {
                assert((lowmask & Smask) == 0);
                double M = maxSum;
                for (int i=0; i<n; ++i) {
                    if (Smask & (1<<i)) continue;
                    if (lowmask & (1<<i)) {
                        val[i] = lowerBound[i];
                    } else {
                        val[i] = upperBound[i];
                    }
                    M -= val[i];
                }
                if (M < -1e-9) {
                    if (lowmask == (1<<n)-1-Smask) {
                        break;
                    } else {
                        continue;
                    }
                }
                for (int i=0; i<(int)S.size(); ++i) {
                    int x = S[i];
                    a[i] = 0.0;
                    for (int j=0; j<n; ++j) {
                        if (Smask & (1<<j)) continue;
                        a[i] += G[x][j]*val[j];
                    }
                }

                if (S.size() > 0) {
                    double c = M - accumulate(a.begin(), a.end(), 0.0) - S.size()*M/2;
                    c /= S.size();
                    for (int i=0; i<(int)S.size(); ++i) {
                        val[S[i]] = a[i] + M/2 + c;
                    }
                }
                bool valid = true;
                for (int i=0; i<(int)S.size(); ++i) {
                    int x = S[i];
                    if (val[x]<lowerBound[x]-1e-9 || val[x]>upperBound[x]+1e-9) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    double cand = 0.0;
                    for (int i=0; i<n; ++i) {
                        for (int j=i+1; j<n; ++j) {
                            cand += G[i][j]*val[i]*val[j];
                        }
                    }
                    sol = max(sol, cand);
                }

                if (lowmask == (1<<n)-1-Smask) {
                    break;
                }
            }
        }
        return sol;
    }
};
