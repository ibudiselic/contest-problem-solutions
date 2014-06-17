//# probability, expectation, swaps
//# => Notice that there is only one significant probablity value and that is the probability that a value stays on the same position after K swaps. Compute that probability and then use linearity of expectation.
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

class TheSwapsDivOne {
public:
    double find(vector <string> sequence, int k) {
        string S = accumulate(begin(sequence), end(sequence), string());
        int n = S.size();
        double p = 1.0;
        double T = n*(n-1)/2;
        for (int i=0; i<k; ++i) {
            p = (p*(n-1)*(n-2)/2 + (1-p))/T;
        }
        double sol = 0.0;
        int all = accumulate(begin(S), end(S), 0) - n*'0';
        T = n*(n+1)/2;
        for (int i=0; i<n; ++i) {
            int val = S[i]-'0';
            sol += (i+1)*(n-i)/T*(p*val + (1-p)*(all-val)/(n-1));
        }
        return sol;
    }
};
