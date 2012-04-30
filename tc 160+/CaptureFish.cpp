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

enum {
    O, X, ANY
};
bool upd(int &state, char c) {
    if (c == 'X') {
        if (state == O) {
            return false;
        }
        state = X;
    } else if (c == 'O') {
        if (state == X) {
            return false;
        }
        state = O;
    }
    return true;
}
class CaptureFish {
public:
    int getParity(string fish) {
        int sol = 0;
        int n = fish.size();
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                int out_state = ANY;
                int in_state = ANY;
                for (int k=0; k<n; ++k) {
                    if (i<=k && k<=j) {
                        if (!upd(in_state, fish[k])) {
                            out_state = in_state = X;
                            break;
                        }
                    } else {
                        if (!upd(out_state, fish[k])) {
                            out_state = in_state = X;
                            break;
                        }
                    }
                }
                if (out_state!=in_state || (in_state==ANY && out_state==ANY)) {
                    ++sol;
                }
            }
        }
        return sol%2;
    }
};
