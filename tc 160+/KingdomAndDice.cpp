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
#include <set>
#include <numeric>

using namespace std;

int dp[2501];
class KingdomAndDice {
public:
    double newFairness(vector <int> A, vector <int> B, int X) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        set<int> all(A.begin(), A.end());
        all.insert(B.begin(), B.end());
        int zeros = count(A.begin(), A.end(), 0);
        int base = 0;
        int b = 0;
        for (int i=zeros; i<(int)A.size(); ++i) {
            while (b<(int)B.size() && B[b]<A[i]) {
                ++b;
            }
            base += b;
        }

        vector<int> nums;
        for (int i=0; i<(int)B.size(); ++i) {
            int x = B[i]+1;
            int added = 0;
            while (added<50 && x<=X && (i+1==(int)B.size() || x<B[i+1])) {
                if (!all.count(x)) {
                    ++added;
                    nums.push_back(i+1);
                }
                ++x;
            }
        }

        const int n = A.size();
        const int total = n*n;
        for (int i=0; i<=total; ++i) {
            dp[i] = 12345;
        }
        dp[0] = 0;
        for (int i=0; i<(int)nums.size(); ++i) {
            for (int val=total; val>=nums[i]; --val) {
                dp[val] = min(dp[val], dp[val-nums[i]] + 1);
            }
        }

        int a = 12345;
        b = -12345;
        for (int val=0; val<=total; ++val) {
            if (dp[val] <= zeros) {
                if (2*(base+val) <= total) {
                    a = base + val;
                } else if (b < 0) {
                    b = base + val;
                    break;
                }
            }
        }
        if (a > total) {
            if (b < 0) {
                return double(base)/total;
            } else {
                return double(b)/total;
            }
        } else {
            if (b < 0) {
                return double(a)/total;
            }
        }

        return a+b>=total ? double(a)/total : double(b)/total;
    }
};
