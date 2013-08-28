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

int G[50][50];
const int inf = 12345678;
class ColorfulWolves {
public:
    int getmin(vector <string> colormap) {
        int n = colormap.size();
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            for (int j=0; j<n; ++j) {
                G[i][j] = (colormap[i][j]=='Y' ? cnt++ : inf);
            }
        }

        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
                }
            }
        }

        return G[0][n-1]==inf ? -1 : G[0][n-1];
    }
};
