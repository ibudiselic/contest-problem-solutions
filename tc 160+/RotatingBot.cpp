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
#include <utility>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
typedef pair<int, int> point;
class RotatingBot {
public:
    int minArea(vector <int> moves) {
        set<int> X, Y;
        set<point> P;
        int dir = 1;
        point at(0, 0);
        P.insert(at);
        X.insert(0);
        Y.insert(0);
        for (int i=0; i<(int)moves.size(); ++i) {
            for (int j=0; j<moves[i]; ++j) {
                at.first += di[dir];
                at.second += dj[dir];
                if (!P.insert(at).second) {
                    return -1;
                }
                X.insert(at.first);
                Y.insert(at.second);
            }
            dir = (dir+3)%4;
        }

        int x0 = *X.begin();
        int x1 = *X.rbegin();
        int y0 = *Y.begin();
        int y1 = *Y.rbegin();
        at.first = at.second = 0;
        dir = 1;
        P.clear();
        P.insert(at);
        for (int k=0; k<(int)moves.size(); ++k) {
            int steps = 0;
            while (1) {
                at.first += di[dir];
                at.second += dj[dir];
                if (at.first<x0 || at.first>x1 || at.second<y0 || at.second>y1 || !P.insert(at).second) {
                    at.first -= di[dir];
                    at.second -= dj[dir];
                    if (steps == 0) {
                        return -1;
                    }
                    if (k+1<(int)moves.size() && moves[k]!=steps) {
                        return -1;
                    }
                    if (k+1==(int)moves.size() && moves[k]>steps) {
                        return -1;
                    }
                    break;
                }
                ++steps;
            }
            dir = (dir+3)%4;
        }

        return (x1-x0+1)*(y1-y0+1);
    }
};
