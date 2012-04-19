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

int P(int x, const vector<int> &a) {
    int val = 0;
    for (int i=0; i<(int)a.size(); ++i) {
        if (a[i] && (i==0 || x==1)) {
            ++val;
        }
    }
    return val%2;
}
class BinaryPolynomialDivTwo {
public:
    int countRoots(vector <int> a) {
        int sol = 0;
        for (int x=0; x<2; ++x) {
            sol += (P(x, a) == 0);
        }
        return sol;
    }
};
