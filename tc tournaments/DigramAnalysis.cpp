#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

class DigramAnalysis {
	public:
	string mostFrequent(vector <string> chunks) {
		string s;

		for (int i=0; i<(int)chunks.size(); ++i)
			s += chunks[i];

		vector<string> W;
		string w;
		istringstream is(s);
		while (is >> w)
			W.push_back(w);

		set<string> dg;

		for (int i=0; i<(int)W.size(); ++i)
			for (int j=0; j<(int)W[i].size()-1; ++j)
				dg.insert(W[i].substr(j, 2));

		string best = "aa";
		int cnt = 0;

		for (set<string>::const_iterator it=dg.begin(); it!=dg.end(); ++it) {
			int cur = 0;
			for (int i=0; i<(int)W.size(); ++i)
				cur += (W[i].find(*it) != string::npos);

			if (cur > cnt) {
				cnt = cur;
				best = *it;
			}
		}

		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"coder decoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "co"; verify_case(0, Arg1, mostFrequent(Arg0)); }
	void test_case_1() { string Arr0[] = {"abracadabra cat"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ca"; verify_case(1, Arg1, mostFrequent(Arg0)); }
	void test_case_2() { string Arr0[] = {"cat mouse mouse mouse"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "mo"; verify_case(2, Arg1, mostFrequent(Arg0)); }
	void test_case_3() { string Arr0[] = {"i", "i"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ii"; verify_case(3, Arg1, mostFrequent(Arg0)); }
	void test_case_4() { string Arr0[] = {" hello world "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "el"; verify_case(4, Arg1, mostFrequent(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DigramAnalysis ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
