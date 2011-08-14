#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int val(const vector<string> &S, int i, int j) {
	char a = S[i][j];
	int ret = 0;
	if (i+1 < (int)S.size()) {
		char b = S[i+1][j];
		ret += (a!=b)-(a==b);
	}
	if (j+1 < (int)S[0].size()) {
		char b = S[i][j+1];
		ret += (a!=b)-(a==b);
	}
	return ret;
}
class IsingModel {
	public:
	int energy(vector <string> spins) {
		int m = spins.size();
		int n = spins[0].size();
		int E = 0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				E += val(spins, i, j);

		return E;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-++",
 "+-+"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, energy(Arg0)); }
	void test_case_1() { string Arr0[] = {"+"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, energy(Arg0)); }
	void test_case_2() { string Arr0[] = {"++-+",
 "-++-",
 "+-+-",
 "++++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, energy(Arg0)); }
	void test_case_3() { string Arr0[] = {"----",
 "---+",
 "-+++",
 "++++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -12; verify_case(3, Arg1, energy(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IsingModel ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
