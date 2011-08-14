#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cctype>

using namespace std;

string s;
class DeserializeSequence {
	public:
	int rek(int x, int last) {
		if (x==(int)s.size()) return 1;

		int res = 0;
		for (int i=x; i<(int)s.size(); ++i) {
			int t = atoi(s.substr(x, i-x+1).c_str());
			if (t == 0) continue;
			if (t > 1000000) break;
			if (t >= last)
				res += rek(i+1, t);
		}
		return res;
	}
	int howMany(string str) {
		s = str;
		return rek(0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1234"; int Arg1 = 5; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arg0 = "000000000001"; int Arg1 = 1; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arg0 = "1000000000000"; int Arg1 = 0; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arg0 = "9876543210"; int Arg1 = 5; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arg0 = "11111111111111111111111111111111111111111111111111"; int Arg1 = 9192; verify_case(4, Arg1, howMany(Arg0)); }
	void test_case_5() { string Arg0 = "10010010010010010010010010010010010010010010010010"; int Arg1 = 1217; verify_case(5, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DeserializeSequence ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
