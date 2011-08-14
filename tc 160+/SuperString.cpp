#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;


int bc_[1<<13];
const int mask = (1<<13)-1;
int bc(int x) {
	return bc_[x & mask] + bc_[(x>>13) & mask];
}
class SuperString {
	public:
	string goodnessSubstring(vector <string> superstring) {
		string s;
		for (int i=0; i<(int)superstring.size(); ++i)
			s += superstring[i];

		bc_[0] = 0;
		for (int i=1; i<(1<<13); ++i)
			bc_[i] = bc_[i>>1] + (i&1);

		int best = 0;
		vector< pair<int, int> > cand;
		for (int i=0; i<(int)s.size(); ++i) {
			bool havePrefix = false;
			if (best < 1) {
				best = 1;
				cand.clear();
				cand.push_back(make_pair(i, 1));
				havePrefix = true;
			} else if (best == 1) {
				cand.push_back(make_pair(i, 1));
				havePrefix = true;
			}
			int haveMore = 0;
			int haveOne = (1<<(s[i]-'A'));

			for (int j=1; i+j<(int)s.size(); ++j) {
				const int m = (1<<(s[i+j]-'A'));
				if (haveOne & m) {
					haveOne ^= m;
					haveMore ^= m;
				} else if ((haveMore & m) == 0) {
					haveOne |= m;
				}

				const int t = bc(haveOne);
				if (t > best) {
					best = t;
					cand.clear();
					cand.push_back(make_pair(i, j+1));
					havePrefix = true;
				} else if (t==best && !havePrefix) {
					havePrefix = true;
					cand.push_back(make_pair(i, j+1));
				}
			}
		}

		random_shuffle(cand.begin(), cand.end());
		string sol = string(100, 'Z');
		for (int i=0; i<(int)cand.size(); ++i) {
			const string &t = s.substr(cand[i].first, cand[i].second);
			if (t < sol)
				sol = t;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CHALLENGE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CHALLENG"; verify_case(0, Arg1, goodnessSubstring(Arg0)); }
	void test_case_1() { string Arr0[] = {"THEWORD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "THEWORD"; verify_case(1, Arg1, goodnessSubstring(Arg0)); }
	void test_case_2() { string Arr0[] = {"THE", "MULTI", "LINE", "TEST"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "HEMULTI"; verify_case(2, Arg1, goodnessSubstring(Arg0)); }
	void test_case_3() { string Arr0[] = {"ZYXWVUTSRQPONMLKJIHGFEDCBA", "ZYXWVUTSRQPONMLKJIHGFEDCBA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AZYXWVUTSRQPONMLKJIHGFEDCB"; verify_case(3, Arg1, goodnessSubstring(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SuperString ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
