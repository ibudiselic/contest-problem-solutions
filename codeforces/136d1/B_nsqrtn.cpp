#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 100000;
int A[MAXN];
vector<int> nums;
int sum[500][MAXN+2];
int main() {
    int n, Q;
    scanf("%d %d", &n, &Q);
    map<int, int> cnt;
    for (int i=0; i<n; ++i) {
        scanf("%d", A+i);
        ++cnt[A[i]];
    }

    for (map<int, int>::const_iterator it=cnt.begin(); it!=cnt.end(); ++it) {
        if (it->second >= it->first) {
            nums.push_back(it->first);
        }
    }

    for (int i=0; i<(int)nums.size(); ++i) {
       sum[i][0] = 0;
       for (int j=0; j<n; ++j) {
           sum[i][j+1] = sum[i][j];
           if (nums[i] == A[j]) {
               ++sum[i][j+1];
           }
       }
    }

    for (int i=0; i<Q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ret = 0;
        for (int j=0; j<(int)nums.size(); ++j) {
            if (sum[j][r] - sum[j][l-1] == nums[j]) {
                ++ret;
            }
        }
        printf("%d\n", ret);
    }
    
    return 0;
}
