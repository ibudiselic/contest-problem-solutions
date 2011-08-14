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

int sqr(int x) { return x*x; }
double D(int i, int ir, int j, int jr) {
	return sqrt(sqr(abs(i-j)) + abs(ir-jr)*4);
}
double dist(int i, int ir, int j, int jr, int k, int kr) {
	return D(i, ir, j, jr) + D(j, jr, k, kr) + D(k, kr, i, ir);
}
class BusSeating {
	public:
	double getArrangement(string leftRow, string rightRow) {
		double sol = 1e30;
		string A[2];
		A[0] = leftRow;
		A[1] = rightRow;
		for (int i=0; i<9; ++i)
			for (int ir=0; ir<2; ++ir)
				if (A[ir][i] == '-')
				for (int j=i; j<10; ++j)
					for (int jr=0; jr<2; ++jr)
						if (i!=j || ir!=jr)
						if (A[jr][j] == '-')
							for (int k=j+(i==j); k<10; ++k)
								for (int kr=0; kr<2; ++kr)
									if (j!=k || jr!=kr)
									if (A[kr][k] == '-')
										sol = min(sol, dist(i, ir, j, jr, k, kr));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "----------"; string Arg1 = "----------"; double Arg2 = 4.0; verify_case(0, Arg2, getArrangement(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "XXX-X-XX-X"; string Arg1 = "-XXXX---XX"; double Arg2 = 4.0; verify_case(1, Arg2, getArrangement(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "XXXXXXXXXX"; string Arg1 = "-XX-XX-X--"; double Arg2 = 6.0; verify_case(2, Arg2, getArrangement(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "XXX-X-XX-X"; string Arg1 = "XXX-X-XX-X"; double Arg2 = 6.82842712474619; verify_case(3, Arg2, getArrangement(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BusSeating ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
