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

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
string dir = "NESW";

int D[50];
bool dead[50];
class AntsMeet {
public:
    int countAnts(vector <int> x, vector <int> y, string direction) {
        int n = x.size();
        for (int i=0; i<(int)direction.size(); ++i) {
            D[i] = dir.find(direction[i]);
        }
        for (int i=0; i<n; ++i) {
            x[i] *= 2;
            y[i] *= 2;
        }
        memset(dead, 0, sizeof dead);
        for (int iter=0; iter<10000; ++iter) {
            for (int i=0; i<n; ++i) {
                if (!dead[i]) {
                    x[i] += dx[D[i]];
                    y[i] += dy[D[i]];
                }
            }
            for (int i=0; i<n; ++i) {
                if (dead[i]) continue;
                for (int j=i+1; j<n; ++j) {
                    if (dead[j]) continue;
                    if (x[i]==x[j] && y[i]==y[j]) {
                        dead[i] = dead[j] = 1;
                    }
                }
            }
        }
        
        int sol = 0;
        for (int i=0; i<n; ++i) {
            if (!dead[i]) {
                ++sol;
            }
        }
        return sol;
    }
};
