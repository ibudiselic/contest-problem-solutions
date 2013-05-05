#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int m, n, s;
int main() {
    scanf("%d %d %d", &m, &n, &s);
    long long sol = 0;
    for (int a=0; 2*a+1<=m; ++a) {
        for (int c=0; 2*c+1<=m; ++c) {
            for (int maxbd=0; 2*maxbd+1<=n; ++maxbd) {
                const long long H = 2*max(a, c) + 1;
                const long long W = 2*maxbd + 1;
                const long long fit_ways = (long long)(m-H+1)*(n-W+1);
                
                // maxbd == b
                long long Aab = (long long)(2*a+1)*(2*maxbd+1);
                long long Qfact = (long long)(2*c+1) - (2*min(a, c)+1);
                // s == Aab + Q*Qfact
                bool beqd_used = false;
                if (Qfact == 0) { // d can be any number <= b (i.e. b+1 different numbers)
                    if (Aab == s) {
                        beqd_used = true;
                        sol += (maxbd+1)*fit_ways;
                    }
                } else if ((s-Aab)*Qfact>=0 && (s-Aab)%Qfact==0) {
                    long long Q = (s-Aab)/Qfact;
                    assert(Aab + Q*Qfact == s);
                    if ((Q&1)==1 && 2*maxbd+1>=Q) { // then d is an integer <=b
                        sol += fit_ways;
                        if (2*maxbd+1 == Q) {
                            beqd_used = true;
                        }
                    }
                }

                // maxbd == d
                long long Acd = (long long)(2*c+1)*(2*maxbd+1);
                Qfact = (long long)(2*a+1) - (2*min(a, c)+1);
                if (Qfact == 0) {
                    if (Acd == s) {
                        sol += (maxbd+1-beqd_used)*fit_ways;
                    }
                } else if ((s-Acd)*Qfact>=0 && (s-Acd)%Qfact==0) {
                    long long Q = (s-Acd)/Qfact;
                    assert(Acd + Q*Qfact == s);
                    if ((Q&1)==1 && 2*maxbd+1>=Q && (!beqd_used || 2*maxbd+1>Q)) {
                        sol += fit_ways;
                    }
                }
            }
        }
    }

    printf("%I64d\n", sol);
    return 0;
}
