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

class BigAndSmallAirports {
public:
    long long solve(int Nlo, int Nhi, int Blo, int Bhi, int Slo, int Shi) {
        long long sol = 0;
        for (int B=Blo; B<=Bhi; ++B) {
            const int Slim = min(Shi, B-1);
            for (int S=Slo; S<=Slim; ++S) {
                if (S == 1) {
                    if (Nlo<=1 && 1<=Nhi) {
                        ++sol;
                    }
                    if (Nlo<=2 && 2<=Nhi) {
                        ++sol;
                    }
                }
                if (S > 1) {
                    sol += Nhi-Nlo+1;
                }
                for (int b=1; b<=B; ++b) {
                    int minN = max(Nlo, max(B+1, (b*(B-b+S+1)+S-1)/S));
                    sol += max(0, Nhi-minN+1);
                }
                long long a = max(0, Nlo-B);
                long long b = max(0, Nhi-B);
                sol += (a+b)*(b-a+1)/2;
            }
        }
        return sol;
    }
};
