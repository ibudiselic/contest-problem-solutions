#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int fd2[5000001], fd3[5000001], fd5[5000001];

class PascalCount {
	public:
	int howMany(int i, int d) {
		int sol = 0;

		for (int j=1; j<=5000000; ++j) {
			fd2[j] = j/2 + fd2[j/2];
			fd3[j] = j/3 + fd3[j/3];
			fd5[j] = j/5 + fd5[j/5];
		}
		for (int j=1; j<=i; ++j) {
			int c2 = fd2[i]-fd2[j]-fd2[i-j];
			int c3 = fd3[i]-fd3[j]-fd3[i-j];
			int c5 = fd5[i]-fd5[j]-fd5[i-j];

			switch (d) {
				case 2: if (c2) ++sol; break;
				case 3: if (c3) ++sol; break;
				case 4: if (c2>=2) ++sol; break;
				case 5: if (c5) ++sol; break;
				case 6: if (c2 && c3) ++sol; break;
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 1; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 3; int Arg2 = 0; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PascalCount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
