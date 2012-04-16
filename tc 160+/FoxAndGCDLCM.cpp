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

long long gcd(long long m, long long n) {
    return m==0 ? n : gcd(n%m, m);
}
class FoxAndGCDLCM {
public:
    long long get(long long G, long long L) {
        if (L%G != 0) {
            return -1;
        }
        long long PQ = L/G;
        long long sol = -1;
        for (long long p=1; p*p<=PQ; ++p) {
            if (PQ%p == 0) {
                if ((sol==-1 || p+PQ/p<sol) && gcd(p, PQ/p)==1) {
                    sol = p + PQ/p;
                }
            }
        }
        sol *= G;
        return sol;
    }
};
