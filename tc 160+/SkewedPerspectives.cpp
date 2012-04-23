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

class SkewedPerspectives {
public:
    vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views) {
        vector<string> sol;
        for (int i=0; i<(int)views.size(); ++i) {
            const string &W = views[i];
            int atw = 0;
            vector<int> need(3, 0);
            int any = 0;
            int anyb = 0;
            int nb = 0;
            bool ok = true;
            for (int h=0; h<(int)W.size(); ++h) {
                if (W[h] == 'b') {
                    int h2 = h+1;
                    while (h2<(int)W.size() && W[h2]=='b') {
                        ++h2;
                    }
                    int len = h2 - h;
                    if (len & 1) {
                        if (h == 0) {
                            if (h2==1 || ++nb>B) {
                                ok = false;
                                break;
                            }
                            ++h; // must add B into the first column then
                        } else {
                            if (++atw>=w || ++nb>B) { // new col
                                ok = false;
                                break;
                            }
                            any += h - 1;
                            anyb += (h-1)/2;
                        }
                    } else {
                        if (++nb > B) {
                            ok = false;
                            break;
                        }
                        ++h;
                    }
                } else {
                    int color = W[h] - '0';
                    if (++need[color] > cubes[color]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                for (int i=0; i<3; ++i) {
                    any -= cubes[i]-need[i];
                }
                any -= min(anyb, B-nb)*2;
            }
            if (ok && any<=0) {
                sol.push_back("valid");
            } else {
                sol.push_back("invalid");
            }
        }
        
        return sol;
    }
};
