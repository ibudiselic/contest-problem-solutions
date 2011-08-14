#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool done[1000001];
int getNum(const string &s) {
	int ret = 0;
	for (int i=0; i<(int)s.size(); ++i)
		ret = ret*10 + s[i]-'0';
	return ret;
}
void go(string &s) {
	int num = getNum(s);
	if (done[num])
		return;
	done[num] = 1;

	for (int i=0; i<(int)s.size(); ++i)
		if (s[i] != '0')
			for (int j=i+1; j<(int)s.size(); ++j)
				if (s[j] != '0') {
					swap(s[i], s[j]);
					--s[i]; --s[j];
					go(s);
					++s[i]; ++s[j];
					swap(s[i], s[j]);
				}
}

class RemissiveSwaps {
	public:
	int findMaximum(int N) {
		ostringstream os;
		os << N;

		memset(done, 0, sizeof done);

		string s = os.str();
		go(s);

		for (int i=1000000; i>N; --i)
			if (done[i])
				return i;

		return N;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 166; int Arg1 = 560; verify_case(0, Arg1, findMaximum(Arg0)); }
	void test_case_1() { int Arg0 = 3499; int Arg1 = 8832; verify_case(1, Arg1, findMaximum(Arg0)); }
	void test_case_2() { int Arg0 = 34199; int Arg1 = 88220; verify_case(2, Arg1, findMaximum(Arg0)); }
	void test_case_3() { int Arg0 = 809070; int Arg1 = 809070; verify_case(3, Arg1, findMaximum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RemissiveSwaps ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
