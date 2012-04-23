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

int calc(const string &s, int d) {
    int at = 0;
    int sol = 0;
    for (int i=0; i<(int)s.size(); ++i) {
        switch (s[i]) {
            case 'L': --at; break;
            case 'R': ++at; break;
            default: at += d; break;
        }
        sol = max(sol, abs(at));   
    }
    return sol;
}
class LeftOrRight {
public:
    int maxDistance(string program) {
        return max(calc(program, 1), calc(program, -1));
    }
};
