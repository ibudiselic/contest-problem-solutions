//# implementation, shortest paths
//# => trivial
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int D[50][50];
class TravelOnMars {
public:
    int minTimes(vector <int> range, int S, int E) {
        int n = range.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                D[i][j] = 123456;
            }
        }
        for (int i=0; i<n; ++i) {
            D[i][i] = 0;
            for (int d=1; d<=range[i]; ++d) {
                D[i][(i-d+100*n)%n] = 1;
                D[i][(i+d)%n] = 1;
            }
        }
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
        return D[S][E];
    }
};
