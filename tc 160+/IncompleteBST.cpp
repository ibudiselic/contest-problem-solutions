#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char tree[1u<<20];
bool valid(int i, int m, int M) {
	const int left = 2*i;
	const int right = 2*i + 1;

	if (tree[i]<m || tree[i]>M
		||
		left<(1<<20) && tree[left]!=0 && !valid(left, m, (int)tree[i])
		||
		right<(1<<20) && tree[right]!=0 && !valid(right, tree[i]+1, M))
		return false;

	return true;
}
class IncompleteBST {
	public:
	string missingValues(vector <string> T) {
		memset(tree, 0, sizeof tree);
		int missing = -1;

		for (int i=0; i<(int)T.size(); ++i) {
			char c;
			int x;
			istringstream is(T[i]);
			is >> c >> x;
			if (c == '?')
				missing = x;
			else
				tree[x] = c;
		}
		assert(missing != -1);

		string sol;
		for (int i='A'; i<='Z'; ++i) {
			tree[missing] = i;
			if (valid(1, 'A', 'Z'))
				sol += char(i);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A 1", "? 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; verify_case(0, Arg1, missingValues(Arg0)); }
	void test_case_1() { string Arr0[] = {"B 1", "? 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AB"; verify_case(1, Arg1, missingValues(Arg0)); }
	void test_case_2() { string Arr0[] = {"V 1", "? 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WXYZ"; verify_case(2, Arg1, missingValues(Arg0)); }
	void test_case_3() { string Arr0[] = {"K 1", "K 2", "A 6", "? 12", "Y 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(3, Arg1, missingValues(Arg0)); }
	void test_case_4() { string Arr0[] = {"Z 1", "Y 2", "X 4", "W 8", "V 16", "U 32", "T 64", "S 128", "R 256", "Q 512",
"P 1024", "O 2048", "N 4096", "M 8192", "L 16384", "K 32768", "J 65536", "? 131072"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCDEFGHIJ"; verify_case(4, Arg1, missingValues(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IncompleteBST ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
