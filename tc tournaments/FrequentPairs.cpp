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

int cnt(char a, char b, const vector<string> &v) {
	int ret = 0;

	for (int i=0; i<(int)v.size(); ++i) {
		string s;
		s += a;
		s += b;
		for (int j=0; j+2<=(int)v[i].size(); ++j)
			ret += v[i].substr(j, 2)==s;

		if (a != b) {
			reverse(s.begin(), s.end());
			for (int j=0; j+2<=(int)v[i].size(); ++j)
				ret += v[i].substr(j, 2)==s;
		}
	}

	return ret;
}
class FrequentPairs {
	public:
	int mostFrequent(vector <string> words) {
		set<char> C;

		for (int i=0; i<(int)words.size(); ++i)
			for (int j=0; j<(int)words[i].size(); ++j)
				C.insert(words[i][j]);

		vector<char> CC(C.begin(), C.end());

		int sol = 0;
		for (int i=0; i<(int)CC.size(); ++i)
			for (int j=i; j<(int)CC.size(); ++j)
				sol = max(sol, cnt(CC[i], CC[j], words));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"attach", "tatoo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, mostFrequent(Arg0)); }
	void test_case_1() { string Arr0[] = {"boo","boom","cool"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, mostFrequent(Arg0)); }
	void test_case_2() { string Arr0[] = {"aaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, mostFrequent(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FrequentPairs ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
