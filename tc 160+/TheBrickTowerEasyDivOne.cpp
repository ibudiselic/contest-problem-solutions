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

class TheBrickTowerEasyDivOne {
public:
    int find(int redCount, int redHeight, int blueCount, int blueHeight) {
        if (redCount > blueCount) {
            swap(redHeight, blueHeight);
            swap(redCount, blueCount);
        }
        if (redHeight == blueHeight) {
            return 2*redCount + (redCount<blueCount);
        } else {
            return 3*redCount + (redCount<blueCount);
        }
    }
};
