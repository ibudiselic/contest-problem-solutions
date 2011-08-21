#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const double EPS = 1e-9;
double eq(double a, double b) {
    return fabs(a-b) < EPS;
}
struct point {
    double x, y;
    point(double x_=0.0, double y_=0.0): x(x_), y(y_) {}
    double length() const { return sqrt(x*x + y*y); }
};

bool operator==(const point &A, const point &B) {
    return fabs(A.x-B.x)<EPS && fabs(A.y-B.y)<EPS;
}

point operator-(const point &A, const point &B) {
    return point(A.x-B.x, A.y-B.y);
}
point operator-(const point &A) {
    return point(-A.x, -A.y);
}
point operator+(const point &A, const point &B) {
    return point(A.x+B.x, A.y+B.y);
}

ostream& operator<<(ostream &os, const point &A) {
    os << '(' << A.x << ',' << A.y << ')';
    return os;
}

double dist(const point &A, const point &B) {
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

point translate(const point &A, const point &by) {
    return A + by;
}
point rotate(const point &A, double phi_rad) {
    if (fabs(A.x)<EPS && fabs(A.y)<EPS) { // required check for atan2
        return A;
    }
    double ang_rad = atan2(A.y, A.x) + phi_rad;
    const double len = A.length();
    return point(len * cos(ang_rad), len * sin(ang_rad));
}

point circumcenter(const point &A, const point &B, const point &C) {
    const point b = B - A;
    const point c = C - A;
    double denom = 2*(b.x*c.y - b.y*c.x);
    
    point ret(c.y*(b.x*b.x + b.y*b.y) - b.y*(c.x*c.x + c.y*c.y),
              b.x*(c.x*c.x + c.y*c.y) - c.x*(b.x*b.x + b.y*b.y));
    ret.x /= denom;
    ret.y /= denom;
    
    return ret + A; // translate back
}

point affine(const point &A, const point &B, double t) {
    return point(A.x*t + (1-t)*B.x, A.y*t + (1-t)*B.y);
}

vector<point> ccintersection(const point &A, double ra, const point &B, double rb) {
    if (A == B) {
        if (eq(ra, rb)) {
            assert(!"same circle - infinite intersection");
        } else {
            return vector<point>();
        }
    }

    const double d = dist(A, B);
    if (d>ra+rb+EPS || d+ra<rb-EPS || d+rb<ra-EPS) {
        return vector<point>();
    }
    
    point b = B - A;
    assert(!(b == point(0, 0))); // due to first if
    assert(eq(d, b.length()));

    double ang_rad = atan2(b.y, b.x);
    b = rotate(b, -ang_rad);
    assert(eq(b.y, 0.0));
    
    const double x = (ra*ra - rb*rb + d*d)/2.0/d;
    const double tmp = sqrt(ra*ra - x*x);
    vector<point> ret;
    ret.push_back(point(x, -tmp));
    ret.push_back(point(x, +tmp));
    
    for (int i=0; i<2; ++i) {
        ret[i] = rotate(ret[i], +ang_rad) + A;
    }
    return ret;
}

void output(const point &A) {
    printf("%.5f %.5f\n", A.x, A.y);
}

double r[3];
point P[3];
int main() {
    for (int i=0; i<3; ++i) {
        cin >> P[i].x >> P[i].y >> r[i];
    }
    
    if (eq(r[0], r[1]) && eq(r[1], r[2])) {
        output(circumcenter(P[0], P[1], P[2]));
    } else {
        if (eq(r[0], r[1])) {
            swap(P[0], P[2]);
            swap(r[0], r[2]);
        } else if (eq(r[0], r[2])) {
            swap(P[0], P[1]);
            swap(r[0], r[1]);
        }
        
        double tc1 = r[1]*r[1]/(r[1]*r[1] - r[0]*r[0]);
        point A = affine(P[0], P[1], tc1);
        double ra = r[0]*r[1]/abs(r[1]*r[1] - r[0]*r[0]) * dist(P[0], P[1]);
        
        double tc2 = r[2]*r[2]/(r[2]*r[2] - r[0]*r[0]);
        point B = affine(P[0], P[2], tc2);
        double rb = r[0]*r[2]/abs(r[2]*r[2] - r[0]*r[0]) * dist(P[0], P[2]);
        
        vector<point> same_angle = ccintersection(A, ra, B, rb);
        if (same_angle.size() > 0) {
            if (dist(same_angle[0], P[0]) > dist(same_angle[1], P[0])) {
                swap(same_angle[0], same_angle[1]); // less dist -> wider angle
            }
            output(same_angle[0]);
        }
    }
    return 0;
}
