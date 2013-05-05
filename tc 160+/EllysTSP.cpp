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

class EllysTSP {
public:
    int getMax(string places) {
        int nc = 0;
        int nv = 0;
        for (int i=0; i<(int)places.size(); ++i) {
            nc += (places[i]=='C');
            nv += (places[i]=='V');
        }
        return 2*min(nc, nv) + (max(nc, nv)>min(nc, nv));
    }
};
