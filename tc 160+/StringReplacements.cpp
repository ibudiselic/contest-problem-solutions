#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
ll abc[3][21][3];
ll pot3[21];
int rep[][3] = { { 0, 2, 1 }, { 1, 0, 0 }, { 1, 2, 1 } };
vector<int> sol;

void go(int c, int t, int l, int r) {
	if (l > r) return;
	if (t == 0) {
		assert(l == r);
		++sol[c];
		return;
	}
	if (!(l>=0 && r<=pot3[t]-1)) {
		cerr << l << ' ' << r << ' ' << (long long)pot3[t] << '\n';
		assert(0);
	}
	if (l==0 && r==pot3[t]-1) {
		for (int i=0; i<3; ++i)
			sol[i] += abc[c][t][i];
		return;
	}
	const ll onet = pot3[t]/3;
	const ll twot = 2*onet;
	if (l < onet) {
		go(rep[c][0], t-1, l, min((long long)r, onet-1)); // goto left
		if (r >= twot) {
			for (int i=0; i<3; ++i) // add middle part
				sol[i] += abc[rep[c][1]][t-1][i];
			go(rep[c][2], t-1, 0, r-twot); // goto right
		} else if (r >= onet) {
			go(rep[c][1], t-1, 0, r-onet); // goto right
		}
	} else if (l < twot) {
		go(rep[c][1], t-1, l-onet, min((long long)r, twot-1)-onet); // goto middle
		if (r >= twot)
			go(rep[c][2], t-1, 0, r-twot); // goto right;
	} else {
		go(rep[c][2], t-1, l-twot, r-twot); // goto right;
	}
}
class StringReplacements {
	public:
	vector <int> substringCounter(string letter, int left, int right, int nSeconds) {
		const int start = (letter=="a" ? 0 : letter=="b" ? 1 : 2);

		pot3[0] = 1;
		for (int i=1; i<21; ++i)
			pot3[i] = 3*pot3[i-1];

		memset(abc, 0, sizeof abc);
		for (int i=0; i<3; ++i)
			abc[i][0][i] = 1;
		for (int t=1; t<=nSeconds; ++t)
			for (int s=0; s<3; ++s) {
				abc[s][t][0] = abc[s][t-1][0] + 2*abc[s][t-1][1];
				abc[s][t][1] = abc[s][t-1][0] + abc[s][t-1][1] + 2*abc[s][t-1][2];
				abc[s][t][2] = abc[s][t-1][0] + abc[s][t-1][2];
			}

		sol.assign(3, 0);
		go(start, nSeconds, left, right);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "a"; int Arg1 = 2; int Arg2 = 6; int Arg3 = 2; int Arr4[] = {0, 4, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, substringCounter(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "a"; int Arg1 = 0; int Arg2 = 2; int Arg3 = 1; int Arr4[] = {1, 1, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, substringCounter(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "c"; int Arg1 = 1; int Arg2 = 4; int Arg3 = 2; int Arr4[] = {2, 1, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, substringCounter(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "b"; int Arg1 = 4; int Arg2 = 12; int Arg3 = 3; int Arr4[] = {2, 4, 3 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, substringCounter(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StringReplacements ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
