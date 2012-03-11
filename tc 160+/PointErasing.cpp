#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// this is a transcription of Petr's solution to C++
bool cankill[50][50];
bool dp[2][51][51];
vector<int> calc(int l, int r, int yval, const vector<int> &y) {
    if (l > r) {
        return vector<int>(1, 1);
    }
    int n = 0;
    vector<int> idx(y.size(), -1);
    for (int i=l; i<=r; ++i) {
        if (y[i] == yval) {
            idx[i] = n++;
        }
    }
    vector<int> L(y.size()), R(y.size());
    int cur = -1;
    for (int i=0; i<(int)y.size(); ++i) {
        if (idx[i] != -1) {
            cur = idx[i];
        }
        L[i] = cur;
    }
    cur = -1;
    for (int i=(int)y.size()-1; i>=0; --i) {
        if (idx[i] != -1) {
            cur = idx[i];
        }
        R[i] = cur;
    }
    
    memset(cankill, 0, sizeof cankill);
    for (int i=0; i<(int)y.size(); ++i) {
        for (int j=0; j<(int)y.size(); ++j) {
            if ((y[i]<yval && y[j]>yval) || (y[i]>yval && y[j]<yval)) {
                int first = R[i];
                int last = L[j];
                if (first<=last && first!=-1 && last!=-1) {
                    cankill[first][last] = true;
                }
            }
        }
    }
    memset(dp, 0, sizeof dp); // [i&1][j][k]=true iff j of the points before k can be alive using all the rectangles with first<=i
    dp[1][0][0] = true;
    for (int first=0; first<n; ++first) {
        int cur = first&1;
        int last = 1-cur;
        memset(dp[cur], 0, sizeof dp[cur]);
        for (int last_alive=0; last_alive<=n; ++last_alive) {
            int l = n;
            for (int i=first; i<=n; ++i) {
                if (dp[last][last_alive][i]) {
                    l = i;
                    break;
                }
            }
            for (int i=first; i<=n; ++i) {
                if (dp[last][last_alive][i]) {
                    dp[cur][last_alive][i] = true;
                }
            }
            for (int last=l; last<n; ++last) {
                if (cankill[first][last]) {
                    dp[cur][last_alive][last+1] = true;
                }
            }
            if (dp[cur][last_alive][first]) {
                dp[cur][last_alive+1][first+1] = true;
                dp[cur][last_alive][first] = false;
            }
        }
    }
    
    vector<int> ret(n+1, 0);
    for (int i=0; i<=n; ++i) {
        if (dp[(n+1)&1][i][n]) {
            ret[i] = true;
        }
    }
    return ret;
}
class PointErasing {
public:
    vector <int> getOutcomes(vector <int> y) {
        int ymin=y[0], ymax=y[0];
        for (int i=1; i<(int)y.size(); ++i) {
            ymin = min(ymin, y[i]);
            ymax = max(ymax, y[i]);
        }
        int l = -1;
        for (int i=0; i<(int)y.size(); ++i) {
            if (y[i]==ymin || y[i]==ymax) {
                l = i;
                break;
            }
        }
        int r = -1;
        for (int i=(int)y.size()-1; i>=0; --i) {
            if (y[i]==ymin || y[i]==ymax) {
                r = i;
                break;
            }
        }
        assert(l!=-1 && r!=-1);
        
        int nstay = 0;
        for (int i=0; i<(int)y.size(); ++i) {
            if (y[i]==ymin || y[i]==ymax) {
                ++nstay;
            }
        }
        
        vector<int> left = calc(0, l-1, y[0], y);
        vector<int> right = calc(r+1, (int)y.size()-1, y.back(), y);
        vector<int> can(y.size() + 1, 0);
        for (int i=0; i<(int)left.size(); ++i) {
            for (int j=0; j<(int)right.size(); ++j) {
                if (left[i] && right[j]) {
                    can[i+j+nstay] = 1;
                }
            }
        }
        
        vector<int> sol;
        for (int i=nstay; i<(int)can.size(); ++i) {
            if (can[i]) {
                sol.push_back(i);
            }
        }
        return sol;
    }
};
