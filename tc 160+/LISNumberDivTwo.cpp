//# increasing subsequence, subsequence, implementation
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

class LISNumberDivTwo {
public:
    int calculate(vector <int> seq) {
        int last = 123456789;
        int sol = 0;
        for (int i=0; i<(int)seq.size(); ++i) {
            if (seq[i] <= last) {
                ++sol;
            }
            last = seq[i];
        }
        return sol;
    }
};
