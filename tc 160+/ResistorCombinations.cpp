#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


double tr, sol, dif;
vector<double> a;
vector<int> order;
inline double serial(double a, double b) {
	return a+b;
}
inline double parallel(double a, double b) {
	return a*b/(a+b);
}
inline void update(double cur) {
	if (fabs(tr-cur) < dif) {
		dif = fabs(tr-cur);
		sol = cur;
	}
}
template<class T> void append(vector<T> &a, const vector<T> &b) {
	for (int i=0; i<(int)b.size(); ++i)
		a.push_back(b[i]);
}
vector<double> go(int l, int r) {
	if (l+1 == r)
		return vector<double>(1, a[order[l]]);

	vector<double> ret;
	for (int m=l+1; m<r; ++m) {
		vector<double> x = go(l, m);
		vector<double> y = go(m, r);
		for (int i=0; i<(int)x.size(); ++i)
			for (int j=0; j<(int)y.size(); ++j) {
				ret.push_back(serial(x[i], y[j]));
				ret.push_back(parallel(x[i], y[j]));
			}
		append(ret, x);
		append(ret, y);
	}
	return ret;
}
class ResistorCombinations {
	public:
	double closestValue(vector <string> resistances, double target) {
		tr = target;
		a.clear();

		for (int i=0; i<(int)resistances.size(); ++i) {
			double x;
			sscanf(resistances[i].c_str(), "%lf", &x);
			a.push_back(x);
		}

	  dif = 1e32;
		order.clear();
		for (int i=0; i<(int)a.size(); ++i)
			order.push_back(i);

		do {
			vector<double> t = go(0, order.size());
			for (int i=0; i<(int)t.size(); ++i)
				update(t[i]);
		} while (next_permutation(order.begin(), order.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"2","3","5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.5; double Arg2 = 2.5; verify_case(0, Arg2, closestValue(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"2","3","5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1; double Arg2 = 0.967741935483871; verify_case(1, Arg2, closestValue(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"10.25","13.31","6.777","12.2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 10.5; double Arg2 = 10.510805181371511; verify_case(2, Arg2, closestValue(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"10000","2000","300","40","5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 20000; double Arg2 = 12345.0; verify_case(3, Arg2, closestValue(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"125.10000","00270.9","000625.55","90.100000","0015.60000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 153; double Arg2 = 152.75975812465552; verify_case(4, Arg2, closestValue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ResistorCombinations ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
