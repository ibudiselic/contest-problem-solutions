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

int L[3];
int fact[] = {2, 4, 8};
class SRMCodingPhase {
public:
    int countScore(vector <int> points, vector <int> skills, int luck) {
        vector<int> order;
        for (int i=0; i<3; ++i) {
            order.push_back(i);
        }
        int sol = 0;
        for (L[0]=0; L[0]<=min(luck, skills[0]-1); ++L[0]) {
            for (L[1]=0; L[1]<=min(luck-L[0], skills[1]-1); ++L[1]) {
                L[2] = luck - L[0] - L[1];
                assert(L[2] >= 0);
                L[2] = min(L[2], skills[2]-1);
                do {
                    int cand = 0;
                    int tleft = 75;
                    for (int i=0; i<3; ++i) {
                        int t = skills[order[i]] - L[order[i]];
                        if (t<=tleft && points[order[i]]>=fact[order[i]]*t) {
                            cand += points[order[i]] - fact[order[i]]*t;
                            tleft -= t;
                        } else {
                            break;
                        }
                    }
                    sol = max(sol, cand);
                } while (next_permutation(order.begin(), order.end()));
            }
        }
        return sol;
    }
};
