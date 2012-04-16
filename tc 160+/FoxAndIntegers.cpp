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

class FoxAndIntegers {
public:
    vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC) {
        int a = (AminusB+AplusB) / 2;
        int b = AplusB - a;
        int c = BplusC - b;
        if (a+b==AplusB && a-b==AminusB && b-c==BminusC && b+c==BplusC) {
            vector<int> sol(3, 0);
            sol[0] = a; sol[1] = b; sol[2] = c;
            return sol;
        } else {
            return vector<int>();
        }
    }
};
