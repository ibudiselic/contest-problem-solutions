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

class WorkingRabbits {
public:
    double getEfficiency(vector <string> profit) {
        int n = profit.size();
        int x = 0;
        int y = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                x += profit[i][j] - '0';
                ++y;
            }
        }
        return double(x)/y;
    }
};
