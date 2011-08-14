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

double log1px(double x) {
    double ret = 0.0;
    double xx = x;
    for (int i=0; i<20; ++i) {
        ret += xx/(i+1);
        xx *= -x;
    }

    return ret;
}

class CollectingBonuses {
	public:
	double expectedBuy(string n_, string k_) {
		long long n, k;
        sscanf(n_.c_str(), "%lld", &n);
        sscanf(k_.c_str(), "%lld", &k);

        const long long lim = 10000000;
        long long m = n-k+1;
        double t = 0.0;

        while (m <= lim) {
            t += 1.0/m;
            if (m++ == n) {
                return n*t;
            }
        }

        double x = double(2*n - 2*m + 2)/(2*m - 1);

        if (x < 0.5) {
            return n * (t + log1px(x));
        } else {
            return n * (t + log(1+x));
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1"; string Arg1 = "1"; double Arg2 = 1.0; verify_case(0, Arg2, expectedBuy(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "2"; string Arg1 = "1"; double Arg2 = 1.0; verify_case(1, Arg2, expectedBuy(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "2"; string Arg1 = "2"; double Arg2 = 3.0; verify_case(2, Arg2, expectedBuy(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "4"; string Arg1 = "3"; double Arg2 = 4.333333333333333; verify_case(3, Arg2, expectedBuy(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CollectingBonuses ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
