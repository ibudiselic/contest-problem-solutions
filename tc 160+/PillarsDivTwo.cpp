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
#include <cmath>

using namespace std;

double dp[2][101];
class PillarsDivTwo {
public:
    double maximalLength(vector <int> height, int w) {
        for (int i=1; i<=height[0]; ++i) {
            dp[0][i] = 0.0;
        }
        for (int i=1; i<(int)height.size(); ++i) {
            for (int h=1; h<=height[i]; ++h) {
                dp[i&1][h] = -1e20;
                for (int ph=1; ph<=height[i-1]; ++ph) {
                    dp[i&1][h] = max(dp[i&1][h], dp[(i+1)&1][ph] + sqrt(w*w + (h-ph)*(h-ph)));
                }
            }
        }

        return *max_element(dp[int(height.size() + 1)&1]+1, dp[int(height.size() + 1)&1]+height.back()+1);
    }
};
