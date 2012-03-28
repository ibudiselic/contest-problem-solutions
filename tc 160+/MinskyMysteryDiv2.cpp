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

class MinskyMysteryDiv2 {
public:
    long long computeAnswer(long long N) {
        if (N < 2) {
            return -1;
        }
        long long d = 2;
        while (d*d <= N) {
            if (N%d == 0) {
                return N/d + d;
            }
            ++d;
        }
        return N + 1;
    }
};
