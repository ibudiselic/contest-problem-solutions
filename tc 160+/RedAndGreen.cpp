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

class RedAndGreen {
public:
    int minPaints(string row) {
        int r = 0;
        for (int i=0; i<(int)row.size(); ++i) {
            if (row[i] == 'R') {
                ++r;
            }
        }
        int sol = 1234;
        int g = 0;
        for (int i=0; i<(int)row.size(); ++i) {
            sol = min(sol, g+r);
            if (row[i] == 'G') {
                ++g;
            } else {
                --r;
            }
            sol = min(sol, g+r);
        }
        return sol;
    }
};
