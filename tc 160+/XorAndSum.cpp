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

class XorAndSum {
public:
    long long maxSum(vector<long long> number) {
        int n = number.size();
        int r = 0;
        for (int j=60; j>=0; --j) {
            for (int i=r; i<n; ++i) {
                if (number[i] & (1ll<<j)) {
                    swap(number[i], number[r]);
                    for (int x=0; x<n; ++x) {
                        if (x!=r && (number[x] & (1ll<<j))) {
                            number[x] ^= number[r];
                        }
                    }
                    r++;
                    break;
                }
            }
        }

        for (int i=1; i<r; ++i) {
            number[0] ^= number[i];
        }
        for (int i=1; i<n; ++i) {
            number[i] ^= number[0];
        }
        return accumulate(number.begin(), number.end(), 0ll);
    }
};
