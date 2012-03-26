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

class Cut {
public:
    int getMaximum(vector <int> L, int ncuts) {
        int sol = 0;
        sort(L.begin(), L.end());
        for (int i=0; i<(int)L.size(); ++i) {
            if (L[i]%10 == 0) {
                int need = L[i]/10 - 1;
                if (need <= ncuts) {
                    sol += need + 1;
                    ncuts -= need;
                    L[i] = 0;
                } else {
                    sol += ncuts;
                    ncuts = 0;
                    L[i] = 0;
                }
            }
        }
        
        for (int i=0; i<(int)L.size(); ++i) {
            if (L[i] > 0) {
                int canget = L[i]/10;
                if (canget <= ncuts) {
                    ncuts -= canget;
                    sol += canget;
                } else {
                    return sol + ncuts;
                }
            }
        }
        
        return sol;
    }
};
