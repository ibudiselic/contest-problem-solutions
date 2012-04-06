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

class DengklekTryingToSleep {
public:
    int minDucks(vector <int> ducks) {
        int l = *min_element(ducks.begin(), ducks.end());
        int r = *max_element(ducks.begin(), ducks.end());
        return r-l+1-(int)ducks.size();
    }
};
