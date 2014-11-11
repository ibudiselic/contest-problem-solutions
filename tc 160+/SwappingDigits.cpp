//# implementation, strings
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

class SwappingDigits {
public:
    string minNumber(string num) {
        string sol = num;
        for (int i=0; i<(int)num.size(); ++i) {
            for (int j=i+1; j<(int)num.size(); ++j) {
                swap(num[i], num[j]);
                if (num[0] != '0') {
                    sol = min(sol, num);
                }
                swap(num[i], num[j]);
            }
        }
        return sol;
    }
};
