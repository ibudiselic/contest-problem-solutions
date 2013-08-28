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
#include <map>

using namespace std;

class ColorfulBricks {
public:
    int countLayouts(string bricks) {
        map<char, int> cnt;
        for (int i=0; i<(int)bricks.size(); ++i) {
            ++cnt[bricks[i]];
        }
        if (cnt.size() > 2) {
            return 0;
        }
        if (cnt.size() == 1) {
            return 1;
        }
        return 2;
    }
};
