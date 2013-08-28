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
#include <queue>
#include <utility>

using namespace std;

typedef pair<long long, int> pli;

int D[1000001];
vector<int> P;
class HolyNumbers {
public:
    long long count(long long M, int maximalPrime) {
        memset(D, 0, sizeof D);
        P.clear();
        for (int i=2; i<=maximalPrime; ++i) {
            if (D[i] == 0) {
                D[i] = i;
                P.push_back(i);
            }
            for (int j=0; j<(int)P.size() && P[j]<=D[i] && P[j]<=maximalPrime/i; ++j) {
                D[P[j]*i] = P[j];
            }
        }
        
        long long sol = 1;
        queue<pli> Q;
        Q.push(pli(1, 0));
        while (!Q.empty()) {
            pli t = Q.front();
            Q.pop();
            if (t.second==(int)P.size() || t.first*P[t.second]>M) {
                continue;
            }
            const long long psqr = (long long)P[t.second]*P[t.second];
            if (t.first > M/psqr) {
                sol += (upper_bound(P.begin(), P.end(), M/t.first) - P.begin()) - t.second;
                continue;
            }
            Q.push(pli(t.first, t.second+1));
            t.first *= P[t.second];
            while (true) {
                ++sol;
                Q.push(pli(t.first, t.second+1));
                if (t.first <= M/psqr) {
                    t.first *= psqr;
                } else {
                    break;
                }
            }
        }

        return sol;
    }
};
