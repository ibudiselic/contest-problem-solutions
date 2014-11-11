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

class TopFox {
public:
    int possibleHandles(string a, string b) {
        set<string> opts;
        for (int i=0; i<(int)a.size(); ++i) {
            for (int j=0; j<(int)b.size(); ++j) {
                opts.insert(a.substr(0, i+1) + b.substr(0, j+1));
            }
        }
        return opts.size();
    }
};
