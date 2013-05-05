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

class ElectionFraudDiv2 {
public:
    string IsFraudulent(vector <int> percentages) {
        int T = 10000;
        int a = 0;
        int b = 0;
        for (int i=0; i<(int)percentages.size(); ++i) {
            int p = percentages[i];
            int lo = max(0, (T*(2*p-1)+199)/200);
            int hi = min(T, (T*(2*p+1)-1)/200);
            if (lo > hi) {
                return "YES";
            }
            a += lo;
            b += hi;
        }
        return a>T || b<T ? "YES" : "NO";
    }
};
