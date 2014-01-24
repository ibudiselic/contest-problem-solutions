//# implementation, math
//# => trivial
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

class TheSimilarNumbers {
public:
    int find(int lower, int upper) {
        int sol = 0;
        while (lower <= upper) {
            ++sol;
            lower = 10*lower+1;
        }
        return sol;
    }
};
