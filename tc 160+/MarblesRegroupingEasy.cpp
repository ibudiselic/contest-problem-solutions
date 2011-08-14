#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MarblesRegroupingEasy {
	public:
	int minMoves(vector <string> boxes) {
		int sol = 123456789;
		for (int x=0; x<(int)boxes.size(); ++x) {
			int cur = 0;
			long long mask = 0;
			for (int i=0; i<(int)boxes.size(); ++i) {
				if (i != x) {
					int cnt = 0;
					int jj = -1;
					for (int j=0; j<(int)boxes[i].size(); ++j) {
						if (boxes[i][j] != '0') {
							++cnt;
							jj = j;
						}
					}
					if (cnt == 0) {
						continue;
					} else if (cnt == 1) {
						if (mask & (1<<jj)) {
							++cur;
						} else {
							mask |= (1<<jj);
						}
					} else {
						++cur;
					}
				}
			}

			sol = min(sol, cur);
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"20",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"11",
 "11",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"10",
 "10",
 "01",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"11",
 "11",
 "11",
 "10",
 "10",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"020008000070",
 "000004000000",
 "060000600000",
 "006000000362",
 "000720000000",
 "000040000000", 
 "004009003000",
 "000800000000", 
 "020030003000",
 "000500200000",
 "000000300000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, minMoves(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MarblesRegroupingEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
