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
#include <numeric>

using namespace std;

double dp[51];
class MergersDivTwo {
public:
    double findMaximum(vector <int> revenues, int k) {
        sort(revenues.begin(), revenues.end());
        vector<double> R(1, 0.0);
        copy(revenues.begin(), revenues.end(), back_inserter(R));
        int n = revenues.size();
        for (int i=1; i<=n; ++i) {
            R[i] += R[i-1];
        }
        dp[k] = R[k]/k;
        for (int i=k+1; i<=n; ++i) {
            dp[i] = R[i]/i;
            for (int j=i-k+1; j>=k; --j) {
                dp[i] = max(dp[i], (R[i]-R[j]+dp[j])/(i-j+1));
            }
        }
        return dp[n];
    }
};
