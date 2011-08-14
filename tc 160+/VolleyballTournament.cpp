#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool testPoss(int w, int l, int ws, int ls) {
	if (w<0 || l<0 || ws<0 || ls<0)
		return false;

	ws -= 3*w;
	ls -= 3*l;

	if (ws>=0 && ls>=0 && ws<=l*2 && ls<=w*2)
		return true;

	return false;
}
class VolleyballTournament {
	public:
	string reconstructResults(int wonMatches, int lostMatches, int wonSets, int lostSets) {
		int wPoss = 0;
		int lPoss = 0;
		vector<string> v;
		vector<bool> isWin;
		for (int i=0; i<=3; ++i)
			for (int j=0; j<=3; ++j)
				if ((i==3 || j==3) && i!=j)
					if (testPoss(wonMatches-(i>j), lostMatches-(j>i), wonSets-i, lostSets-j)) {
						wPoss += (i>j);
						lPoss += (j>i);
						ostringstream os;
						os << i << '-' << j << '\n';
						v.push_back(os.str());
						isWin.push_back(i>j);
					}



		if (wPoss>2 || lPoss>2) {
			return "AMBIGUITY";
		} else {
			string sol;
			bool first = 1;
			for (int i=0; i<=3; ++i)
				for (int j=0; j<=3; ++j)
					if ((i==3 || j==3) && i!=j)
						while (testPoss(wonMatches-(i>j), lostMatches-(j>i), wonSets-i, lostSets-j)) {
							if (!first)
								sol += ',';
							first = 0;
							sol += char(i+'0');
							sol += '-';
							sol += char(j+'0');

							wonMatches -= (i>j);
							lostMatches -= (j>i);
							wonSets -= i;
							lostSets -= j;
						}

			return sol;
		}
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 9; int Arg3 = 9; string Arg4 = "0-3,0-3,0-3,3-0,3-0,3-0"; verify_case(0, Arg4, reconstructResults(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 3; int Arg2 = 6; int Arg3 = 9; string Arg4 = "2-3,2-3,2-3"; verify_case(1, Arg4, reconstructResults(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 9; int Arg3 = 3; string Arg4 = "AMBIGUITY"; verify_case(2, Arg4, reconstructResults(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 4; int Arg3 = 4; string Arg4 = "1-3,3-1"; verify_case(3, Arg4, reconstructResults(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VolleyballTournament ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
