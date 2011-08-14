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

int pos[1<<22];
int cnt[1<<22];
class LongLongNim {
	public:
	int numberOfWins(int maxN, vector <int> moves) {
		memset(pos, 0, sizeof pos);
		const int n = moves.size();
		int cur = 0;

		int state = (1<<22)-2;
		for (int i=0; i<n; ++i)
			--moves[i];

		bool cyc = 0;
		for (int x=1; x<=maxN; ++x) {
			int next = 0;
			for (int i=0; i<n; ++i)
				next |= !((state>>moves[i])&1);

			cur += !next;
			state = ((state<<1)+next)&0x3fffff;

			if (!cyc && pos[state]) {
				cyc = 1;
				int len = x-pos[state];
				int val = cur-cnt[state];
				int k = (maxN-x)/len;
				cur += k*val;
				x += k*len;
			} else {
				pos[state] = x;
				cnt[state] = cur;
			}
		}
		return cur;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, numberOfWins(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 999; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 499; verify_case(1, Arg2, numberOfWins(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000000000; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 333333333; verify_case(2, Arg2, numberOfWins(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6543; int Arr1[] = {2,4,7,11,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1637; verify_case(3, Arg2, numberOfWins(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LongLongNim ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
