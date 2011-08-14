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

struct line {
    line(int x1, int y1, int x2, int y2) {
        A = y1 - y2;
        B = x2 - x1;
        assert(A!=0 || B!=0);
        C = A*x1 + B*y1;
        if (A<0 || A==0 && B<0) {
            A *= -1;
            B *= -1;
            C *= -1;
        }
    }
    line(int A_, int B_, int C_): A(A_), B(B_), C(C_) {}

    int A, B, C;
};
struct dpoint {
    double x, y;
    dpoint(double x_, double y_): x(x_), y(y_) {}
};

bool operator<(const dpoint &a, const dpoint &b) {
    if (fabs(a.x - b.x) > 1e-9) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}

bool parallel(const line &u, const line &v) {
    return (long long)u.A*v.B == (long long)u.B*v.A;
}

const line perp(const line &l) {
    return line(-l.B, l.A, 0);
}

const dpoint intersection2(const line &u, const line &v) {
    assert(!parallel(u, v));

    if (u.A == 0) {
        assert(v.A != 0);
        assert(u.B != 0);
        double y = double(u.C) / u.B;
        return dpoint((v.C - y*v.B) / v.A, y);
    } else if (u.B == 0) {
        assert(v.B != 0);
        assert(u.A != 0);
        double x = double(u.C) / u.A;
        return dpoint(x, (v.C - x*v.A) / v.B);
    }
    
    double c = double(u.C) / u.A;
    double cy = -double(u.B) / u.A;
    double y = (v.C - v.A*c) / (v.A*cy + v.B);
    double x = cy*y + c;

    return dpoint(x, y);
}

const dpoint intersection(const line &u, const line &v) {
    assert(!parallel(u, v));

    if (u.A == 0) {
        assert(v.A != 0);
        assert(u.B != 0);
        double y = double(u.C) / u.B;
        return dpoint((v.C - y*v.B) / v.A, y);
    } else if (u.B == 0) {
        assert(v.B != 0);
        assert(u.A != 0);
        double x = double(u.C) / u.A;
        return dpoint(x, (v.C - x*v.A) / v.B);
    }

    return intersection2(v, u);
}

bool diff(const dpoint &a, const dpoint &b) {
    return fabs(a.x-b.x)>1e-9 || fabs(a.y-b.y)>1e-9;
}

double dist(const dpoint &a, const dpoint &b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool contains(const line &l, double x, double y) {
    double t = l.A*x + l.B*y;
    return fabs(t-l.C) <= 1e-9;
}

class CentersOfSymmetry {
	public:
	int lineConfigurations(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2) {
        int n = x1.size();
        if (n == 1) {
            return -1;
        }
        vector<line> L;
		for (int i=0; i<n; ++i) {
            L.push_back(line(x1[i], y1[i], x2[i], y2[i]));
        }
        
        vector<dpoint> P;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (!parallel(L[i], L[j])) {
                    P.push_back(intersection(L[i], L[j]));
                }
            }
        }

        if (P.size() == 0) {
            line l = perp(L[0]);
            for (int i=0; i<n; ++i) {
                P.push_back(intersection(l, L[i]));
            }
            sort(P.begin(), P.end());
            dpoint mid(0, 0);
            if (P.size() % 2 == 0) {
                int t = P.size() / 2;
                mid = dpoint((P[t-1].x + P[t].x)/2, (P[t-1].y + P[t].y)/2);
            } else {
                mid = P[P.size() / 2];
            }

            for (int i=0; 2*i<(int)P.size()-1; ++i) {
                if (fabs(dist(P[i], mid) - dist(mid, P[P.size()-1-i])) > 1e-9) {
                    return 0;
                }
            }

            return -1;
        } else {
            sort(P.begin(), P.end());
            vector<dpoint> v;
            v.push_back(P[0]);
            for (int i=1; i<(int)P.size(); ++i) {
                if (diff(P[i], P[i-1])) {
                    v.push_back(P[i]);
                }
            }

            double x = 0.0;
            double y = 0.0;
            for (int i=0; i<(int)v.size(); ++i) {
                x += v[i].x;
                y += v[i].y;
            }
            x /= v.size();
            y /= v.size();

            for (int i=0; i<(int)L.size(); ++i) {
                bool ok = false;
                double xx = 2*x - x1[i];
                double yy = 2*y - y1[i];
                for (int j=0; j<(int)L.size(); ++j) {
                    if (contains(L[j], xx, yy)) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    return 0;
                }
            }

            return 1;
        }

        return -2;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, -1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(0, Arg4, lineConfigurations(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(1, Arg4, lineConfigurations(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, -1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, lineConfigurations(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {-10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, -10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-10, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-10, 10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(3, Arg4, lineConfigurations(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {-50, -50, -50, -50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-50, -49, -48, -46}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50, 49, 48, 46}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50, 50, 50, 50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(4, Arg4, lineConfigurations(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {10, -35, -8, 7, -5, -8, -9, -50, -17, -18, -17, -26, -5, 23, 18, -7, -8, -6,
 -8, -12, 22, -7, 17, -48, -6, -16, -12, -14, 13, 30, 11, 17, -3, -5, -27, -30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-27, -25, -17, -26, -3, -19, -20, -33, -22, -21, -23, -38, -2, -32, -27, -8, -2, -5,
 -21, -7, -15, -15, -5, -27, 0, -19, -25, 1, -22, -11, -13, -38, -1, -6, -17, -32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {16, -32, -11, 11, -3, -9, -8, -45, -16, -15, -19, -29, -2, 20, 24, -1, 4, -7,
 -5, -13, 16, -9, 29, -43, 2, -17, -15, -15, 17, 24, 23, 14, -7, -3, -24, -33}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-35, -23, -26, -32, -3, -21, -18, -30, -20, -15, -27, -42, -5, -28, -35, 2, -5, -6,
 -15, -7, -13, -19, -9, -24, -12, -21, -34, 1, -28, -9, -17, -34, -9, 0, -15, -36}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(5, Arg4, lineConfigurations(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CentersOfSymmetry ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
