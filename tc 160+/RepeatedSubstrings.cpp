#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

class RepeatedSubstrings {
	public:
	string decompress(string compressed) {
		string orig;
		vector<int> beg, end;
		map<int, int> ind;

		for (int i=0; i<(int)compressed.size(); ++i) {
			if ('&' == compressed[i]) {
				beg.push_back(0);
				end.push_back(0);
				ind[orig.size()] = beg.size()-1;
				sscanf(compressed.substr(i).c_str(), "&%d-%d", &beg[beg.size()-1], &end[end.size()-1]);
				orig += string(end[end.size()-1]-beg[beg.size()-1]+1, '?');

				++i;
				while (i<(int)compressed.size() && compressed[i]!='&' && !isalpha(compressed[i]) && !isspace(compressed[i]))
					++i;
				--i;
			} else {
				orig += compressed[i];
			}
		}

		string sol = orig;
		bool done = false;

		while (!done) {
			done = true;
			for (int i=0; i<(int)orig.size(); ++i)
				if ('?' == orig[i]) {
					const int t = ind[i];
					for (int j=beg[t]; j<=end[t]; ++j, ++i)
						if (sol[i]=='?' && sol[j]!='?') {
							done = false;
							sol[i] = sol[j];
						}
					--i;
				}
		}
		return sol;
	}







// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDEFG &0-6"; string Arg1 = "ABCDEFG ABCDEFG"; verify_case(0, Arg1, decompress(Arg0)); }
	void test_case_1() { string Arg0 = "AB&7-9&2-6"; string Arg1 = "AB????????"; verify_case(1, Arg1, decompress(Arg0)); }
	void test_case_2() { string Arg0 = "IT WAS THE BE&39-49 &0-10WORST OF TIMES"; string Arg1 = "IT WAS THE BEST OF TIMES IT WAS THE WORST OF TIMES"; verify_case(2, Arg1, decompress(Arg0)); }
	void test_case_3() { string Arg0 = "ABC&0-21"; string Arg1 = "ABCABCABCABCABCABCABCABCA"; verify_case(3, Arg1, decompress(Arg0)); }
	void test_case_4() { string Arg0 = "&0-10"; string Arg1 = "???????????"; verify_case(4, Arg1, decompress(Arg0)); }
	void test_case_5() { string Arg0 = "&5-9ABC&2-7DE&20-22&17-19F"; string Arg1 = "ABCCCABCCCCABCDEF?F?F?F"; verify_case(5, Arg1, decompress(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RepeatedSubstrings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
