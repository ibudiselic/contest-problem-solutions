#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <functional>

using namespace std;

class MakeUnique {
	public:
	string eliminated(string original) {
		set<char, greater<char> > c(original.begin(), original.end());

		int best = -1;
		int bestdist = 10000;
		reverse(original.begin(), original.end());
		for (int i=0; i<(int)original.size(); ++i)
			if (*(c.begin()) == original[i]) {
				int j = i;
				for (set<char>::const_iterator it=c.begin(); ++it!=c.end(); ) {
					for (++j; j<(int)original.size() && original[j]!=*it; ++j)
						continue;
					if (j == (int)original.size())
						goto lose;
				}
				if (j-i < bestdist) {
					bestdist = j-i;
					best = i;
				}
				lose: ;
			}

		if (-1 == best)
			return string();

		string sol(original.size(), '.');
		sol[best] = *(c.begin());
		int i=best;
		for (set<char>::const_iterator it=c.begin(); ++it!=c.end();) {
			for (++i; i<(int)original.size() && original[i]!=*it; ++i)
				continue;
			assert(i < (int)original.size());
			sol[i] = *it;
		}
		reverse(sol.begin(), sol.end());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABBBXCXABCX"; string Arg1 = ".......ABCX"; verify_case(0, Arg1, eliminated(Arg0)); }
	void test_case_1() { string Arg0 = "ABBBXCXABCB"; string Arg1 = "A..B.CX...."; verify_case(1, Arg1, eliminated(Arg0)); }
	void test_case_2() { string Arg0 = "ABBBXCABCB"; string Arg1 = ""; verify_case(2, Arg1, eliminated(Arg0)); }
	void test_case_3() { string Arg0 = "AABACBXABX"; string Arg1 = ".AB.C.X..."; verify_case(3, Arg1, eliminated(Arg0)); }
	void test_case_4() { string Arg0 = "CABDEAFDEGSDABCDEADFGSEFBGS"; string Arg1 = "............ABCDE..FGS....."; verify_case(4, Arg1, eliminated(Arg0)); }
	void test_case_5() { string Arg0 = "AAAAAA"; string Arg1 = ".....A"; verify_case(5, Arg1, eliminated(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MakeUnique ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
