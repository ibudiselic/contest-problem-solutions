#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class SimpleIO {
	public:
	int worstCase(string pattern, int targetState) {
		int n = pattern.size();
		vector<bool> done(n, false);

		string s = pattern;
		for (int i=0; i<2; ++i)
			s += pattern;

		int left = n;
		int sol = 0;
		for (int l=1; left>0 && l<=2*n; ++l) {
			map<string, vector<int> > M;
			for (int i=0; i<n; ++i)
				if (!done[i]) {
					/*cerr << i << " :: " << s.substr(i, l) << '\n';*/
					M[s.substr(i, l)].push_back(i);
				}

			for (map<string, vector<int> >::const_iterator it=M.begin(); it!=M.end(); ++it) {
				const vector<int> &v = it->second;

				if (v.size() == 1u) {
					done[v[0]] = 1;
					--left;
					/*if (l + (targetState + n - (v[0]+l)%n)%n > sol)
						cerr << "novi maksimum: " << v[0] << ' ' << l << '\n';*/
					sol = max(sol, l + (targetState + n - (v[0]-1+l)%n)%n);
				}
			}
		}

		return left==0 ? sol : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BNB"; int Arg1 = 0; int Arg2 = 4; verify_case(0, Arg2, worstCase(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BNBNBNBN"; int Arg1 = 3; int Arg2 = -1; verify_case(1, Arg2, worstCase(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BBNNBNBBBBNBBBBBB"; int Arg1 = 3; int Arg2 = 18; verify_case(2, Arg2, worstCase(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SimpleIO ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
