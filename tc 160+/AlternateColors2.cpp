//# case, dp, implementation
//# => split into moves before kth and after kth
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

const int MAXN = 100010;
long long w2[MAXN], w3[MAXN];
long long b2[MAXN], b3[MAXN];
class AlternateColors2 {
public:
    long long countWays(int n, int k) {
        int after = n-k+1;
        memset(w2, 0, sizeof w2);
        memset(w3, 0, sizeof w3);

        w2[2] = 1;
        for (int have=3; have<=after; ++have) {
            w2[have] = w2[have-2] + 2;
        }
        w3[3] = 1;
        for (int have=4; have<=after; ++have) {
            w3[have] = w3[have-3] + 3*w2[have-3] + 3;
        }

        long long sol = 0;
        for (int three=0; 3*three<k; ++three) {
            if (3*three+1 == k) {
                sol += w3[after] + 2*w2[after]; // continue with three or red + (green|blue)
            }
            ++sol; // from three to just red
            for (int two=1; 3*three+2*two<k; ++two) {
                sol += 2; // from two to just red
                if (3*three+2*two+1 == k) {
                    sol += 2*w2[after]; // continue with two
                }
            }
        }

        return sol;
    }
};
