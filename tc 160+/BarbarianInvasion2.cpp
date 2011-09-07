#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
double dist(double x1, double y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void update(double x, double y, int x1, int y1, int x2, int y2, double len, vector<double> &pts) {
    double t = (x-x1)/(x2-x1)*len;
    if (t>0.0 && t<len) {
        pts.push_back(t);
    }
}
class BarbarianInvasion2 {
	public:
	double minimumTime(vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy) {
		int n = bx.size();
        int ncities = cx.size();
        
        bx.push_back(bx[0]);
        by.push_back(by[0]);
        vector<double> lens;
        double total = 0.0;
        for (int i=0; i<n; ++i) {
            lens.push_back(dist(bx[i], by[i], bx[i+1], by[i+1]));
            total += lens.back();
        }
        
        double lo = 0.0;
        double hi = 3000.0;
        for (int iter=0; iter<100; ++iter) {
            double R = (lo+hi)/2.0;
            vector<double> covers(32, 0.0);
            for (int i=0; i<n; ++i) {
                vector<double> pts;
                pts.push_back(0);
                pts.push_back(lens[i]);
                for (int j=0; j<ncities; ++j) {
                    int x1 = bx[i] - cx[j];
                    int y1 = by[i] - cy[j];
                    int x2 = bx[i+1] - cx[j];
                    int y2 = by[i+1] - cy[j];
                    
                    if (x1 == x2) {
                        double yy = R*R - x1*x1;
                        if (yy >= 0) {
                            double y = sqrt(yy);
                            update(-y, x1, y1, x1, y2, x2, lens[i], pts);
                            update(+y, x1, y1, x1, y2, x2, lens[i], pts);
                        }
                    } else {
                        double k = double(y2-y1)/(x2-x1);
                        double C = y1 - k*x1;
                        double a = 1+k*k;
                        double b = 2*k*C;
                        double c = C*C - R*R;
                        double D = b*b - 4*a*c;
                        if (D < 0) {
                            D = 0;
                        }
                        double sqrtD = sqrt(D);
                        double x = (-b-sqrtD)/2/a;
                        double y = k*x + C;
                        update(x, y, x1, y1, x2, y2, lens[i], pts);
                        x = (-b+sqrtD)/2/a;
                        y = k*x + C;
                        update(x, y, x1, y1, x2, y2, lens[i], pts);
                    }
                }
                sort(pts.begin(), pts.end());
                for (int j=1; j<(int)pts.size(); ++j) {
                    double d = (pts[j-1]+pts[j])/2.0;
                    double x = bx[i] + d/lens[i]*(bx[i+1]-bx[i]);
                    double y = by[i] + d/lens[i]*(by[i+1]-by[i]);
                    int s = 0;
                    for (int k=0; k<ncities; ++k) {
                        if (dist(x, y, cx[k], cy[k]) <= R) {
                            s |= (1<<k);
                        }
                    }
                    covers[s] += pts[j] - pts[j-1];
                }
            }
            
            bool ok = true;
            for (int s1=1; s1<(1<<ncities); ++s1) {
                double s1_need = 0.0;
                for (int i=0; i<ncities; ++i) {
                    if (s1 & (1<<i)) {
                        s1_need += total/ncities;
                    }
                }
                double s1_can_have = 0.0;
                for (int s2=1; s2<(1<<ncities); ++s2) {
                    if (s1 & s2) {
                        s1_can_have += covers[s2];
                    }
                }
                if (s1_can_have < s1_need - 1e-11) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                hi = R;
            } else {
                lo = R;
            }
        }

        return hi;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1.414213562373088; verify_case(0, Arg4, minimumTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,3,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.8284271247461485; verify_case(1, Arg4, minimumTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,3,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.236067977499772; verify_case(2, Arg4, minimumTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,40,40,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,40,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,31,2,15}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,3,24}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 38.05748153551994; verify_case(3, Arg4, minimumTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {0,124,-6,-120,-300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,125,140,137,-100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50,51,52,21}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 332.77770358002783; verify_case(4, Arg4, minimumTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BarbarianInvasion2 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
