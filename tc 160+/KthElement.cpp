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

int F(int x) {
	int ret = 0;
	while (x > 0) {
		++ret;
		x &= (x-1);
	}

	return ret;
}
class KthElement {
	public:
	int find(int A, int B, int K) {
		vector<int> v;
		map<int, int> pos;

		v.push_back(0);
		pos[0] = 0;
		for (int i=1; i<=K; ++i) {
			int t = F(v.back());
			v.push_back(A*t + B);
			t = v.back();
			if (pos.count(t)) {
				int x = i-pos[t];
				return v[pos[t] + (K-pos[t])%x];
			} else {
				pos[t] = i;
			}
		}

		return v.back();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 12; int Arg2 = 5; int Arg3 = 12; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 7; int Arg2 = 15; int Arg3 = 9; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 21; int Arg2 = 500000001; int Arg3 = 51; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 79; int Arg1 = 4; int Arg2 = 700000000; int Arg3 = 478; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 293451; int Arg1 = 765339; int Arg2 = 900000000; int Arg3 = 3993300; verify_case(4, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    KthElement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
