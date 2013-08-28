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
#include <numeric>

using namespace std;

class GreatFairyWar {
public:
    int minHP(vector <int> dps, vector <int> hp) {
        int sol = 0;
        for (int i=0; i<(int)dps.size(); ++i) {
            sol += hp[i]*accumulate(dps.begin()+i, dps.end(), 0);
        }
        return sol;
    }
};
