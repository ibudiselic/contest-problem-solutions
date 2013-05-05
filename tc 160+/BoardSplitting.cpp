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

int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
int lcm(int m, int n) {
    return m*n/gcd(m, n);
}
class BoardSplitting {
public:
    int minimumCuts(int desired, int cnt, int actual) {
        int nparts = lcm(desired, actual)/desired;
        return cnt/nparts*(nparts-1) + cnt%nparts;
    }
};
