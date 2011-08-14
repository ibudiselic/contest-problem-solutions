#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TournamentsAmbiguityNumber {
	public:
	int scrutinizeTable(vector <string> table) {
		int n = table.size();
		int sol = 0;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				for (int k=0; k<n; ++k)
					if (table[i][j]=='1' && table[j][k]=='1' && table[k][i]=='1')
						++sol;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-10",
 "0-1",
 "10-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, scrutinizeTable(Arg0)); }
	void test_case_1() { string Arr0[] = {"----",
 "----",
 "----",
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, scrutinizeTable(Arg0)); }
	void test_case_2() { string Arr0[] = {"-1",
 "0-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, scrutinizeTable(Arg0)); }
	void test_case_3() { string Arr0[] = {"--1-10-1---1--1-00",
 "--0110000--0---10-",
 "01--00000100-00011",
 "-0---0010-11110100",
 "001--01-00-0001-1-",
 "11111--100--1-1-01",
 "-1110--00110-11-01",
 "0110-01--100110-10",
 "-111111---01--0-01",
 "--0-1100----10011-",
 "--10--011--1--101-",
 "01101-110-0--1-0-1",
 "---010-0-0---00-11",
 "--101-00-1-01-0-0-",
 "0-110001110-11-110",
 "-010-----011--0--0",
 "11010110100-010--0",
 "1-01-0010--00-111-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 198; verify_case(3, Arg1, scrutinizeTable(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TournamentsAmbiguityNumber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
