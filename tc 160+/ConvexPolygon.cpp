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

template<typename T>
class Point {
    public:
    T x, y;
    Point(T x_, T y_): x(x_), y(y_) {}
    Point(const Point<T> &P): x(P.x), y(P.y) {}
};

template<typename T>
bool operator<(const Point<T> &a, const Point<T> &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

template<typename T>
const Point<T> operator-(const Point<T> &a, const Point<T> &b) {
    return Point<T>(a.x-b.x, a.y-b.y);
}

template<typename T>
inline long long cross(const Point<T> &a, const Point<T> &b) {
    return (long long)a.x*b.y - (long long)a.y*b.x;
}

template<typename T>
inline long long dot(const Point<T> &a, const Point<T> &b) {
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

template<typename T>
inline int ccw(const Point<T> &a, const Point<T> &b) {
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

template<typename T>
inline long long dist2(const Point<T> &a, const Point<T> &b) {
    /*
     * Returns the squared distance between 'a' and 'b'.
     * Does not check for overflow!
     */
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}

template<typename T>
class PointCmp {
    private:
    Point<T> origin;
    public:
    PointCmp<T>(const Point<T> &origin_): origin(origin_) {}

    bool operator()(const Point<T> &a, const Point<T> &b) {
        int dir = ccw(a-origin, b-origin);
        if (dir == 0) {
            return dist2(a, origin) < dist2(b, origin);
        } else {
            return (dir == 1);
        }
    }
};

template<typename T>
class Polygon {
    public:
    Polygon() {}
    Polygon(const Polygon<T> &P): points(P.get_points()) {}

    int size() const { return (int)points.size(); }
    void add(const Point<T> &p) { points.push_back(p); }
    void pop() { points.pop_back(); }
    void remove(int i) { points.erase(points.begin() + i); }
    void reserve(int size) { points.reserve(size); }
    void clear() { points.clear(); }
    void swap(Polygon<T> &other) { points.swap(other.get_points()); }
    vector< Point<T> >& get_points() { return points; }
    const vector< Point<T> >& get_points() const { return points; }
    Point<T>& operator[](int i) { return points[i]; }
    const Point<T>& operator[](int i) const { return points[i]; }

    double area(bool order_set) const;
    Polygon<T> jarvis_march(bool take_colinear, int size_guess) const; // O(nh)
    Polygon<T> graham_scan(bool take_colinear) const;

    private:
    vector< Point<T> > points;
};

template<typename T>
double Polygon<T>::area(bool order_set=true) const {
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

    const Polygon<T> &P = *this;
    vector< Point<T> > v(P.get_points());
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
        sort(v.begin()+1, v.end(), PointCmp<int>(v[0]));
    }

    double ret = cross(v[0], v.back());
    for (int i=1; i<size(); ++i) {
        ret += cross(v[i], v[i-1]);
    }

    return 0.5 * fabs(ret);
}

template<typename T>
Polygon<T> Polygon<T>::jarvis_march(bool take_colinear=false, int size_guess=0) const {
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
        return Polygon<T>(*this);
    }

    const Polygon<T> &P = *this;
    // find index of first point
    int p = 0; 
    for (int i=1; i<size(); ++i) {
        if (P[i] < P[p]) {
            p = i;
        }
    }

    Polygon<T> convex_hull;
    if (size_guess) {
        convex_hull.reserve(size_guess);
    }
    convex_hull.add(points[p]);
    int q = p;
    vector<bool> used(size(), false);
    // important not to set used[p] since then the loop won't terminate
    do {
        int next = -1; // current next point
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
                            if (take_colinear && d2_cand<=d2_next || !take_colinear && d2_cand>d2_next) {
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

        assert(next != -1);
        used[next] = true;
        convex_hull.add(P[q = next]);
    } while (q != p); // repeat this until we end up with the starting point
    convex_hull.pop(); // remove the repeated starting point
    return convex_hull;
}

class ConvexPolygon {
	public:
	double findArea(vector <int> x, vector <int> y) {
		Polygon<int> P;
        for (int i=0; i<(int)x.size(); ++i) {
            P.add(Point<int>(x[i], y[i]));
        }

        return P.area();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(0, Arg2, findArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-10000,-10000,10000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000,-10000,-10000,10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.0E8; verify_case(1, Arg2, findArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100,80,30,-30,-80,-100,-80,-30,30,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,58,95,95,58,0,-58,-95,-95,-58}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 29020.0; verify_case(2, Arg2, findArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1646,-9172,-9830,-9802,-9749,-9474,-8668,-6832,120,8380,9338,9307,8042}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-9998,-8619,-7863,3976,4541,5975,8127,9500,9612,8734,5216,-9042,-9689}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.55115104E8; verify_case(3, Arg2, findArea(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-6010,-7937,-8782,-9506,-9654,-9852,-9854,-9998,-9999,-9996,-9901,-9811,
-9444,-8798,-8580,-2085,6842,8339,9827,9946,9993,9959,9940,9855,9657,
8504,8262,7552,6326,5537,4723}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-9976,-9947,-9873,-9739,-9654,-8501,-8475,-5009,475,4926,7078,8673,9417,
9785,9820,9974,9986,9979,9862,9211,-5070,-6599,-7121,-8624,-8912,-9710,
-9766,-9863,-9914,-9941,-9962}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.939960635E8; verify_case(4, Arg2, findArea(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ConvexPolygon ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
