#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;
string S;
bool has(int i, const string &patt) {
	if (i+patt.size() > S.size())
		return false;
	return S.substr(i, patt.size()) == patt;
}

bool done[1024][501];
queue< pair<int, int> > Q;
void check(int i, int nc) {
	if (nc>=0 && !done[i][nc]) {
		done[i][nc] = true;
		Q.push(make_pair(i, nc));
	}
}
int go(int x) {
	memset(done, 0, sizeof done);
	done[x][1] = 1;
	Q.push(make_pair(x, 1));

	int ret = -1;
	while (!Q.empty()) {
		int i = Q.front().first;
		int nc = Q.front().second;
		Q.pop();

		if (nc == 0) {
			ret = max(ret, i);
			continue;
		}
		if (i+1 > (int)S.size())
			continue;

		if (has(i, "*/*")) {
			check(i+2, nc-1);
			check(i+3, nc+1);
		} else if (has(i, "/*/")) {
			check(i+2, nc+1);
			check(i+3, nc-1);
		} else if (has(i, "*/")) {
			check(i+2, nc-1);
		} else if (has(i, "/*")) {
			check(i+2, nc+1);
		} else {
			check(i+1, nc);
		}
	}

	return ret;
}

class CommentNest {
	public:
	int whatsLeft(vector <string> lines) {
		S.clear();
		for (int i=0; i<(int)lines.size(); ++i)
			S += lines[i]+'n';

		while (true) {
			for (int i=0; i+2<(int)S.size(); ++i)
				if (has(i, "/*")) {
					int j = go(i+2);
					if (j != -1) {
						string S_;
						for (int k=0; k<i; ++k)
							S_ += S[k];
						for (int k=j; k<(int)S.size(); ++k)
							S_ += S[k];
						S.swap(S_);
						goto AGAIN;
					}
				}

			break;
			AGAIN: ;
		}

		return S.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"abc","def"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, whatsLeft(Arg0)); }
	void test_case_1() { string Arr0[] = {"a//bc/*/d",  "", "x/*/b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, whatsLeft(Arg0)); }
	void test_case_2() { string Arr0[] = {"a/***b///**/*/"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, whatsLeft(Arg0)); }
	void test_case_3() { string Arr0[] = {"/*/*/abc//*xyz*/*" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, whatsLeft(Arg0)); }
	void test_case_4() { string Arr0[] = {"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*", "/*abc*/"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, whatsLeft(Arg0)); }
	void test_case_5() { string Arr0[] = {"*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/",
 "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, whatsLeft(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CommentNest ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
