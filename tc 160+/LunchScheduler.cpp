#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class LunchScheduler {
	public:
	int getOverlap(vector <string> M) {
		int sol = 1000000;

		vector<int> order;
		for (int i=0; i<(int)M.size(); ++i)
			order.push_back(i);

		do {
			vector<bool> left(M.size(), false);
			int o_best = 0;
			int cur = 0;
			for (int t=0; t<(int)M.size(); ++t) {
				++cur;
				o_best = max(o_best, cur);
				for (int i=0; i<=t; ++i)
					if (!left[i]) {
						bool leave = true;
						for (int j=t+1; j<(int)M.size(); ++j)
							if (M[order[i]][order[j]] == '1') {
								leave = false;
								break;
							}
						if (leave) {
							left[i] = true;
							--cur;
						}
					}
			}
			sol = min(sol, o_best);
		} while (next_permutation(order.begin(), order.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0110",
 "1010",
 "1100",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getOverlap(Arg0)); }
	void test_case_1() { string Arr0[] = {"011111",
 "101111",
 "110111",
 "111011",
 "111101",
 "111110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, getOverlap(Arg0)); }
	void test_case_2() { string Arr0[] = {"01000000",
 "10000000",
 "00000000",
 "00000000",
 "00000000",
 "00000000",
 "00000001",
 "00000010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getOverlap(Arg0)); }
	void test_case_3() { string Arr0[] = {"011011010",
 "101000111",
 "110010110",
 "000001101",
 "101001000",
 "100110101",
 "011101010",
 "111000100",
 "010101000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, getOverlap(Arg0)); }
	void test_case_4() { string Arr0[] = {"000",
 "000",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getOverlap(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LunchScheduler ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
