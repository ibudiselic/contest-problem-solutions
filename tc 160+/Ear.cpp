#include <algorithm>
#include <cassert>
#include <cctype>
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

using namespace std;

struct point {
    int x, y;
};
point operator-(const point &a, const point &b) {
    return (point){a.x-b.x, a.y-b.y};
}
long long cross(const point &a, const point &b) {
    return (long long)a.x*b.y - (long long)a.y*b.x;
}

struct PointCmp {
    point P;
    PointCmp(const point &P): P(P) {}
    bool operator()(const point &a, const point &b) {
        return cross(a-P, b-P) > 0;
    }
};

vector<int> parse(vector<string> &v) {
    vector<int> ret;
    string s = accumulate(v.begin(), v.end(), string());
    istringstream is(s);
    copy(istream_iterator<int>(is), istream_iterator<int>(), back_inserter(ret));
    return ret;
}
class Ear {
public:
    long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
        vector<int> rX = parse(redX);
        vector<int> bX = parse(blueX);
        vector<int> bY = parse(blueY);

        int nR = rX.size();
        sort(rX.begin(), rX.end());
        vector<point> red(nR);
        for (int i=0; i<nR; ++i) {
            red[i].x = rX[i];
            red[i].y = 0;
        }

        int nB = bX.size();
        vector<point> blue(nB);
        for (int i=0; i<nB; ++i) {
            blue[i].x = bX[i];
            blue[i].y = bY[i];
        }
        
        long long sol = 0;
        for (int p=0; p<nB; ++p) {
            const point P = blue[p];
            PointCmp cmp(P);
            vector<point> qcands;
            for (int i=0; i<nB; ++i) {
                if (blue[i].y<P.y && rX[0]<blue[i].x && blue[i].x<rX.back()) {
                    qcands.push_back(blue[i]);
                }
            }
            sort(qcands.begin(), qcands.end(), cmp);
            int qs_start = 0;
            for (int a=0; a+3<nR; ++a) {
                const point A = red[a];
                if (A.x >= P.x) {
                    break;
                }
                while (qs_start<(int)qcands.size() && cmp(qcands[qs_start], A)) {
                    ++qs_start;
                }
                while (qs_start<(int)qcands.size() && cross(A-P, qcands[qs_start]-P)==0) {
                    ++qs_start;
                }
                if (qs_start == (int)qcands.size()) {
                    break;
                }

                long long BQ_uniq = 0;
                long long total = 0;
                int qs_next = qs_start;
                vector<int> BQ_uniq_future(nR);
                for (int d=a+1; d<nR; ++d) {
                    const point D = red[d];
                    if (D.x > P.x) {
                        sol += total; // every old triangle works again
                    }
                    while (qs_next<(int)qcands.size() && cmp(qcands[qs_next], D)) {
                        const point Q = qcands[qs_next++];
                        vector<int>::iterator it = lower_bound(rX.begin(), rX.end(), Q.x);
                        assert(it != rX.end());
                        int pos = it - rX.begin();
                        if (pos >= d) {
                            int sub_one = 0;
                            if (Q.x == rX[pos]) {
                                sub_one = 1;
                                ++pos;
                            }
                            assert(pos < nR);
                            int add = pos - a - 1 - sub_one;
                            assert(add >= 0);
                            BQ_uniq_future[pos] += add;
                            pos = d;
                        } else {
                            assert(pos > a);
                            int one_eq = 0;
                            if (Q.x == rX[pos]) {
                                one_eq = 1;
                            }
                            long long bcands = pos-a-1;
                            assert(bcands >= 0);
                            BQ_uniq += bcands;
                            long long ccands = d-pos-one_eq;
                            assert(ccands >= 0);
                            total += bcands*ccands;
                            if (D.x > P.x) {
                                sol += bcands*ccands;
                            }
                        }
                    }
                    BQ_uniq += BQ_uniq_future[d];
                    total += BQ_uniq; // we can use this D in the next step as C
                }
            }
        }
        return sol;
    }
};
