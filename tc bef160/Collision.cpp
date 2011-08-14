#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Collision {
	public:
	double probability(vector <int> br, int ids) {
		double k=ids;
		double p1, p2;
		p1 = p2 = 1.0;

		for (vector<int>::size_type i=0; i<br.size(); ++i) {
			if (br[i] > ids) return 0.0;
			int n = ids;
			for (int j=0; j<br[i]; ++j) {
				p1 *= k/ids;
				p2 *= k--/n--;
			}
		}
		return p2 - p1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {20,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; double Arg2 = 0.2113618990410422; verify_case(0, Arg2, probability(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {123,456}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 123456; double Arg2 = 0.3769052883184334; verify_case(1, Arg2, probability(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2147483647; double Arg2 = 0.0069090268185510555; verify_case(2, Arg2, probability(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1005,1005}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; double Arg2 = 0.0; verify_case(3, Arg2, probability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Collision ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
