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
#include <set>

using namespace std;

inline bool inside(int x, int y, const vector<int> &R) {
    return R[0]<=x && x<=R[2] && R[1]<=y && y<=R[3];
}
class TwoRectangles {
public:
    string describeIntersection(vector <int> A, vector <int> B) {
        set<int> X, Y;
        for (int i=A[0]; i<=A[2]; ++i) {
            for (int j=A[1]; j<=A[3]; ++j) {
                if (inside(i, j, B)) {
                    X.insert(i);
                    Y.insert(j);
                }
            }
        }
        if (X.size() == 0) {
            return "none";
        }
        if (X.size()>1 && Y.size()>1) {
            return "rectangle";
        }
        if (X.size()==1 && Y.size()==1) {
            return "point";
        }
        return "segment";
    }
};
