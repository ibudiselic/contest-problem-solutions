#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

vector<string> T;
map< string, vector<string> > trans;
map< pair<string, string>, int > F;
map<pair<int, string>, int> dp;

int go(int x, const string &last) {
	if (x == (int)T.size())
		return 0;

	if (dp.count(make_pair(x, last)))
		return dp[make_pair(x, last)];

	int ret = 0;
	vector<string> &v = trans[T[x]];
	for (int i=0; i<(int)v.size(); ++i) {
		const pair<string, string> t(last, v[i]);
		const int f = F[t];
		ret = max(ret, f + go(x+1, v[i]));
	}
	return dp[make_pair(x, last)] = ret;
}

class ProbabilisticTranslator {
	public:
	int maximumFidelity(vector <string> text, vector <string> dictionary, vector <string> frequencies) {
		T.clear();
		F.clear();
		for (int i=0; i<(int)text.size(); ++i) {
			istringstream is(text[i]);
			string w;
			while (is >> w) {
				T.push_back(w);
				F[make_pair("DUMMY", w)] = 0;
			}
		}
		trans.clear();
		for (int i=0; i<(int)dictionary.size(); ++i) {
			istringstream is(dictionary[i]);
			string w;
			is >> w;
			vector<string> &v = trans[w];
			is >> w;
			assert(w == ":");
			while (is >> w)
				v.push_back(w);
		}
		for (int i=0; i<(int)frequencies.size(); ++i) {
			pair<string, string> t;
			int f;
			istringstream is(frequencies[i]);
			is >> t.first >> t.second >> f;
			F[t] = f;
		}

		dp.clear();
		return go(0, "DUMMY");
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a b c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a : x y", "b : y z", "c : x z"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"y z 20", "x y 10", "z x 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 30; verify_case(0, Arg3, maximumFidelity(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"a b c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a : x y", "b : p q", "c : x y"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"x p 100", "x q 10", "q x 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; verify_case(1, Arg3, maximumFidelity(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"a b", "c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a : x y", "b : p q", "c : x y"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"x p 100", "x q 97", "q x 97"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 194; verify_case(2, Arg3, maximumFidelity(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"a", "bb c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a : a a", "bb : b", "c : c", "ccc : a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"y z 2", "x y 10", "z x 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, maximumFidelity(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ProbabilisticTranslator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
