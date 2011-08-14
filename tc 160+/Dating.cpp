#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

class Dating {
	public:
	bool samesex(char c, char cc) {
		return islower(c)==islower(cc);
	}
	string dates(string circle, int k) {
		string sol;
		int cur = 0;
		bool space = false;
		while (circle.size() != 0) {
			int best = 130;
			int besti = -1;
			cur = (cur+(k-1))%circle.size();
			for (int i=0; i<(int)circle.size(); ++i)
				if (!samesex(circle[cur], circle[i]) && circle[i]<best) {
					best = circle[i];
					besti = i;
				}
			if (besti == -1)
				break;
			if (space) sol += ' ';
			space = true;
			sol += circle[cur];
			sol += circle[besti];
			if (besti < cur) {
				circle.erase(circle.begin()+besti);
				--cur;
				circle.erase(circle.begin()+cur);
			} else {
				circle.erase(circle.begin()+cur);
				circle.erase(circle.begin()+(besti-1));
			}
			if (circle.size() > 0)
				cur %= circle.size();
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abXCd"; int Arg1 = 2; string Arg2 = "bC dX"; verify_case(0, Arg2, dates(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abXCd"; int Arg1 = 8; string Arg2 = "Xa dC"; verify_case(1, Arg2, dates(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "HGFhgfz"; int Arg1 = 1; string Arg2 = "Hf Gg Fh"; verify_case(2, Arg2, dates(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Dating ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
