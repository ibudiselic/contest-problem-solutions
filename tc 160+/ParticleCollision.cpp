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

const double pi = 3.14159265358979323846;

vector<double> retval(double a, double b, double c) {
    vector<double> v(3, a);
    v[1] = b;
    v[2] = c;

    return v;
}

bool eq(double a, double b) {
    return fabs(a-b) <= 1e-9;
}

class ParticleCollision {
	public:
	vector <double> collision(int vx, int vy, int vz, int x0, int y0, int z0) {
        if (vx==0 && vy==0) {
            if (x0*x0 + y0*y0 - 1 != 0) {
                return vector<double> ();
            }
            if (vz != 0) {
                return vector<double> (3, 0.0);
            }
            int t = z0;
            if (eq(x0, cos(pi * t)) && eq(y0, sin(pi * t))) {
                return retval(x0, y0, z0);
            } else {
                return vector<double>();
            }
        }

		int a = vx*vx + vy*vy;
        int b = 2*(vx*x0 + vy*y0);
        int c = x0*x0 + y0*y0-1;

        if (b*b - 4*a*c < 0) {
            return vector<double>();
        }

        double D = sqrt(b*b - 4*a*c);
        double t, tt;
        vector<double> ret;

        cerr << a << ' ' << b << ' ' << c << ' ' << D << '\n';

        t = (-b-D)/2/a;
        tt = vz*t + z0;
        cerr << t << ' ' << tt << '\n';
        if (eq(vx*t + x0, cos(pi * tt)) && eq(vy*t + y0, sin(pi * tt)) && eq(vz*t + z0, tt)) {
            ret = retval(cos(pi * tt), sin(pi * tt), tt);
        }
       
        if (!eq(D, 0)) {
            t = (-b+D)/2/a;
            tt = vz*t + z0;
            cerr << t << ' ' << tt << '\n';
            if (eq(vx*t + x0, cos(pi * tt)) && eq(vy*t + y0, sin(pi * tt)) && eq(vz*t + z0, tt)) {
                if (ret.size() > 0) {
                    return vector<double> (3, 0.0);
                }
                ret = retval(cos(pi * tt), sin(pi * tt), tt);
            }
        }

        return ret;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; double Arr6[] = { }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 1; int Arg3 = -1; int Arg4 = -1; int Arg5 = 0; double Arr6[] = {0.0, 1.0, 0.5 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = 5; int Arg4 = 4; int Arg5 = 0; double Arr6[] = {0.0, 0.0, 0.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; double Arr6[] = {0.0, 0.0, 0.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ParticleCollision ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
