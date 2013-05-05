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

class ElectionFraudDiv1 {
public:
    int MinimumVoters(vector <int> percentages) {
        for (int T=1; T<500000; ++T) {
            bool failed = false;
            long long a=0, b=0;
            for (int i=0; i<(int)percentages.size(); ++i) {
                int p = percentages[i];
                long long lo = max(0ll, ((long long)T*(2*p-1)+199)/200);
                long long hi = min((long long)T, ((long long)T*(2*p+1)-1)/200);
                if (lo > hi) {
                    failed = true;
                    break;
                }
                a += lo;
                b += hi;
            }
            if (failed || a>T || b<T) {
                continue;
            }
            return T;
        }

        return -1;
    }
};
