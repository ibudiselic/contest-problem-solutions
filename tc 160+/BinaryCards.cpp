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

class BinaryCards {
public:
    long long largestNumber(long long A, long long B) {
        long long prefix = 0;
        for (long long mask=(1ll<<62); mask>0; mask>>=1) {
            if ((B&mask) && !(A&mask)) {
                return prefix + 2*mask - 1;
            }
            if (B&mask) {
                prefix |= mask;
            }
        }
        return A;
    }
};
