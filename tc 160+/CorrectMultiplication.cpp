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

long long mabs(long long x) { return x<0 ? -x : x; }
class CorrectMultiplication {
public:
    long long getMinimum(int a, int b, int c) {
        if (a > b) {
            swap(a, b);
        }
        long long sol = (long long)a+b+c-3;
        for (long long A=1; A*A<=(c+sol); ++A) {
            for (int d=-1; d<2; ++d) {
                long long B = c/A + d;
                if (B > 0) {
                    sol = min(sol, mabs(A-a) + mabs(B-b) + mabs(A*B-c));
                }
            }
        }
        
        return sol;
    }
};
