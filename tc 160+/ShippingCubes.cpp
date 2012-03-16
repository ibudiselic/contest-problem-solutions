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

class ShippingCubes {
public:
    int minimalCost(int N) {
        int sol = 3*N*N*N;
        for (int a=1; a*a*a<=N; ++a) {
            if (N%a) {
                continue;
            }
            for (int b=a; a*b*b<=N; ++b) {
                if (N%(a*b)) {
                   continue;
                }
                sol = min(sol, a + b + N/a/b);
            }
        }
        return sol;
    }
};
