#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(const vector<string> &v) {
	vector<string> cw(30, string(30, ' '));

	bool haveLeft = false;
	bool haveTop = false;
	const string &a = v[0];
	const string &b = v[1];
	const string &c = v[2];
	const string &d = v[3];
	int asz = v[0].size();
	int bsz = v[1].size();
	int csz = v[2].size();
	int dsz = v[3].size();
	int vdist = (int)v[2].size() + (int)v[3].size() - 3;
	int hdist = (int)v[0].size() + (int)v[1].size() - 3;

	if (vdist<3 || hdist<3)
		return 0;

	int ret = 0;

	for (int ai=0; ai<vdist-2; ++ai)
		for (int aj=0; aj<bsz-2; ++aj) {
			haveLeft = (aj==0);
			for (int bi=ai+2; bi<vdist; ++bi)
				for (int bj=0; (!haveLeft && bj<1) || (haveLeft && bj<asz-2); ++bj)
					for (int ci=0; ci<=ai; ++ci) {
						haveTop = (ci==0);
						if (ci+csz > bi)
							for (int cj=max(aj, bj); cj<max(aj+asz, bj+bsz)-2; ++cj)
								for (int di=0; (!haveTop && di<1) || (haveTop && di<=ai); ++di)
									if (di+dsz > bi)
										for (int dj=cj+2; dj<min(aj+asz, bj+bsz); ++dj)
											ret += (a[cj-aj]==c[ai-ci] && a[dj-aj]==d[ai-di] && b[cj-bj]==c[bi-ci] && b[dj-bj]==d[bi-di]);
					}
		}

	return ret;
}
class LatticeCrossword {
	public:
	int crossword(string a, string b, string c, string d) {
		vector<string> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);

		sort(v.begin(), v.end());

		int sol = 0;
		do {
			sol += calc(v);
		} while (next_permutation(v.begin(), v.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoder"; string Arg1 = "contest"; string Arg2 = "problem"; string Arg3 = "solution"; int Arg4 = 2; verify_case(0, Arg4, crossword(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "coder"; string Arg1 = "number"; string Arg2 = "rober"; string Arg3 = "joker"; int Arg4 = 0; verify_case(1, Arg4, crossword(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "lattice"; string Arg1 = "crossword"; string Arg2 = "disticnt"; string Arg3 = "approach"; int Arg4 = 4; verify_case(2, Arg4, crossword(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "zaxb"; string Arg1 = "axc"; string Arg2 = "cxd"; string Arg3 = "bxdy"; int Arg4 = 2; verify_case(3, Arg4, crossword(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaa"; string Arg1 = "aaaaaaaaaaaaba"; string Arg2 = "aaaaaaaaaaaaaab"; string Arg3 = "baaaaaaaaaaaaaa"; int Arg4 = 10082176; verify_case(4, Arg4, crossword(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LatticeCrossword ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
