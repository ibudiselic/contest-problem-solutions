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

bool deg_can[50][360];
class TurtleSpy {
public:
    double maxDistance(vector <string> commands) {
        int F = 0;
        int B = 0;
        vector<int> degs;
        for (int i=0; i<(int)commands.size(); ++i) {
            istringstream is(commands[i]);
            string c;
            int x;
            is >> c >> x;
            switch (c[0]) {
                case 'r': degs.push_back(x); break;
                case 'l': degs.push_back(-x); break;
                case 'f': F += x; break;
                case 'b': B += x; break;
                default: assert(0); break;
            }
        }
        
        memset(deg_can, 0, sizeof deg_can);
        deg_can[0][0] = true;
        for (int i=0; i<(int)degs.size(); ++i) {
            for (int d=0; d<360; ++d) {
                if (deg_can[i][d]) {
                    deg_can[i+1][d] = true;
                    deg_can[i+1][(d+degs[i]+360)%360] = true;
                }
            }
        }
        
        int offset = 0;
        while (!deg_can[degs.size()][180-offset] && !deg_can[degs.size()][180+offset]) {
            ++offset;
        }
        
        if (offset==0 || F==0 || B==0) {
            return F + B;
        }
        return sqrt(double(F)*F + double(B)*B - 2*double(F)*B*cos(double(180-offset)/180*acos(-1.0)));
    }
};
