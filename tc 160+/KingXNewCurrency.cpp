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
bool can(int x, int y, int a) {
    int cur = 0;
    while (cur < a) {
        if ((a-cur)%y == 0) {
            return true;
        }
        cur += x;
    }
    return cur == a;
}
class KingXNewCurrency {
public:
    int howMany(int A, int B, int X) {
        if (gcd(A, B)%X == 0) {
            return -1;
        }
        if (A > B) {
            swap(A, B);
        }
        
        int sol = 0;
        for (int Y=1; Y<=B; ++Y) {
            if (Y!=X && can(X, Y, A) && can(X, Y, B)) {
                ++sol;
            }
        }
        return sol;
    }
};
