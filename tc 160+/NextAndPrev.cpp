//# strings, transformations, rotations, circularity
//# => See the editorial... pretty tricky
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

// basically 99% tourist's solution from the editorial
int to[256];
class NextAndPrev {
public:
    int getMinimum(int nextCost, int prevCost, string start, string goal) {
        if (start == goal) return 0;
        if ((set<char>(begin(goal), end(goal))).size() == 26) {
            return -1;
        }
        int n = start.size();
        memset(to, 0, sizeof to);
        for (int i=0; i<n; ++i) {
            if (to[start[i]] == 0) {
                to[start[i]] = goal[i];
            } else if (goal[i] != to[start[i]]) {
                return -1;
            }
        }
        typedef pair<int, int> pii;
        vector<pii> v;
        for (char c='a'; c<='z'; ++c) {
            if (to[c] != 0) {
                v.push_back(pii(c-'a', to[c]-'a'));
            }
        }

        n = v.size();
        const int inf = 1234567890;
        int sol = inf;
        for (int rot=0; rot<n; ++rot) {
            bool ok = true;
            for (int i=1; i<n; ++i) {
                if (v[i].second < v[i-1].second) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int shift=-2; shift<=2; ++shift) {
                    for (int i=0; i<n; ++i) {
                        v[i].second += shift*26;
                    }
                    int cand = 0;
                    int i = 0;
                    while (i < n) {
                        int j = i;
                        while (j<n && v[i].second==v[j].second) {
                            ++j;
                        }
                        int l=v[i].second, r=v[i].second;
                        for (int k=i; k<j; ++k) {
                            l = min(l, v[k].first);
                            r = max(r, v[k].first);
                        }
                        cand += (v[i].second-l)*nextCost;
                        cand += (r-v[i].second)*prevCost;
                        i = j;
                    }
                    sol = min(sol, cand);
                    for (int i=0; i<n; ++i) {
                        v[i].second -= shift*26;
                    }
                }
            }
            v[0].first += 26;
            sort(begin(v), end(v));
        }
        return sol==inf ? -1 : sol;
    }
};
