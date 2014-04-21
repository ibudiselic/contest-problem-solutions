//# implementation, trivial
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

class FoxAndGame {
public:
    int countStars(vector <string> result) {
        int sol = 0;
        for (int i=0; i<(int)result.size(); ++i) {
            sol += count(begin(result[i]), end(result[i]), 'o');
        }
        return sol;
    }
};
