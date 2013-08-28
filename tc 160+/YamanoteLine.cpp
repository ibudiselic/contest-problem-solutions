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
#include <utility>
#include <queue>

using namespace std;

long long inf = 12345678901234567LL;
typedef pair<long long, int> ans;

ans operator+(const ans& a, const ans &b) {
    return ans(a.first+b.first, a.second+b.second);
}

ans eval(long long L, int n, vector <int> s1, vector <int> t1, vector <int> l1, vector <int> s2, vector <int> t2, vector <int> l2) {
    vector<vector<pair<int, ans> > > adj(n+1);
    for (int i=0; i<n; ++i) {
        adj[i+1].push_back(make_pair(i, ans(-1, 0)));
    }
    adj[0].push_back(make_pair(n, ans(L, +1)));
    adj[n].push_back(make_pair(0, ans(-L, -1)));

    for (int i=0; i<(int)s1.size(); ++i) {
        if (s1[i] < t1[i]) {
            adj[t1[i]].push_back(make_pair(s1[i], ans(-l1[i], 0)));
        } else {
            adj[t1[i]].push_back(make_pair(s1[i], ans(L-l1[i], +1)));
        }
    }
    for (int i=0; i<(int)s2.size(); ++i) {
        if (s2[i] < t2[i]) {
            adj[s2[i]].push_back(make_pair(t2[i], ans(l2[i], 0)));
        } else {
            adj[s2[i]].push_back(make_pair(t2[i], ans(l2[i]-L, -1)));
        }
    }

    queue<int> Q;
    vector<ans> D(n+1, ans(inf, 0));
    vector<int> status(n+1, 0);
    D[0].first = 0;
    Q.push(0);
    int iter = 0;
    ans last;
    while (true) {
        if (++iter == n+2) {
            return ans(0, last.second);
        }
        queue<int> next;
        while (Q.size() > 0) {
            int u = Q.front();
            Q.pop();
            for (int i=0; i<(int)adj[u].size(); ++i) {
                int v = adj[u][i].first;
                ans cand = D[u] + adj[u][i].second;
                if (cand.first < D[v].first) {
                    if (cand.first < 0) {
                        return ans(0, cand.second);
                    }
                    last = D[v] = cand;
                    if (status[v] < iter) {
                        status[v] = iter;
                        next.push(v);
                    }
                }
            }
        }
        
        if (next.size() > 0) {
            Q = next;
        } else {
            break;
        }
    }

    return ans(1, 0);
}
class YamanoteLine {
public:
    long long howMany(int n, vector <int> s1, vector <int> t1, vector <int> l1, vector <int> s2, vector <int> t2, vector <int> l2) {
        long long lo = n-1;
        long long hi = inf;
        while (lo+1 < hi) {
            long long mid = lo + (hi-lo)/2;
            ans tmp = eval(mid, n, s1, t1, l1, s2, t2, l2);
            if (tmp.first || tmp.second<0) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        long long L = hi;

        lo = n;
        hi = inf+1;
        while (lo+1 < hi) {
            long long mid = lo + (hi-lo)/2;
            ans tmp = eval(mid, n, s1, t1, l1, s2, t2, l2);
            if (tmp.first || tmp.second>0) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        long long R = lo;

        if (L > R) {
            return 0;
        } else {
            return R==inf ? -1 : R-L+1;
        }
    }
};
