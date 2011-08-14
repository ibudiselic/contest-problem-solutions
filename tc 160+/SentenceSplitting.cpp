#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
vector<string> tokenize_to_string(const string &s, const char delim=' ') {
	vector<string> ret;

	string t;
	for (string::size_type i=0; i<s.size(); ++i) {
		if (s[i]==delim) {
			ret.push_back(t);
			t.clear();
		} else {
			t += s[i];
		}
	}
	ret.push_back(t);

	return ret;
}

class SentenceSplitting {
	public:
	int split(string sentence, int K) {
		vector<string> words = tokenize_to_string(sentence);
		words.push_back(string(100, ' '));

		for (int sol=1; sol<=(int)sentence.size(); ++sol) {
			int cur = 0;
			int cnt = 0;
			for (int i=0; i<(int)words.size()-1; ++i) {
				if ((int)words[i].size() > sol) goto skip;
				if (cur + (int)words[i].size() + (cur!=0) > sol) {
					++cnt;
					cur = words[i].size();
				} else {
					cur += (int)words[i].size() + (cur!=0);
				}
			}
			if (cnt <= K) return sol;
			skip: ;
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "This is a test sentence"; int Arg1 = 1; int Arg2 = 13; verify_case(0, Arg2, split(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "TheOnlyWord"; int Arg1 = 37; int Arg2 = 11; verify_case(1, Arg2, split(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "One veeeeeeeeeeeeeeeeeeery long word"; int Arg1 = 2; int Arg2 = 22; verify_case(2, Arg2, split(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "Each tournament round is an elimination round"; int Arg1 = 3; int Arg2 = 15; verify_case(3, Arg2, split(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SentenceSplitting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
