//# implementation, trivial, sorting
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

class Chopsticks {
public:
    int getmax(vector <int> length) {
        sort(begin(length), end(length));
        int sol = 0;
        while (length.size() >= 2) {
            if (length.back() == length[length.size()-2]) {
                ++sol;
                length.pop_back();
                length.pop_back();
            } else {
                length.pop_back();
            }
        }
        return sol;
    }
};
