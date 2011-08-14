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

int N;
struct point {
    long long x, y;
    point(long long x_, long long y_): x(x_), y(y_) {}
};
point operator-(const point &a, const point &b) {
    return point(a.x-b.x, a.y-b.y);
}
vector<point> P;
struct comparator {
    bool operator()(int i, int j) {
        if (P[i].x != P[j].x) {
            return P[i].x < P[j].x;
        } else {
            return P[i].y < P[j].y;
        }
    }
};
long long cross(const point &a, const point &b) {
    return a.x*b.y - a.y*b.x;
}
int sgn0(long long x) {
    return x<0 ? -1 : int(x>0);
}
int ccw(const point &a, const point &b) {
    return sgn0(cross(a, b));
}
int ccw(const point &c, const point &a, const point &b) {
    return ccw(b-a, c-a);
}
int ccw(int k, int i, int j) {
    return ccw(P[k], P[i], P[j]);
}
vector<int> combine(vector<int> A, const vector<int> &B) {
    for (int i=0; i<(int)B.size(); ++i) {
        A.push_back(B[i]);
    }
    return A;
}
vector<int> convex_hull(vector<int> A) {
    if (A.size() < 3) {
        return A;
    }
    sort(A.begin(), A.end(), comparator());
    vector<int> up, down;
    int p_down = 0;
    int p_up = 0;
    while (p_up<(int)A.size() && P[A[p_up]].x==P[A[p_down]].x) {
        ++p_up;
    }
    --p_up;
    
    up.push_back(p_up);
    down.push_back(p_down);
    while (true) {
        while (p_down<(int)A.size() && P[A[p_down]].x==P[A[down.back()]].x) {
            ++p_down;
        }
        if (p_down == (int)A.size()) {
            break;
        }
        while (down.size()>1 && ccw(P[A[p_down]], P[A[down[(int)down.size()-2]]], P[A[down.back()]])<=0) {
            down.pop_back();
        }
        down.push_back(p_down);
        p_up = p_down;
        while (p_up<(int)A.size() && P[A[p_up]].x==P[A[p_down]].x) {
            ++p_up;
        }
        --p_up;
        while (up.size()>1 && ccw(P[A[p_up]], P[A[up[(int)up.size()-2]]], P[A[up.back()]])>=0) {
            up.pop_back();
        }
        up.push_back(p_up);
    }
    
    if (up.back() == down.back()) {
        up.pop_back();
    }
    reverse(up.begin(), up.end());
    if (up.back() == down[0]) {
        up.pop_back();
    }

    vector<int> ret;
    for (int i=0; i<(int)down.size(); ++i) {
        ret.push_back(A[down[i]]);
    }
    for (int i=0; i<(int)up.size(); ++i) {
        ret.push_back(A[up[i]]);
    }
    return ret;
}
double area(const vector<int> &A) {
    double ret = 0.0;
    for (int i=0; i<(int)A.size(); ++i) {
        int j = (i+1)%A.size();
        ret += cross(P[A[j]], P[A[i]]);
    }
    return fabs(ret)/2.0;
}
double calc(const vector<int> &A, const vector<int> &B) {
    return max(area(convex_hull(A)), area(convex_hull(B)));
}
class BatmanAndRobin {
	public:
	double minArea(vector <int> x, vector <int> y) {
        N = x.size();  
        if (N == 1) {
            return 0.0;
        }
        P.clear();
        for (int i=0; i<N; ++i) {
            P.push_back(point(x[i], y[i]));
        }
        
        double sol = 1e32;
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                vector<int> L, R, on;
                for (int k=0; k<N; ++k) {
                    int tmp = ccw(k, i, j);
                    if (tmp == 0) {
                        on.push_back(k);
                    } else if (tmp == 1) {
                        R.push_back(k);
                    } else {
                        L.push_back(k);
                    }
                }
                sol = min(sol, calc(combine(L, on), R));
                sol = min(sol, calc(L, combine(R, on)));
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,100,90,90,-100,-100,-90,-90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,90,100,90,-100,-90,-100,-90}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 100.0; verify_case(0, Arg2, minArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1000,-1000,1000,1000,1000,-1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1000,1000,-1000,1000,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, minArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1000,-1000,1000,1000,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1000,1000,-1000,1000,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1000000.0; verify_case(2, Arg2, minArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-904,-812,-763,-735,-692,-614,-602,-563,-435,-243,-87,-52,-28,121,126,149,157,185,315,336,390,470,528,591,673,798,815,837,853,874}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {786,10,-144,949,37,-857,-446,-969,-861,-712,5,-972,-3,-202,-845,559,-244,-542,-421,422,526,-501,-791,-899,-315,281,-275,467,743,-321}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1067472.0; verify_case(3, Arg2, minArea(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BatmanAndRobin ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
