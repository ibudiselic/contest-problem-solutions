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

class PlatypusPaternity {
public:
    int maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups) {
        int n = siblingGroups[0].size();
        
        int sol = 0;
        for (int c=0; c<(int)siblingGroups.size(); ++c) {
            for (int i=0; i<(int)femaleCompatibility.size(); ++i) {
                for (int j=0; j<(int)maleCompatibility.size(); ++j) {
                    bool ok = true;
                    for (int k=0; k<n; ++k) {
                        if (siblingGroups[c][k] == 'Y') {
                            if (femaleCompatibility[i][k]=='N' || maleCompatibility[j][k]=='N') {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) {
                        int sz = 0;
                        for (int k=0; k<n; ++k) {
                            sz += (siblingGroups[c][k]=='Y');
                        }
                        sol = max(sol, 2 + sz);
                        break;
                    }
                }
            }
        }
        return sol;
    }
};
