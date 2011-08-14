#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class PeopleCircle {
	public:
	string order(int m, int f, int k) {
		string sol(m+f, 'M');
		int n = m+f;
		int start = n-1;

		for (int i=0; i<f; ++i) {
			for (int j=0; j<k; ) {
				start = (start+1)%n;
				if (sol[start] == 'M')
					++j;
			}
			sol[start] = 'F';
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; string Arg3 = "MFMFMFMM"; verify_case(0, Arg3, order(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 3; int Arg2 = 1; string Arg3 = "FFFMMMMMMM"; verify_case(1, Arg3, order(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 25; int Arg1 = 25; int Arg2 = 1000; string Arg3 = "MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF"; verify_case(2, Arg3, order(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 3; string Arg3 = "MFFMMFFMFM"; verify_case(3, Arg3, order(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 245; string Arg3 = "M"; verify_case(4, Arg3, order(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PeopleCircle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
