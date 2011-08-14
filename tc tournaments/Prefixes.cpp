#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Group {
	int pSz;
	vector<string> w;
};
bool operator<(const Group &a, const Group &b) {
	if (a.pSz != b.pSz)
		return a.pSz > b.pSz;
	return a.w[0].substr(0, a.pSz) < b.w[0].substr(0, b.pSz);
}
bool sw(const string &a, const string &b) {
	if (b.size() > a.size())
		return false;
	for (int i=0; i<(int)b.size(); ++i)
		if (a[i] != b[i])
			return false;
	return true;
}
class Prefixes {
	public:
	vector <string> prefixList(vector <string> v) {
		vector<Group> g;

		sort(v.begin(), v.end());
		while (v.size() > 1) {
			for (int len=50; len>0; --len) {
				for (int i=0; i+1<(int)v.size(); ++i)
					if (len <= (int)v[i].size()) {
						int j = i+1;
						const string &s = v[i].substr(0, len);
						while (j<(int)v.size() && sw(v[j], s))
							++j;
						if (j > i+1) {
							g.push_back(Group());
							g.back().pSz = len;
							for (int k=i; k<j; ++k)
								g.back().w.push_back(v[k]);
							sort(g.back().w.begin(), g.back().w.end());

							vector<string> t;
							for (int k=0; k<i; ++k)
								t.push_back(v[k]);
							for (int k=j; k<(int)v.size(); ++k)
								t.push_back(v[k]);
							v.swap(t);

							goto FOUND_SOME;
						}
					}
			}
			// zero prefix
			g.push_back(Group());
			g.back().pSz = 0;
			for (int i=0; i<(int)v.size(); ++i)
				g.back().w.push_back(v[i]);
			sort(g.back().w.begin(), g.back().w.end());
			v.clear();

			FOUND_SOME: ;
		}
		if (v.size() == 1) {
			g.push_back(Group());
			g.back().pSz = 0;
			g.back().w.push_back(v[0]);
		}

		sort(g.begin(), g.end());

		vector<string> sol;
		for (int i=0; i<(int)g.size(); ++i) {
			for (int j=0; j<(int)g[i].w.size(); ++j)
				sol.push_back(g[i].w[j]);
			sol.push_back(string(g[i].pSz, '-'));
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"AAAAA","ABCDE","ABCDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABCDE", "ABCDE", "-----", "AAAAA", "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, prefixList(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABCDE", "ABCDXY", "ABC", "ABD", "ARX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABCDE", "ABCDXY", "----", "ABC", "ABD", "--", "ARX", "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, prefixList(Arg0)); }
	void test_case_2() { string Arr0[] = {"XA","AX","XB","A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A", "AX", "-", "XA", "XB", "-" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, prefixList(Arg0)); }
	void test_case_3() { string Arr0[] = {"XA","AX","YXB","A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A", "AX", "-", "XA", "YXB", "" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, prefixList(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Prefixes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
