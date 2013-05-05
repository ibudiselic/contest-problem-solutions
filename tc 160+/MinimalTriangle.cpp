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
#include <cmath>

using namespace std;

class MinimalTriangle {
public:
    double maximalArea(int length) {
        return double(length)*length*sqrt(3)/4;
    }
};
