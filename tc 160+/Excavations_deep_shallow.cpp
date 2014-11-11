//# dp, medium dp, excavation, depth, digging, artefacts
//# => See the regular version. This is a O(n^4) (slower) version which tracks the deepest depth of a discovered location and the shallowest depth of the excavated but not found artefacts. Conceptually, it is probably simpler, but the dp code is fairly tricky.
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

long long dp[2][54][54][52][2];
class Excavations {
public:
    long long count(vector <int> kind, vector <int> depth, vector <int> found_, int K) {
        int n = kind.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (kind[i]>kind[j] || (kind[i]==kind[j] && depth[i]>depth[j])) {
                    swap(kind[i], kind[j]);
                    swap(depth[i], depth[j]);
                }
            }
        }
        kind.insert(kind.begin(), 51);
        depth.insert(depth.begin(), 100001);
        kind.insert(kind.begin(), 51);
        depth.insert(depth.begin(), 0);
        n += 2;

        vector<int> found(n);
        {
        vector<int> found__(55);   
        for (int p : found_) found__[p] = 1;
        for (int i=0; i<n; ++i) {
            found[i] = found__[kind[i]];
        }
        }

        memset(dp, 0, sizeof dp);
        dp[1][0][1][0][0] = 1;
        for (int i=1; i<n-1; ++i) {
            int cur = i&1;
            int next = 1-cur;
            for (int deep=0; deep<=i; ++deep) {
                for (int shallow=0; shallow<=i; ++shallow) {
                    for (int k=0; k<=K; ++k) {
                        if (dp[cur][deep][shallow][k][0]) {
                            long long val = 0;
                            swap(val, dp[cur][deep][shallow][k][0]);

                            if (kind[i]==kind[i+1] || !found[i]) {
                                if (found[i+1]) {
                                    int ndeep = depth[i+1]>depth[deep] ? i+1 : deep;
                                    dp[next][ndeep][shallow][k+1][1] += val;
                                }
                                if (!found[i+1]) {
                                    int nshl = depth[i+1]<depth[shallow] ? i+1 : shallow;
                                    dp[next][deep][nshl][k+1][0] += val;
                                }
                                dp[next][deep][shallow][k][0] += val;
                            }
                        }
                        if (dp[cur][deep][shallow][k][1]) {
                            long long val = 0;
                            swap(val, dp[cur][deep][shallow][k][1]);

                            if (found[i+1]) {
                                int ndeep = kind[i]!=kind[i+1]&&depth[i+1]>depth[deep] ? i+1 : deep;
                                dp[next][ndeep][shallow][k+1][1] += val;
                            }
                            if (/*kind[i]!=kind[i+1] && */!found[i+1]) {
                                assert(kind[i] != kind[i+1]);
                                int nshl = depth[i+1]<depth[shallow] ? i+1 : shallow;
                                dp[next][deep][nshl][k+1][0] += val;
                            }
                            dp[next][deep][shallow][k][kind[i]==kind[i+1]] += val;
                        }
                    }
                }
            }
        }

        long long sol = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (depth[i] < depth[j]) {
                    sol += dp[(n+1)&1][i][j][K][found[n-1]];
                }
            }
        }
        return sol;
    }
};
