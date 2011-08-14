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

class NestedDiamonds {
	public:
	double minHeight(vector <int> sides) {
		sort(sides.begin(), sides.end());
		for (int i=1; i<(int)sides.size(); ++i) {
			if (sides[i] == sides[i-1]) {
				return -1.0;
			}
		}

		vector<long long> a;
		for (int i=0; i<(int)sides.size(); ++i) {
			a.push_back((long long)sides[i] * sides[i]);
		}

		long long l = 0;
		long long r = a.back();
		long long t = 0;
		reverse(a.begin(), a.end());
		for (int i=1; i<(int)a.size(); ++i) {
			long long ll, rr;
			if (i & 1) {
				ll = a[i] + t;
				rr = 2*a[i] + t;
				t += 2*a[i];
			} else {
				ll = t - 2*a[i];
				rr = t - a[i];
				t -= 2*a[i];
			}
			l = max(l, ll);
			r = min(r, rr);
		}

		if (l > r) {
			return -1.0;
		}

		return 2 * sqrt(0.5*l);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.8284271247461903; verify_case(0, Arg1, minHeight(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 5, 2}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.16515138991168; verify_case(1, Arg1, minHeight(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.69041575982343; verify_case(2, Arg1, minHeight(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -1.0; verify_case(3, Arg1, minHeight(Arg0)); }
	void test_case_4() { int Arr0[] = {1,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.656854249492381; verify_case(4, Arg1, minHeight(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NestedDiamonds ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
