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

using namespace std;

class TheBrickTowerEasyDivTwo {
public:
    int find(int redCount, int redHeight, int blueCount, int blueHeight) {
        if (redCount > blueCount) {
            swap(redCount, blueCount);
            swap(redHeight, blueHeight);
        }
        if (redHeight == blueHeight) {
            return 2*redCount + (redCount<blueCount);
        } else {
            return 3*redCount + (redCount<blueCount);
        }
    }
};
