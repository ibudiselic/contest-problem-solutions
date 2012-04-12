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
#include <map>
#include <numeric>
#include <iterator>

using namespace std;

map<long long, int> repr(long long n) {
    map<long long, int> ret;
    for (long long d=2; d<=n/d; ++d) {
        if (n%d == 0) {
            int cnt = 0;
            do {
                ++cnt;
                n /= d;
            } while (n%d == 0);
            ret[d] = cnt;
        }
    }
    if (n > 1) {
        ret[n] = 1;
    }
    return ret;
}
void merge(map<long long, int> &a, const map<long long, int> &b) {
    for (map<long long, int>::const_iterator it=b.begin(); it!=b.end(); ++it) {
        if (!a.count(it->first)) {
            a[it->first] = it->second;
        }
    }
}

vector<int> nums;
long long dp[2][1<<16];
class EllysNumbers {
public:
    long long getSubsets(long long n, vector <string> special) {
        string s = accumulate(special.begin(), special.end(), string());
        istringstream is(s);
        
        vector<long long> v;
        copy(istream_iterator<long long>(is), istream_iterator<long long>(), back_inserter(v));
        
        vector< map<long long, int> > reprs;
        map<long long, int> all;
        for (int i=0; i<(int)v.size(); ++i) {
            if (n%v[i] != 0) {
                continue;
            }
            map<long long, int> tmp = repr(v[i]);
            long long rem = n/v[i];
            bool ok = true;
            for (map<long long, int>::const_iterator it=tmp.begin(); it!=tmp.end(); ++it) {
                if (rem % (it->first) == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                merge(all, tmp);
                reprs.push_back(tmp);
            }
        }
        
        long long res = 1;
        for (map<long long, int>::const_iterator it=all.begin(); it!=all.end(); ++it) {
            long long f = it->first;
            int cnt = it->second;
            while (res<=n/f && cnt>0) {
                res *= f;
                --cnt;
            }
            if (cnt > 0) {
                return 0;
            }
        }
        if (res != n) {
            return 0;
        }
        
        assert(all.size() <= 16);
        map<long long, int> idx;
        int nfact = 0;
        for (map<long long, int>::const_iterator it=all.begin(); it!=all.end(); ++it) {
            idx[it->first] = nfact++;
        }
        assert(nfact == (int)all.size());
        
        nums.clear();
        for (int i=0; i<(int)reprs.size(); ++i) {
            int mask = 0;
            for (map<long long, int>::const_iterator it=reprs[i].begin(); it!=reprs[i].end(); ++it) {
                mask |= (1<<idx[it->first]);
            }
            nums.push_back(mask);
        }
        
        memset(dp, 0, sizeof dp);
        dp[1][0] = 1;
        for (int i=0; i<(int)nums.size(); ++i) {
            int cur = i&1;
            int prev = 1 - cur;
            for (int had=0; had<(1<<nfact); ++had) {
                if (dp[prev][had] > 0) {
                    dp[cur][had] += dp[prev][had];
                    if ((nums[i] & had) == 0) {
                        dp[cur][had|nums[i]] += dp[prev][had];
                    }
                    dp[prev][had] = 0;
                }
            }
        }
    
        return dp[(nums.size()+1)&1][(1<<nfact)-1];
    }
};
