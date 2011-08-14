#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

bool have[100000];
class OddDigitable {
	public:
	string findMultiple(int N, int M) {
		memset(have, 0, sizeof have);
		queue< pair<int, string> > Q;
		Q.push(make_pair(0, ""));

		while (!Q.empty()) {
			const pair<int, string> t = Q.front();
			Q.pop();

			if (t.first==M && t.second!="")
				return t.second;

			for (int d=1; d<10; d+=2) {
				long long x = t.first*10 + d;
				long long mod = x % N;
				if (have[mod])
					continue;
				have[mod] = 1;
				Q.push(make_pair(mod, t.second + char('0'+d)));
			}
		}

		return "-1";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 7; string Arg2 = "7"; verify_case(0, Arg2, findMultiple(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 22; int Arg1 = 12; string Arg2 = "-1"; verify_case(1, Arg2, findMultiple(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 29; int Arg1 = 0; string Arg2 = "319"; verify_case(2, Arg2, findMultiple(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5934; int Arg1 = 2735; string Arg2 = "791957"; verify_case(3, Arg2, findMultiple(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OddDigitable ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
