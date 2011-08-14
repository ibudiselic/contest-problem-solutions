#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

struct state {
	int pos, a, b, c, last, prelast;
	state(int pos_, int a_, int b_, int c_, int last_, int prelast_): pos(pos_), a(a_), b(b_), c(c_), last(last_), prelast(prelast_) {}
};
bool operator<(const state &x, const state &y) {
	if (x.pos != y.pos)
		return x.pos < y.pos;
	else if (x.a != y.a)
		return x.a < y.a;
	else if (x.b != y.b)
		return x.b < y.b;
	else if (x.c != y.c)
		return x.c < y.c;
	else if (x.last != y.last)
		return x.last < y.last;
	else
		return x.prelast < y.prelast;
}

map<state, int> M;
vector<int> B;
int go(int pos, int a, int b, int c, int last, int prelast) {
	if (pos == (int)B.size())
		return 0;

	state cur(pos, a, b, c, last, prelast);
	if (M.count(cur))
		return M[cur];

	int &ret = M[cur];

	ret = -1;

	if (a > 0) {
		if (last!=0 || last!=prelast) {
			int t = go(pos+1, a-1, b, c, 0, last);
			if (t >= 0)
				ret = max(ret, t + (B[pos]==0));
		}
	}
	if (b > 0) {
		if (last!=1 || last!=prelast) {
			int t = go(pos+1, a, b-1, c, 1, last);
			if (t >= 0)
				ret = max(ret, t + (B[pos]==1));
		}
	}
	if (c > 0) {
		if (last!=2 || last!=prelast) {
			int t = go(pos+1, a, b, c-1, 2, last);
			if (t >= 0)
				ret = max(ret, t + (B[pos]==2));
		}
	}

	return ret;
}
class BoxesArrangement {
	public:
	int maxUntouched(string boxes) {
		B.clear();
		for (int i=0; i<(int)boxes.size(); ++i)
			B.push_back(boxes[i]-'A');

		int a = count(B.begin(), B.end(), 0);
		int b = count(B.begin(), B.end(), 1);
		int c = count(B.begin(), B.end(), 2);

		M.clear();
		return go(0, a, b, c, -1, -1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAABBBCCC"; int Arg1 = 6; verify_case(0, Arg1, maxUntouched(Arg0)); }
	void test_case_1() { string Arg0 = "AAAAAAAACBB"; int Arg1 = 7; verify_case(1, Arg1, maxUntouched(Arg0)); }
	void test_case_2() { string Arg0 = "CCCCCB"; int Arg1 = -1; verify_case(2, Arg1, maxUntouched(Arg0)); }
	void test_case_3() { string Arg0 = "BAACAABAACAAA"; int Arg1 = 5; verify_case(3, Arg1, maxUntouched(Arg0)); }
	void test_case_4() { string Arg0 = "CBBABA"; int Arg1 = 6; verify_case(4, Arg1, maxUntouched(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BoxesArrangement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
