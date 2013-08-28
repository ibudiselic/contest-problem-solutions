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

class FoxAndMountainEasy {
public:
    string possible(int n, int h0, int hn, string history) {
        if ((hn^h0^n)&1) {
            return "NO";
        }
        int max_minus = 0;
        int delta = 0;
        for (int i=0; i<(int)history.size(); ++i) {
            if (history[i] == 'U') {
                ++delta;
            } else {
                --delta;
                max_minus = min(max_minus, delta);
            }
        }
        for (int start=0; start+int(history.size())<=n; ++start) {
            int a = max((h0^start)&1, h0-start);
            int b = h0+start;
            if (a + max_minus < 0) {
                a += (-max_minus-a+1)/2*2;
                assert(a+max_minus >= 0);
            }
            if (a > b) continue;
            a += delta;
            b += delta;
            int rem = n - start - int(history.size());
            int c = max((hn^rem)&1, hn-rem);
            int d = hn + rem;
            if (b<c || d<a || (a==b && ((a^hn^rem)&1)) || (b==c && ((b^hn^rem)&1)) || (d==a && ((a^hn^rem)&1))) continue;
            return "YES";
        }
        return "NO";
    }
};
