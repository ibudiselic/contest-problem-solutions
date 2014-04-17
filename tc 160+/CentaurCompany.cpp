//# network, tree, conected components, company, expectation
//# => The key idea is to work out that the cost depends only on the number of nodes given to a company and the number of connected components those nodes are in. This can be done by noticing that any connected component with more than 1 node can be connected in a chain and the 1-node components can then be connected as "appendages" to this chain, and each such commponent except the two that are connected to the endpoints of the chain will cost one. The expected cost is then just the sum of probabilities that a certain number of nodes comprising a certain number of components are assigned to a company multiplied by the corresponding cost. Due to linearity of expectation the total expectation is just twice the expectation for one company, and that can be computed via dp.
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

vector<vector<int>> T;
int n;
const int MAXN = 36+2;
bool done[MAXN][MAXN][MAXN][MAXN][2];
double prob[MAXN][MAXN][MAXN][MAXN][2];
double getprob(int u, int p, int start, int total, int comps, bool taken) {
    if (done[u][start][total][comps][taken]) {
        return prob[u][start][total][comps][taken];
    }
    done[u][start][total][comps][taken] = 1;
    double &ret = prob[u][start][total][comps][taken];
    if (total < comps) {
        ret = 0.0;
    } else if (start == (int)T[u].size()) {
        if (total==0 && comps==0) {
            ret = 1.0;
        } else {
            ret = 0.0;
        }
    } else if (T[u][start] == p) {
        ret = getprob(u, p, start+1, total, comps, taken);
    } else {
        ret = 0.0;
        // other
        double add = 0.0;
        for (int rem=0; rem<=total; ++rem) {
            for (int rcomps=0; rcomps<=comps; ++rcomps) {
                add += getprob(T[u][start], u, 0, rem, rcomps, 0)*getprob(u, p, start+1, total-rem, comps-rcomps, taken);
            }
        }
        ret += add/2;
        
        // this
        if (total > 0) {
            add = 0.0;
            if (taken) {
                for (int rem=0; rem<total; ++rem) {
                    for (int rcomps=0; rcomps<=comps; ++rcomps) {
                        add += getprob(T[u][start], u, 0, rem, rcomps, 1)*getprob(u, p, start+1, total-1-rem, comps-rcomps, 1);
                    }
                }
            } else if (comps > 0) { // otherwise can't take this child
                for (int rem=0; rem<total; ++rem) {
                    for (int rcomps=0; rcomps<comps; ++rcomps) {
                        add += getprob(T[u][start], u, 0, rem, rcomps, 1)*getprob(u, p, start+1, total-1-rem, comps-1-rcomps, 0);
                    }
                }
            }
            ret += add/2;
        }
    }

    return ret;
}
class CentaurCompany {
public:
    double getvalue(vector <int> a, vector <int> b) {
        n = a.size()+1;  
        T.assign(n, vector<int>());
        for (int i=0; i<n-1; ++i) {
            int x = a[i]-1;
            int y = b[i]-1;
            T[x].push_back(y);
            T[y].push_back(x);
        }

        memset(done, 0, sizeof done);
        double sol = 0;
        for (int total=3; total<=n; ++total) {
            for (int comps=1; comps<=n; ++comps) {
                int cost = 2*comps-total-2;
                if (cost > 0) {
                    double p = 0.5 * (getprob(0, -1, 0, total, comps, 0) +
                                      getprob(0, -1, 0, total-1, comps-1, 1));
                    //cerr << total << ' ' << comps << ' ' << p << ' ' << cost << '\n';
                    sol += p*cost;
                }
            }
        }
        return 2*sol;
    }
};
