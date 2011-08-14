#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class EratosthenSieve2 {
	public:
	int nthElement(int n) {
		vector<int> a;
		for (int i=1; i<=1000; ++i)
			a.push_back(i);
		for (int i=2; i<11; ++i) {
			vector<int> next;
			for (int j=1; j<=(int)a.size(); ++j)
				if (j%i)
					next.push_back(a[j-1]);
			a = next;
		}
		return a[n-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; verify_case(0, Arg1, nthElement(Arg0)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; verify_case(1, Arg1, nthElement(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 79; verify_case(2, Arg1, nthElement(Arg0)); }
	void test_case_3() { int Arg0 = 25; int Arg1 = 223; verify_case(3, Arg1, nthElement(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EratosthenSieve2 ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
