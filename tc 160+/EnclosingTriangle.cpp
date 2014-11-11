//# triangle, geometry, ccw
//# => For each point, precompute two 'boundary' points such that the vectors to those points enclose all the black points. This precomputation makes it possible to compute the answers for each point in O(n) time where n is the number of points on the border. During the analysis, a key problem arises of storing a sequence of partial solutions that can all be modified via subtraction of some constant and can be queried for the sum of all numbers. This can be done with a modified queue which is the central idea of the problem (see code/editorial for details).
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

const int MAXN = 240000;
int S[2*MAXN], E[2*MAXN];
int n;
struct point {
    int x, y;
};
point operator-(const point &a, const point &b) {
    return {a.x-b.x, a.y-b.y};
}
vector<point> square;
vector<point> blacks;

long long cross(const point &a, const point &b) {
    return (long long)a.x*b.y - (long long)a.y*b.x;
}
bool all_right(int a, int b) {
    point l = square[b] - square[a];
    for (int i=0; i<(int)blacks.size(); ++i) {
        if (cross(l, blacks[i]-square[a]) > 0) {
            return false;
        }
    }
    return true;
}
bool all_left(int a, int b) {
    point l = square[b] - square[a];
    for (int i=0; i<(int)blacks.size(); ++i) {
        if (cross(l, blacks[i]-square[a]) < 0) {
            return false;
        }
    }
    return true;
}

struct Item {
    int key;
    long long val;
};
Item SubQueue_items[2*MAXN];
struct SubQueue {
    int head, tail;
    long long sum, subval;
    SubQueue(): head(0), tail(0), sum(0), subval(0) {}
    void enq(int key, long long val) {
        SubQueue_items[tail].key = key;
        SubQueue_items[tail++].val = val + subval;
        sum += val;
    }
    void deq(int key) {
        while (head<tail && SubQueue_items[head].key<=key) {
            sum -= SubQueue_items[head].val - subval;
            ++head;
        }
    }
    int size() const {
        return tail-head;
    }
    void sub(long long val) {
        sum -= size()*val;
        subval += val;
        while (head<tail && SubQueue_items[head].val-subval <= 0) {
            sum -= SubQueue_items[head].val - subval;
            ++head;
        }
    }
};
class EnclosingTriangle {
public:
    long long getNumber(int side, vector <int> x, vector <int> y) {
        square.clear();
        blacks.clear();

        n = 4*side;
        for (int i=0; i<=side; ++i) {
            square.push_back({0, i});
        }
        for (int i=1; i<=side; ++i) {
            square.push_back({i, side});
        }
        for (int i=1; i<=side; ++i) {
            square.push_back({side, side-i});
        }
        for (int i=1; i<side; ++i) {
            square.push_back({side-i, 0});
        }
        assert(int(square.size()) == n);
        for (int i=0; i<n; ++i) {
            square.push_back(square[i]);
        }

        for (int i=0; i<(int)x.size(); ++i) {
            blacks.push_back({x[i], y[i]});
        }

        int b = 0;
        for (int a=0; a<n; ++a) {
            ++b;
            while (all_right(a, b)) {
                ++b;
            }
            --b;
            S[a] = b;
        }
        int c = n-1;
        while (all_left(0, c)) {
            --c;
        }
        ++c;
        E[0] = c;
        for (int a=1; a<n; ++a) {
            while (!all_left(a, c)) {
                ++c;
            }
            E[a] = c;
        }

        long long sol = 0;
        SubQueue SQ;
        for (b=1; b<=S[0]; ++b) {
            long long val = min(n-1, S[b])-E[0]+1;
            if (val <= 0) continue;
            SQ.enq(b, val);
            sol += val - (b==E[0]);
        }
        for (int a=1; a<n && E[a]<n; ++a) {
            SQ.deq(a);
            SQ.sub((E[a]-E[a-1]+n)%n);
            sol += SQ.sum;
            for (; b <= S[a]; ++b) {
                long long val = min(n-1, S[b])-E[a]+1;
                if (val <= 0) continue;
                SQ.enq(b, val);
                sol += val - (b==E[a]);
            }
        }

        return sol;
    }
};
