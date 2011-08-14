#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

struct dPoint {
    double x, y;
    dPoint(double x_=0, double y_=0): x(x_), y(y_) {}
};
struct Point {
    int x, y;
    Point(int x_=0, int y_=0): x(x_), y(y_) {}
};
bool operator==(const Point &a, const Point &b) {
    return a.x==b.x && a.y==b.y;
}

ostream& operator<<(ostream& os, const Point &a) {
    os << '(' << a.x << ", " << a.y << ')';
    return os;
}
ostream& operator<<(ostream& os, const dPoint &a) {
    os << '(' << a.x << ", " << a.y << ')';
    return os;
}

double dist2(const dPoint &a, const dPoint &b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
int dist2(const Point &a, const Point &b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
double dist(const dPoint &a, const dPoint &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double dist(const Point &a, const Point &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double dist(const Point &a, const dPoint &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void sort_down(int &a, int &b, int &c) {
    // a>=b>=c
    if (a < b) {
        swap(a, b);
    }
    if (a < c) {
        swap(a, c);
    }
    if (b < c) {
        swap(b, c);
    }
    assert(a >= b);
    assert(b >= c);
}

/* Stable Heron's formula */
void sort_down(double &a, double &b, double &c) {
    // a>=b>=c
    if (a < b) {
        swap(a, b);
    }
    if (a < c) {
        swap(a, c);
    }
    if (b < c) {
        swap(b, c);
    }
    assert(a >= b);
    assert(b >= c);
}
double area(double a, double b, double c) {
    sort_down(a, b, c);
    return sqrt((a + (b+c)) * (c - (a-b)) * (c + (a-b)) * (a + (b-c))) / 4.0;
}
double area2(double a, double b, double c) {
    sort_down(a, b, c);
    return (a + (b+c)) * (c - (a-b)) * (c + (a-b)) * (a + (b-c)) / 16.0;
}

const double EPS = 1e-9;
struct Circle {
    int radius;
    dPoint center;
    Circle(const dPoint &center_, int radius_): radius(radius_), center(center_) {}
    
    // construct a circle with points a and b on its edge
    // lower determines if the lower x or higher x center is chosen (two solutions)
    // if x for both centers is equal, applies to y
    Circle(const Point &a, const Point &b, int radius_, bool lower) {
        radius = radius_;
        if (a==b || 4*radius*radius+EPS<dist2(a, b)) {
            radius = -1;
            return;
        }
        const double d = dist(a, b);
        if (a.x == b.x) { // c.y = (a.y+b.y)/2
            const dPoint m(a.x, double(a.y+b.y)/2.0);
            // get c.x from dist(a, c)
            const double u = (m.y-a.y) * (m.y-a.y) - radius*radius;
            const double A = 1;
            const double B = -2*a.x;
            const double C = u + a.x*a.x;
            const double D = B*B - 4*A*C;
            if (D < 0.0) {
                radius = -1;
                return;
            }
            
            center.y = m.y;
            int sgn = (lower ? -1 : +1);
            center.x = (-B + sgn*sqrt(D))/2/A;
        } else if (a.y == b.y) { // c.x = (a.x+b.x)/2
            const dPoint m(double(a.x+b.x)/2.0, a.y);
            // get c.y from dist(a, c)
            const double u = (m.x-a.x) * (m.x-a.x) - radius*radius;
            const double A = 1;
            const double B = -2*a.y;
            const double C = u + a.y*a.y;
            const double D = B*B - 4*A*C;
            if (D < 0.0) {
                radius = -1;
                return;
            }
            
            center.x = m.x;
            int sgn = (lower ? -1 : +1);
            center.y = (-B + sgn*sqrt(D))/2/A;
        } else {
            const double Kab = double(a.y-b.y) / (a.x-b.x);
            const double Km = -1.0/Kab;
            const dPoint m(double(a.x+b.x)/2.0, double(a.y+b.y)/2.0);
            const double A2 = area2(radius, radius, d);
            const double dc2 = 4*A2 / d / d;
            const double u = -Km * m.x;
            
            const double A = 1 + Km*Km;
            const double B = 2*(Km*u - m.x);
            const double C = m.x*m.x + u*u - dc2;
            const double D = B*B - 4*A*C;
            if (D < 0.0) {
                radius = -1;
                return;
            }
            
            int sgn = (lower ? -1 : +1);
            center.x = (-B + sgn*sqrt(D))/2/A;
            center.y = Km * center.x + m.y - Km * m.x;
        }
    }
    bool is_valid() const { return radius > 0; }
    double bottom() const { return center.y - radius; };
    double top() const { return center.y + radius; };
    bool is_inside(const Point &a) const { return dist(a, center) <= radius+EPS; }
};

struct State {
    int i, j, k;
    State(int i_, int j_, int k_): i(i_), j(j_), k(k_) {}
};
bool done[17][17][17];

int R;
bool ok(const Point &a, const Point &b, const Point &c) {
    for (int lower=0; lower<2; ++lower) {
        {
            const Circle C(a, b, R, lower);
            if (C.is_valid() && C.bottom()<EPS && C.is_inside(c)) {
                return true;
            }
        }
        {
            const Circle C(a, c, R, lower);
            if (C.is_valid() && C.bottom()<EPS && C.is_inside(b)) {
                return true;
            }
        }
        {
            const Circle C(b, c, R, lower);
            if (C.is_valid() && C.bottom()<EPS && C.is_inside(a)) {
                return true;
            }
        }
        {
            const Circle C(a, Point(a.x, 0), R, lower);
            if (C.is_valid() && C.is_inside(b) && C.is_inside(c)) {
                return true;
            }
        }
        {
            const Circle C(b, Point(b.x, 0), R, lower);
            if (C.is_valid() && C.is_inside(a) && C.is_inside(c)) {
                return true;
            }
        }
        {
            const Circle C(c, Point(c.x, 0), R, lower);
            if (C.is_valid() && C.is_inside(a) && C.is_inside(b)) {
                return true;
            }
        }
    }
    
    return false;
}
bool ok(const Point &a, const Point &b, const Point &c, const Point &d) {
    for (int lower=0; lower<2; ++lower) {
        const Circle C(a, b, R, lower);
        if (C.is_valid() && C.is_inside(c) && C.is_inside(d)) {
            return true;
        }
    }
    return false;
}
double calc(const Point &a, const Point &b, const Point &c) {
    double max_top = -1.0;
    for (int lower=0; lower<2; ++lower) {
        {
            const Circle C(a, b, R, lower);
            if (C.is_valid() && C.is_inside(c)) {
                max_top = max(max_top, C.top());
            }
        }
        {
            const Circle C(a, c, R, lower);
            if (C.is_valid() && C.is_inside(b)) {
                max_top = max(max_top, C.top());
            }
        }
        {
            const Circle C(c, b, R, lower);
            if (C.is_valid() && C.is_inside(a)) {
                max_top = max(max_top, C.top());
            }
        }
    }
    {
        const Circle C(a, Point(a.x, a.y+2*R), R, 0);
        if (C.is_valid() && C.is_inside(b) && C.is_inside(c)) {
            max_top = max(max_top, C.top());
        }
    }
    {
        const Circle C(b, Point(b.x, b.y+2*R), R, 0);
        if (C.is_valid() && C.is_inside(a) && C.is_inside(c)) {
            max_top = max(max_top, C.top());
        }
    }
    {
        const Circle C(c, Point(c.x, c.y+2*R), R, 0);
        if (C.is_valid() && C.is_inside(a) && C.is_inside(b)) {
            max_top = max(max_top, C.top());
        }
    }
    return max_top;
}

class WallClimbing {
	public:
	double maxHeight(vector <int> holdx, vector <int> holdy, int armLength) {
		const int n = holdx.size();
        R = armLength;
        memset(done, 0, sizeof done);
        double sol = 2*R;
        queue<State> Q;
        vector<Point> P;
        P.reserve(holdx.size());
        for (int i=0; i<(int)holdx.size(); ++i) {
            P.push_back(Point(holdx[i], holdy[i]));
        }
        
        for (int i=0; i<n-2; ++i) {
            if (holdy[i] <= 2*R) {
                for (int j=i+1; j<n-1; ++j) {
                    for (int k=j+1; k<n; ++k) {
                        if (!done[i][j][k] && ok(P[i], P[j], P[k])) {
                            done[i][j][k] = 1;
                            Q.push(State(i, j, k));
                        }
                    }
                }
            }
        }
        
        while (!Q.empty()) {
            int i = Q.front().i;
            int j = Q.front().j;
            int k = Q.front().k;
            Q.pop();
            sol = max(sol, calc(P[i], P[j], P[k]));
            for (int l=0; l<n; ++l) {
                if (l!=i && l!=j && l!=k) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    v.push_back(l);
                    sort(v.begin(), v.end());
                    for (int a=0; a<3; ++a) {
                        for (int b=a+1; b<4; ++b) {
                            int c = 0;
                            while (c==a || c==b) {
                                ++c;
                            }
                            int d = c + 1;
                            while (d==a || d==b) {
                                ++d;
                            }
                            if (ok(P[v[a]], P[v[b]], P[v[c]], P[v[d]])) {
                                goto GOOD;
                            }
                        }
                    }
                    continue;
                    GOOD:;
                    for (int a=0; a<2; ++a) {
                        for (int b=a+1; b<3; ++b) {
                            for (int c=b+1; c<4; ++c) {
                                if (!done[v[a]][v[b]][v[c]]) {
                                    done[v[a]][v[b]][v[c]] = 1;
                                    Q.push(State(v[a], v[b], v[c]));
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 40, 60}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 30; double Arg3 = 80.0; verify_case(0, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {20, 40, 60, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 20, 20, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; double Arg3 = 40.0; verify_case(1, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {10, 10, 10, 10,  10,  10,  10,  10,  10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 40, 60, 80, 100, 120, 140, 160, 180}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 30; double Arg3 = 200.0; verify_case(2, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 40; double Arg3 = 80.0; verify_case(3, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = { 50, 100, 150, 200,
  50, 100, 150, 200,
  50, 100, 150, 200,
  50, 100, 150, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50,  50,  50,  50,
 100, 100, 100, 100,
 150, 150, 150, 150,
 200, 200, 200, 200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; double Arg3 = 50.0; verify_case(4, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = { 50, 100, 150, 200,
  50, 100, 150, 200,
  50, 100, 150, 200,
  50, 100, 150, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50,  50,  50,  50,
 100, 100, 100, 100,
 150, 150, 150, 150,
 200, 200, 200, 200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; double Arg3 = 250.0; verify_case(5, Arg3, maxHeight(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WallClimbing ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
