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

class DeerInZooDivTwo {
public:
    vector <int> getminmax(int N, int K) {
       return vector<int>{max(0, N-K), (2*N-K)/2};
    }
};
