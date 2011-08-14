#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef int poly_type_; // expected int, long or long long
class Point {
    public:
    poly_type_ x, y;
    Point(poly_type_ x_, poly_type_ y_): x(x_), y(y_) {}
    Point(const Point &P): x(P.x), y(P.y) {}
};

bool operator<(const Point &a, const Point &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

const Point operator-(const Point &a, const Point &b) {
    return Point(a.x-b.x, a.y-b.y);
}

inline long long cross(const Point &a, const Point &b) {
    return (long long)a.x*b.y - (long long)a.y*b.x;
}

inline long long dot(const Point &a, const Point &b) {
    return (long long)a.x*b.x + (long long)a.y*b.y;
}     

inline int sgn0(long long x) {
    /*
     * Returns:
     * -1 if x<0
     * 0 if x==0
     * 1 if x>0
     */
    return (x==0 ? 0 : (x>0 ? 1 : -1));
}

inline int ccw(const Point &a, const Point &b) {
    /*
     * Returns the direction of the origin vector with endpoint 'a' 
     * with respect to the origin vector with endpoint 'b'.
     * -1 if clockwise
     * 0 if colinear
     * 1 if counterclockwise
     */
    return sgn0(cross(a, b));
}

inline long long sqr(long long x) {
    /*
     * Returns the square of 'x'.
     * Does not check for overflow!
     */
    return x*x;
}

inline long long dist2(const Point &a, const Point &b) {
    /*
     * Returns the squared distance between 'a' and 'b'.
     * Does not check for overflow!
     */
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}

class PointCmp {
    private:
    Point origin;
    public:
    PointCmp(const Point &origin_): origin(origin_) {}

    bool operator()(const Point &a, const Point &b) {
        int dir = ccw(a-origin, b-origin);
        if (dir == 0) {
            return dist2(a, origin) < dist2(b, origin);
        } else {
            return (dir == 1);
        }
    }
};

class Polygon {
    public:
    Polygon() {}
    Polygon(const Polygon &P): points(P.get_points()) {}

    int size() const { return (int)points.size(); }
    void add(const Point &p) { points.push_back(p); }
    void pop() { points.pop_back(); }
    Point& back() { return points.back(); }
    const Point &back() const { return points.back(); }
    void remove(int i) { points.erase(points.begin() + i); }
    void reserve(int size) { points.reserve(size); }
    void clear() { points.clear(); }
    void swap(Polygon &other) { points.swap(other.get_points()); }
    vector< Point >& get_points() { return points; }
    const vector< Point >& get_points() const { return points; }
    Point& operator[](int i) { return points[i]; }
    const Point& operator[](int i) const { return points[i]; }

    double area(bool order_set) const;
    Polygon jarvis_march(bool take_colinear, int size_guess) const; // O(nh)
    Polygon grahams_scan(bool take_colinear, int size_guess) const; // O(n log n)

    private:
    vector<Point> points;
};

double Polygon::area(bool order_set=true) const {
    /*
     * Returns the area of the polygon as a double.
     *
     * If 'order_set' is set, the points are assumed to be in either 
     * clockwise or counter clockwise order and are not sorted.
     */
    // degenerate case
    if (size() < 3) {
        return 0.0;
    }

    const Polygon &P = *this;
    vector< Point > v(P.get_points());
    if (!order_set) {
        int p = 0;
        for (int i=1; i<(int)v.size(); ++i) {
            if (v[i] < v[p]) {
                p = i;
            }
        }
        if (p != 0) {
            std::swap(v[0], v[p]);
        }
        sort(v.begin()+1, v.end(), PointCmp(v[0]));
    }

    double ret = cross(v[0], v.back());
    for (int i=1; i<size(); ++i) {
        ret += cross(v[i], v[i-1]);
    }

    return 0.5 * fabs(ret);
}

Polygon Polygon::jarvis_march(bool take_colinear=false, int size_guess=0) const {
    /* 
     * Returns the polygon representing the convex hull of the given polygon.
     * If 'take_colinear' is set, the returned hull will return colinear points
     * on boundaries.
     *
     * 'size_guess' (if set to a positive value) is used to reserve space for the 
     * convex hull to potentially make fewer reallocations.
     *
     * Duplicate points are allowed and are included multiple times in the 
     * convex hull if 'take_colinear' is set.
     *
     * Degenerate polygons (less then 3 points) are returned as the convex hull 
     * although the convex hull is not well defined in that case.
     *
     * Complexity: O(nh) where n is the number of points in the polygon and 
     * h is the number of points in the convex hull.
     */
    // check degenerate case
    if (size() < 3) {
        return Polygon(*this);
    }

    const Polygon &P = *this;
    // find index of first point
    int p = 0; 
    for (int i=1; i<size(); ++i) {
        if (P[i] < P[p]) {
            p = i;
        }
    }

    Polygon convex_hull;
    if (size_guess) {
        convex_hull.reserve(size_guess);
    }
    convex_hull.add(points[p]);
    int q = p;
    vector<bool> used(size(), false);
    // important not to set used[p] since then the loop won't terminate
    do {
        int next = -1; // current next point
        bool can_take_p = false; // special case for duplicate points
        for (int cand=0; cand<size(); ++cand) { // new candidate
            if (cand!=q && !used[cand]) { // could potentially take duplicate points and get stuck if take_colinear is set otherwise
                bool found = (next == -1); // found new point if the current next point is not set
                if (!found) {
                    const int direction = ccw(P[next]-P[q], P[cand]-P[q]);
                    if (direction == -1) { // or if next is clockwise to cand relative to q 
                        found = true;
                    } else if (direction == 0) { // or if next, cand and q are colinear
                        const long long D = dot(P[next]-P[q], P[cand]-P[q]);
                        if (D>=0 || q==p) {
                            const long long d2_next = dist2(P[next], P[q]);
                            const long long d2_cand = dist2(P[cand], P[q]);
                            if (take_colinear && d2_cand<=d2_next) {
                                if (cand == p) {
                                    can_take_p = true; // try not to take p if it's not the only option
                                } else {
                                    found = true;
                                }
                            } else if (!take_colinear && d2_cand>d2_next) {
                                found = true;
                            }
                        } else {
                            assert(q != p); // at least 2 points in the hull
                            assert(convex_hull.size() > 1u);
                            // take the point that's in the direction of the hull
                            if (dot(P[q]-convex_hull[convex_hull.size()-2], P[cand]-P[q]) > 0) {
                                found = true;
                            }
                        }
                    }
                }
                if (found) {
                    next = cand;
                }
            }
        }

        assert(next!=-1 || can_take_p);
        if (next == -1) {
            next = p;
        }
        used[next] = true;
        convex_hull.add(P[q = next]);
    } while (q != p); // repeat this until we end up with the starting point
    convex_hull.pop(); // remove the repeated starting point
    return convex_hull;
}

Polygon Polygon::grahams_scan(bool take_colinear=false, int size_guess=0) const {
     /* 
     * Returns the polygon representing the convex hull of the given polygon.
     * If 'take_colinear' is set, the returned hull will return colinear points
     * on boundaries.
     *
     * 'size_guess' (if set to a positive value) is used to reserve space for the 
     * convex hull to potentially make fewer reallocations.
     *
     * Duplicate points are allowed and are included multiple times in the 
     * convex hull if 'take_colinear' is set.
     *
     * Degenerate polygons (less then 3 points) are returned as the convex hull 
     * although the convex hull is not well defined in that case.
     *
     * Complexity: O(n log n) where n is the number of points in the polygon.
     */
    // check degenerate case
    if (size() < 3) {
        return Polygon(*this);
    }

    vector<Point> v(get_points());
    sort(v.begin(), v.end());

    Polygon convex_hull;
    if (size_guess) {
        convex_hull.reserve(size_guess);
    }
    for (int t=0; t<2; ++t) {
        for (int i=0; i<(int)v.size(); ++i) {
            while (convex_hull.size() >= 2) {
                const int dir = ccw(convex_hull.back()-convex_hull[convex_hull.size()-2], v[i]-convex_hull[convex_hull.size()-2]);
                if (dir==1 || dir==0 && !take_colinear) {
                    convex_hull.pop();
                } else {
                    break;
                }
            }
            convex_hull.add(v[i]);
        }
        convex_hull.pop();
        if (!t) {
            reverse(v.begin(), v.end());
        }
    }
    return convex_hull;
}


inline long long my_abs(long long x) {
    return x>0 ? x : -x;
}
int area2(const Point &a, const Point &b, const Point &c) {
    // Returns twice the area of the triangle formed by a, b and c
    return my_abs(cross(b-a, c-a));
}
class ExtendableTriangles {
	public:
	int getCount(vector <string> A) {
        int m = A.size();
        int n = A[0].size();
        Polygon R, G, B;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                (A[i][j]=='R' ? R : (A[i][j]=='G' ? G : B)).add(Point(i, j));
            }
        }

        long long total = (long long)R.size() * G.size() * B.size();
        R = R.grahams_scan(true, 500);
        G = G.grahams_scan(true, 500);
        B = B.grahams_scan(true, 500);
        vector< vector<int> > max_area_rg(R.size(), vector<int>(G.size()));
        vector< vector<int> > max_area_rb(R.size(), vector<int>(B.size()));
        vector< vector<int> > max_area_gb(G.size(), vector<int>(B.size()));
        for (int r=0; r<(int)R.size(); ++r) {
            for (int g=0; g<(int)G.size(); ++g) {
                for (int b=0; b<(int)B.size(); ++b) {
                    int a = area2(R[r], G[g], B[b]);
                    max_area_rg[r][g] = max(max_area_rg[r][g], a);
                    max_area_rb[r][b] = max(max_area_rb[r][b], a);
                    max_area_gb[g][b] = max(max_area_gb[g][b], a);
                }
            }
        }
        
        for (int r=0; r<(int)R.size(); ++r) {
            for (int g=0; g<(int)G.size(); ++g) {
                for (int b=0; b<(int)B.size(); ++b) {
                    int a = area2(R[r], G[g], B[b]);
                    if (a==max_area_rg[r][g] && a==max_area_rb[r][b] && a==max_area_gb[g][b]) {
                        --total;
                    }
                }
            }
        }

        return (int)total;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RGB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"RGB",
 "RGB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"RRRRRRRR",
 "GGGGBBBB",
 "RRRRRRRR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 240; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"RBRBRBRB",
 "BRBRBRBR",
 "RBRBRBRB",
 "BRBRBRBR",
 "RRRRRRRR",
 "BBBBBBBB",
 "RRRRBBBB",
 "BBBBRRRR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { string Arr0[] = {"RGB",
 "RBG",
 "GRB",
 "GBR",
 "BRG",
 "BGR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 208; verify_case(4, Arg1, getCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ExtendableTriangles ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
