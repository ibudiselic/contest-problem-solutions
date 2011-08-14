#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

inline int sqr(int x) {
	return x*x;
}
class LongNumber {
	public:
	int first(int k) {
		int t = k;
		int pot10 = 1;
		int digs = 1;
		while (t > 0) {
			t -= (pot10*10 - pot10)*digs;
			pot10 *= 10;
			++digs;
		}
		pot10 /= 10;
		--digs;
		t += (pot10*10-pot10)*digs;
		--t;
		return to_str(pot10 + (t/digs))[t%digs] - '0';
	}
	int second(int k) {
		int t = k;
		int pot10 = 1;
		int digs = 1;
		while (t > 0) {
			t -= ((int)sqrt((double)pot10*10) - (int)sqrt((double)pot10))*digs;
			pot10 *= 10;
			++digs;
		}
		pot10 /= 10;
		--digs;
		t += ((int)sqrt((double)pot10*10) - (int)sqrt((double)pot10))*digs;
		--t;
		cerr << t << ' ' << digs << ' ' << pot10 << '\n';
		return to_str(sqr((int)sqrt((double)pot10) + (t/digs)))[t%digs] - '0';
	}
	int findDigit(int k) {
		/*int sol;
		sol = (first(k)+second(k))%10;

		t = k+1;
		while (first(t)+second(t)==9)
			++t;
		sol += (first(t)+second(t) > 9);

		return sol;*/
		return second(k);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; verify_case(0, Arg1, findDigit(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; verify_case(1, Arg1, findDigit(Arg0)); }
	void test_case_2() { int Arg0 = 78; int Arg1 = 5; verify_case(2, Arg1, findDigit(Arg0)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 6; verify_case(3, Arg1, findDigit(Arg0)); }
	void test_case_4() { int Arg0 = 1780243932; int Arg1 = 1; verify_case(4, Arg1, findDigit(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LongNumber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
