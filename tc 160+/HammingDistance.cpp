#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(const string &a, const string &b) {
	int ret = 0;
	for (int i=0; i<(int)a.size(); ++i)
		ret += (a[i]!=b[i]);

	return ret;
}
class HammingDistance {
	public:
	int minDistance(vector <string> numbers) {
		int sol = 1234567890;
		for (int i=0; i<(int)numbers.size(); ++i)
			for (int j=i+1; j<(int)numbers.size(); ++j)
				sol = min(sol, calc(numbers[i], numbers[j]));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11010", "01100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minDistance(Arg0)); }
	void test_case_1() { string Arr0[] = {"00", "01", "10", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minDistance(Arg0)); }
	void test_case_2() { string Arr0[] = {"000", "011", "101", "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minDistance(Arg0)); }
	void test_case_3() { string Arr0[] = {"01100", "01100", "10011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, minDistance(Arg0)); }
	void test_case_4() { string Arr0[] = {"00000000000000000000000000000000000000000000000000",
"11111111111111111111111111111111111111111111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(4, Arg1, minDistance(Arg0)); }
	void test_case_5() { string Arr0[] = {"000000", "000111", "111000", "111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, minDistance(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HammingDistance ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
