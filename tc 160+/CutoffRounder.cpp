#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CutoffRounder {
	public:
	int round(string num, string cutoff) {
		long long x, r;
		int cnt;
		if (num[0] == '.')
			num = '0' + num;
		{
		  char c; int a, b; istringstream is(num);
		  if (is >> a >> c >> b) {
		  	assert(num.find('.') != string::npos);
		  	cnt = num.size()-num.find('.') - 1;
		  	long long pot10 = 1;
		  	for (int t=0; t<cnt; ++t)
		  		pot10 *= 10;
		  	x = a*pot10 + b;
		  } else {
		  	cnt = 0;
		  	x = a;
		  }
		}
		{
		  char c; int a, b; istringstream is(cutoff);
		  assert(is >> a >> c >> b);
		  r = b;
		  int t = cnt-4;
		  if (t > 0)
		  	while (t--)
		  		r *= 10;
		  else if (t < 0)
		  	while (t++) {
		  		++cnt;
		  		x *= 10;
		  	}
		}
		//cerr << num << ' ' << cutoff << ' ' << x << ' ' << r << ' ' << cnt << '\n';

		long long pot10 = 1;

		for (int t=0; t<cnt; ++t)
			pot10 *= 10;
		x += (x%pot10 >= r%pot10)*pot10;

		while (cnt--)
			x /= 10;

		return x;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "003.656930"; string Arg1 = "0.5000"; int Arg2 = 4; verify_case(0, Arg2, round(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = ".001"; string Arg1 = "0.0001"; int Arg2 = 1; verify_case(1, Arg2, round(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1.99999999"; string Arg1 = "0.9999"; int Arg2 = 2; verify_case(2, Arg2, round(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "135"; string Arg1 = "0.6531"; int Arg2 = 135; verify_case(3, Arg2, round(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "135."; string Arg1 = "0.6531"; int Arg2 = 135; verify_case(4, Arg2, round(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "1356.13671"; string Arg1 = "0.1367"; int Arg2 = 1357; verify_case(5, Arg2, round(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "0.00010001"; string Arg1 = "0.0001"; int Arg2 = 1; verify_case(6, Arg2, round(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CutoffRounder ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
