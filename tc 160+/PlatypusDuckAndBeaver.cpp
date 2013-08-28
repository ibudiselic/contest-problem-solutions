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

class PlatypusDuckAndBeaver {
public:
    int minimumAnimals(int feet, int bills, int tails) {
        for (int beavers=0; beavers<=1000; ++beavers) {
            for (int ducks=0; ducks<=1000; ++ducks) {
                if (ducks*2+beavers*4>feet || ducks>bills) break;
                int f = feet - ducks*2 - beavers*4;
                int b = bills - ducks;
                int p = f/4;
                if (p*4==f && p==b && tails-beavers==p) {
                    return beavers+ducks+p;
                }
            }
        }

        return -1;
    }
};
