#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class WinningRecord {
	public:
	vector <int> getBestAndWorst(string games) {
		int w=0, bw=0, bwc=0, ww=0, wwc=0;


		for (int i=0; i<3; ++i)
			w += (games[i]=='W');

		bwc = wwc = 3;
		bw = ww = w;

		for (int i=3; i<(int)games.size(); ++i) {
			w += (games[i]=='W');
			if (w * bwc >= bw * (i+1)) {
				bw = w;
				bwc = i+1;
			}
			if (w * wwc <= ww * (i+1)) {
				ww = w;
				wwc = i+1;
			}
		}

		vector<int> sol(2, 0);
		sol[0] = bwc;
		sol[1] = wwc;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "WWWWWLLLLLLLLLLLLLLL"; int Arr1[] = { 5,  20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getBestAndWorst(Arg0)); }
	void test_case_1() { string Arg0 = "WWWWWW"; int Arr1[] = { 6,  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getBestAndWorst(Arg0)); }
	void test_case_2() { string Arg0 = "LWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLWLW"; int Arr1[] = { 50,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getBestAndWorst(Arg0)); }
	void test_case_3() { string Arg0 = "WLWLWLLWWLWLWWWWWWWLWLLLLLLLLLLLLWWLWLLWWWLLLWLWLW"; int Arr1[] = { 19,  33 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getBestAndWorst(Arg0)); }
	void test_case_4() { string Arg0 = "LWWLWWLWWLLLW"; int Arr1[] = { 9,  12 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getBestAndWorst(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WinningRecord ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
