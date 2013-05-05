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

class ANDEquation {
public:
    int restoreY(vector <int> A) {
        int n = A.size();
        for (int i=0; i<n; ++i) {
            int ret = (1<<20)-1;
            for (int j=0; j<n; ++j) {
                if (i != j) {
                    ret &= A[j];
                }
            }
            if (ret == A[i]) {
                return ret;
            }
        }
        return -1;
    }
};
