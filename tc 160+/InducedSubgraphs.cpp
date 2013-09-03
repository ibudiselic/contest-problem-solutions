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

const int mod = 1000000009;
int n;
vector< vector<int> > G;
int sz[42][42];
int C[42][42];
int F[42];
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}

int getsz(int u, int p) {
    int &ret = sz[u][p];
    if (ret != -1) {
        return ret;
    }
    ret = 1;
    for (int i=0; i<(int)G[u].size(); ++i) {
        int v = G[u][i];
        if (v != p) {
            ret += getsz(v, u);
        }
    }
    return ret;
}

int ways[42][42]; // assign getsize(u, p) numbers to vertices of subtree(u, p) in a "heap-like" order
int getways(int u, int p) {
    int &ret = ways[u][p];
    if (ret != -1) {
        return ret;
    }
    int k = getsz(u, p) - 1;
    ret = 1;
    for (int i=0; i<(int)G[u].size(); ++i) {
        int v = G[u][i];
        if (v != p) {
            int subsz = getsz(v, u);
            ret = modmul(ret, modmul(C[k][subsz], getways(v, u)));
            k -= subsz;
        }
    }
    return ret;
}

int fastexp(int n, int k) {
    int ret = 1;
    while (k > 0) {
        if (k&1) ret = modmul(ret, n);
        n = modmul(n, n);
        k /= 2;
    }
    return ret;
}

int K;
int chain[42][42];
int chain_ways(int u, int p) {
    int &ret = chain[u][p];
    if (ret != -1) {
        return ret;
    }
    int subsz = getsz(u, p);
    if (subsz < K) {
        ret = 0;
    } else if (subsz == K) {
        ret = getways(u, p);
    } else {
        int nopts = 0;
        for (int i=0; i<(int)G[u].size(); ++i) {
            int v = G[u][i];
            if (v != p) {
                ++nopts;
            }
        }
        if (nopts != 1) {
            ret = 0;
        } else {
            for (int i=0; i<(int)G[u].size(); ++i) {
                int v = G[u][i];
                if (v != p) {
                    ret = chain_ways(v, u);
                    break;
                }
            }
        }
    }
    return ret;
}
int chain_ways() {
    int ret = 0;
    int nedges = n-2*K+1;
    memset(chain, 0xff, sizeof chain);
    for (int u=0; u<n; ++u) {
        for (int i=0; i<(int)G[u].size(); ++i) {
            int v = G[u][i];
            ret = modadd(ret, modmul(chain_ways(u, v), chain_ways(v, u)));
        }
    }
    ret = modmul(ret, fastexp(nedges, mod-2));
    return ret;
}

struct edge_t {
    int a, b;
    int get(int forward) {
        return forward ? b : a;
    }
};
vector<edge_t> E;

vector<vector<int> > H;
int tree[42][3][42][42][42];
int tree_ways(const int e, int forward, int cidx, int small, int big) {
    //cerr << e << ' ' << forward << ' ' << cidx << ' ' << small << ' ' << big << '\n';
    int &ret = tree[e][forward][cidx][small][big];
    if (ret != -1) {
        return ret;
    }

    int u, p;
    if (forward == 2) {
        u = e;
        p = -1;
    } else {
        u = E[e].get(forward);
        p = E[e].get(!forward);
    }

    if (small==0 && big==0) {
        ret = 1;
        return ret;
    }

    if (cidx==0 && (small==0 || big==0)) {
        assert(p != -1);
        int subsz = getsz(u, p);
        if (max(small, big) == subsz) {
            ret = getways(u, p);
            return ret;
        }
    }

    if (cidx < (int)H[u].size()) {
        int e2 = H[u][cidx];
        assert(e2 != 0);
        int v = E[abs(e2)-1].get(e2>0);
        if (v == p) {
            ++cidx;
        }
    }

    ret = 0;
    if (cidx == (int)H[u].size()) {
        ret = (small==0 && big==0);
    } else {
        int e2 = H[u][cidx];
        assert(e2 != 0);
        int v = E[abs(e2)-1].get(e2>0);
        assert(v != -1);

        if (small==0 && big==0) {
            ret = 1;
        } else if (small == 0) {
            ret = 0;
            for (int b=0; b<=big; ++b) {
                ret = modadd(ret, modmul(C[big][b], modmul(tree_ways(abs(e2)-1, e2>0, 0, 0, b), tree_ways(e, forward, cidx+1, 0, big-b))));
            }
        } else if (big == 0) {
            ret = 0;
            for (int s=0; s<=small; ++s) {
                ret = modadd(ret, modmul(C[small][s], modmul(tree_ways(abs(e2)-1, e2>0, 0, s, 0), tree_ways(e, forward, cidx+1, small-s, 0))));
            }
        } else {
            ret = 0;
            for (int b=0; b<=big; ++b) {
                for (int s=0; s<=small; ++s) {
                    int add = modmul(C[big][b], modmul(C[small][s], tree_ways(abs(e2)-1, e2>0, 0, s, b)));
                    if (add != 0) {
                        ret = modadd(ret, modmul(add, tree_ways(e, forward, cidx+1, small-s, big-b)));
                    }
                }
            }
        }
    }

    return ret;
}
int tree_ways() {
    int tree_nodes = 2*K - n;
    assert(tree_nodes > 0);
    memset(tree, 0xff, sizeof tree);
    H.assign(n, vector<int>());
    for (int i=0; i<(int)E.size(); ++i) {
        H[E[i].a].push_back(i+1);
        H[E[i].b].push_back(-i-1);
    }
    int ret = 0;
    for (int i=0; i<n; ++i) {
        ret = modadd(ret, tree_ways(i, 2, 0, (n-tree_nodes)/2, (n-tree_nodes)/2));
    }
    ret = modmul(ret, F[tree_nodes-1]);
    return ret;
}
class InducedSubgraphs {
public:
    int getCount(vector <int> edge1, vector <int> edge2, int k) {
        n = edge1.size() + 1;
        K = k;
        E.clear();
        G.assign(n, vector<int>());
        for (int i=0; i<n-1; ++i) {
            G[edge1[i]].push_back(edge2[i]);
            G[edge2[i]].push_back(edge1[i]);
            E.push_back((edge_t){edge1[i], edge2[i]});
        }
        C[0][0] = 1;
        for (int i=1; i<n; ++i) {
            C[i][0] = 1;
            for (int j=1; j<=i; ++j) {
                C[i][j] = modadd(C[i-1][j], C[i-1][j-1]);
            }
        }
        F[0] = 1;
        for (int i=1; i<=n; ++i) {
            F[i] = modmul(F[i-1], i);
        }
        if (k == 1) {
            return F[n];
        }
        
        memset(sz, 0xff, sizeof sz);
        memset(ways, 0xff, sizeof ways);
        if (2*k <= n) {
            return chain_ways();
        } else {
            return tree_ways();
        }
    }
};
