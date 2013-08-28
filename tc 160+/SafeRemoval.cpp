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

using namespace std;

int m4cnt[4];
int dp[51][51][51][51];
vector< vector<int> > nums;
const int FAILVAL = -987654321;
int modval(int n0, int n1, int n2, int n3) {
    return (n1 + 2*n2 + 3*n3)%4;
}
class SafeRemoval {
public:
    int removeThem(vector <int> seq, int k) {
        memset(m4cnt, 0, sizeof m4cnt);
        int n = seq.size();
        nums.assign(4, vector<int>());
        for (int i=0; i<n; ++i) {
            ++m4cnt[seq[i]%4];
            nums[seq[i]%4].push_back(seq[i]);
        }
        for (int i=0; i<4; ++i) {
            sort(nums[i].begin(), nums[i].end());
            reverse(nums[i].begin(), nums[i].end());
        }
        for (int a=0; a<51; ++a) {
            for (int b=0; b<51; ++b) {
                for (int c=0; c<51; ++c) {
                    for (int d=0; d<51; ++d) {
                        dp[a][b][c][d] = FAILVAL;
                    }
                }
            }
        }
        for (int n0=0; n0<=m4cnt[0]; ++n0) {
            if (m4cnt[0]-n0 > k) continue;
            for (int n1=0; n1<=m4cnt[1]; ++n1) {
                if (m4cnt[0]-n0 + m4cnt[1]-n1 > k) continue;
                for (int n2=0; n2<=m4cnt[2]; ++n2) {
                    const int n3 = m4cnt[3] - k + (m4cnt[0]-n0) + (m4cnt[1]-n1) + (m4cnt[2]-n2);
                    if (n3 < 0) {
                        break;
                    }
                    if (n3 > m4cnt[3]) {
                        continue;
                    }
                    if (modval(n0, n1, n2, n3) != 0) {
                        int val = 0;
                        int ns[] = {n0, n1, n2, n3};
                        for (int i=0; i<4; ++i) {
                            for (int j=0; j<ns[i]; ++j) {
                                val += nums[i][j];
                            }
                        }
                        dp[n0][n1][n2][n3] = val;
                    }
                }
            }
        }

        for (int n0=0; n0<=m4cnt[0]; ++n0) {
            if (m4cnt[0]-n0 >= k) continue;
            for (int n1=0; n1<=m4cnt[1]; ++n1) {
                if (m4cnt[0]-n0 + m4cnt[1]-n1 >= k) continue;
                for (int n2=0; n2<=m4cnt[2]; ++n2) {
                    if (m4cnt[0]-n0 + m4cnt[1]-n1 + m4cnt[2]-n2 >= k) continue;
                    for (int n3=0; n3<=m4cnt[3]; ++n3) {
                        if (m4cnt[0]-n0 + m4cnt[1]-n1 + m4cnt[2]-n2 + m4cnt[3]-n3 >= k) continue;
                        if (modval(n0, n1, n2, n3) == 0) continue;
                        int val = FAILVAL;
                        if (n0 > 0) {
                            val = max(val, dp[n0-1][n1][n2][n3]);
                        }
                        if (n1 > 0) {
                            val = max(val, dp[n0][n1-1][n2][n3]);
                        }
                        if (n2 > 0) {
                            val = max(val, dp[n0][n1][n2-1][n3]);
                        }
                        if (n3 > 0) {
                            val = max(val, dp[n0][n1][n2][n3-1]);
                        }
                        dp[n0][n1][n2][n3] = val;
                    }
                }
            }
        }

        int ret = dp[m4cnt[0]][m4cnt[1]][m4cnt[2]][m4cnt[3]];
        return (ret==FAILVAL ? -1 : ret);
    }
};
