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
#include <cmath>

using namespace std;

class MergersDivOne {
public:
    double findMaximum(vector <int> revenues) {
        sort(revenues.begin(), revenues.end());
        double sol = revenues[0];
        for (int i=1; i<(int)revenues.size(); ++i) {
            sol = (sol + revenues[i]) / 2.0;
        }
        return sol;
    }
};
