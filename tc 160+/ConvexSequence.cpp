#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class ConvexSequence {
public:
    long long getMinimum(vector <int> a) {
        int n = (int)a.size();
        long long sol = 0;
        while (1) {
            bool change = false;
            for (int i=1; i<n-1; ++i) {
                if (2*a[i] > a[i-1]+a[i+1]) {
                    int by = (2*a[i]-a[i-1]-a[i+1]+1) / 2;
                    a[i] -= by;
                    sol += by;
                    change = true;
                }
            }
            if (!change) {
                break;
            }
        }
        
        return sol;
    }
};
