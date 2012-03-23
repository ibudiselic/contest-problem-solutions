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

using namespace std;

class MagicCandy {
public:
    int whichOne(int n) {
        vector<int> sqrs;
        for (int i=1; i<=n/i; ++i) {
            sqrs.push_back(i*i);
        }
        sqrs.push_back(n+10);
        
        int s = 0;
        int x = 1;
        int by = 0;
        while (x <= n) {
            if (x == sqrs[s]) {
                ++x;
                ++by;
                ++s;
            } else {
                x += by;
            }
        }
        return x - by;
    }
};
