#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
class TireRotation {
	public:
	int getCycle(string initial, string current) {
		string t(initial.size(), ' ');
		for (int i=0; i<4; ++i) {
			if (initial == current) return i+1;
			t[2] = initial[0];
			t[3] = initial[1];
			t[1] = initial[2];
			t[0] = initial[3];
			initial = t;
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCD"; string Arg1 = "ABCD"; int Arg2 = 1; verify_case(0, Arg2, getCycle(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCD"; string Arg1 = "DCAB"; int Arg2 = 2; verify_case(1, Arg2, getCycle(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABCD"; string Arg1 = "CDBA"; int Arg2 = 4; verify_case(2, Arg2, getCycle(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABCD"; string Arg1 = "ABDC"; int Arg2 = -1; verify_case(3, Arg2, getCycle(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ZAXN"; string Arg1 = "XNAZ"; int Arg2 = 4; verify_case(4, Arg2, getCycle(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TireRotation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
