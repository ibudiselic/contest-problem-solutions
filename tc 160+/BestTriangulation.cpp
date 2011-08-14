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

vector<double> X, Y;
vector< vector<double> > D;
inline double sqr(double x) { return x*x; }
inline double dist(int i, int j) {
	return sqrt(sqr(X[i]-X[j]) + sqr(Y[i]-Y[j]));
}
double triag(int i, int j, int k) {
	double a = D[i][j], b = D[j][k], c = D[k][i];
	double s = (a+b+c) / 2;

	return sqrt(s*(s-a)*(s-b)*(s-c));
}
class BestTriangulation {
	public:
	double maxArea(vector <string> vertices) {
		X.clear();
		Y.clear();
		for (int i=0; i<(int)vertices.size(); ++i) {
			int x, y;
			sscanf(vertices[i].c_str(), "%d %d", &x, &y);
			X.push_back(x);
			Y.push_back(y);
		}
		D.assign(X.size(), vector<double>(X.size(), 0.0));
		for (int i=0; i<(int)X.size(); ++i)
			for (int j=i+1; j<(int)X.size(); ++j)
				D[i][j] = D[j][i] = dist(i, j);

		double sol = 0.0;
		for (int i=0; i<(int)X.size(); ++i)
			for (int j=i+1; j<(int)Y.size(); ++j)
				for (int k=j+1; k<(int)X.size(); ++k)
					sol = max(sol, triag(i, j, k));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 1", "2 3", "3 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5; verify_case(0, Arg1, maxArea(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 1", "1 2", "3 3", "2 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5; verify_case(1, Arg1, maxArea(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 2", "1 3", "2 4", "3 4", "4 3", "4 2", "3 1", "2 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(2, Arg1, maxArea(Arg0)); }
	void test_case_3() { string Arr0[] = {"6 2", "2 1", "1 2", "1 4", "2 6", "5 6", "6 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 10.0; verify_case(3, Arg1, maxArea(Arg0)); }
	void test_case_4() { string Arr0[] = {"10000 3469", "9963 712", "9957 634", "9834 271", "9700 165",
 "9516 46", "8836 4", "1332 57", "229 628", "171 749",
 "52 1269", "30 1412", "7 4937", "35 8676", "121 9917",
 "2247 9960", "3581 9986", "6759 9995", "9486 9998", "9888 9890",
 "9914 9318", "9957 8206", "9998 6402"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.8292483E7; verify_case(4, Arg1, maxArea(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BestTriangulation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
