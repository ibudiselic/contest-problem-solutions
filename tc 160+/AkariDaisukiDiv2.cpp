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

class AkariDaisukiDiv2 {
public:
    int countTuples(string S) {
        int n = S.size();
        int sol = 0;
        for (int i=1; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                for (int k=j+1; k+j-i+1<=n; ++k) {
                    if (S.substr(i, j-i) == S.substr(k, j-i)) {
                        ++sol;
                    }
                }
            }
        }
        return sol;
    }
};
