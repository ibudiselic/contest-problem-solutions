#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ZeroesAndOnesGrid {
	public:
	int minMovesCount(vector <string> table) {
		int m = table.size();
		int n = table[0].size();

		int sol = 0;
		while (1) {
			for (int i=m-1; i>=0; --i)
				for (int j=n-1; j>=0; --j)
					if (table[i][j] == '1') {
						++sol;
						for (int y=0; y<=i; ++y)
							for (int x=0; x<=j; ++x)
								table[y][x] = 1-(table[y][x]-'0')+'0';
						goto NEXT;
					}
			break;
			NEXT: ;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0000",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minMovesCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"11111",
 "11111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minMovesCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"01",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minMovesCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"00",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minMovesCount(Arg0)); }
	void test_case_4() { string Arr0[] = {"010101011010000101010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(4, Arg1, minMovesCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ZeroesAndOnesGrid ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
