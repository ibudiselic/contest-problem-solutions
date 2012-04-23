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

class EvenRoute {
public:
    string isItPossible(vector <int> x, vector <int> y, int wp) {
        for (int i=0; i<(int)x.size(); ++i) {
            if (((abs(x[i]) + abs(y[i])) & 1) == wp) {
                return "CAN";
            }
        }
        return "CANNOT";
    }
};
