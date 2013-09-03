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
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <bitset>

using namespace std;

struct point {
    long long x, y;
};
vector<long long> parse(vector<string> &x) {
    string s = accumulate(x.begin(), x.end(), string());
    istringstream is(s);
    vector<long long> ret;
    copy(istream_iterator<long long>(is), istream_iterator<long long>(), back_inserter(ret));
    return ret;
}
vector<point> parse(vector<string> &x, vector<string> &y) {
    vector<long long> xx = parse(x);
    vector<long long> yy = parse(y);
    vector<point> ret;
    for (int i=0; i<(int)xx.size(); ++i) {
        ret.push_back((point){xx[i], yy[i]});
    }
    return ret;
}

inline point operator-(point &a, point &b) {
    return (point){a.x-b.x, a.y-b.y};
}
long long cross(const point &a, const point &b) {
    return a.x*b.y - a.y*b.x;
}
bool ccw(point &c, point &a, point &b) {
    return cross(b-a, c-a) > 0;
}
typedef bitset<222> Bset;
class CheckerFreeness {
public:
    string isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY) {
        vector<point> W = parse(whiteX, whiteY);
        vector<point> B = parse(blackX, blackY);
        for (int iteration=0; iteration<2; ++iteration) {
            vector<vector<Bset> > ww(W.size(), vector<Bset>(W.size()));
            vector<vector<Bset> > wb(W.size(), vector<Bset>(B.size()));
            for (int i=0; i<(int)W.size(); ++i) {
                for (int j=i+1; j<(int)W.size(); ++j) {
                    for (int k=0; k<(int)B.size(); ++k) {
                        if (ccw(B[k], W[i], W[j])) {
                            ww[i][j][k] = 1;
                        }
                    }
                }
                for (int j=0; j<(int)B.size(); ++j) {
                    for (int k=0; k<(int)B.size(); ++k) {
                        if (k == j) continue;
                        if (ccw(B[k], W[i], B[j])) {
                            wb[i][j][k] = 1;
                        }
                    }
                }
            }
            for (int i=0; i<(int)W.size(); ++i) {
                for (int j=i+1; j<(int)W.size(); ++j) {
                    for (int k=0; k<(int)B.size(); ++k) {
                        if (ww[i][j][k]) {
                            if ((~ww[i][j]&~wb[i][k]&wb[j][k]).any()) {
                                return "NO";
                            }
                        } else {
                            if ((ww[i][j]&wb[i][k]&~wb[j][k]).any()) {
                                return "NO";
                            }
                        }
                    }
                }
            }
            W.swap(B);
        }
        return "YES";
    }
};
