#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <functional>

using namespace std;

class ChangePurse {
	public:
	vector <int> optimalCoins(vector <int> coinTypes, int value) {
		vector< pair<int, int> > v;

		for (int i=0; i<(int)coinTypes.size(); ++i)
			v.push_back(make_pair(coinTypes[i], i));

		sort(v.begin(), v.end(), greater< pair<int, int> >());
		vector<int> cnt(v.size(), 0);

		for (int i=0; i<(int)v.size(); ++i)
			if ((value+1)%v[i].first == 0) {
				cnt[i] = (value+1)/v[i].first - 1;
				value = v[i].first-1;
			}

		vector<int> sol(v.size(), 0);
		for (int i=0; i<(int)v.size(); ++i)
			sol[v[i].second] = cnt[i];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,25,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; int Arr2[] = { 24,  1,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, optimalCoins(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; int Arr2[] = { 49,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, optimalCoins(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {11,5,10,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 109; int Arr2[] = { 9,  0,  0,  10 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, optimalCoins(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {29210, 58420, 350520, 708072, 720035, 230, 42355,
 1, 59006, 985, 236024, 163, 701040}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 929579039; int Arr2[] = { 1,  5,  1,  0,  0,  126,  0,  229,  0,  0,  0,  0,  1325 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, optimalCoins(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {795, 5536, 26, 915, 18590, 60840, 49140, 2,
 119700, 162235, 369000, 383936, 478800, 505995,
 949, 95984, 455, 8, 420, 239400, 276800, 191968,
 619305, 654810, 706420, 393120, 738000, 767872,
 425880, 786240, 830400, 676, 4500, 851760, 957600,
 648940, 1, 112, 180, 457}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 687245439; int Arr2[] = { 0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  1,  0,  0,  0,  1,  0,  13,  0,  0,  0,  1,  0,  0,  0,  0,  0,  894,  0,  0,  0,  0,  0,  0,  0,  0,  1,  856,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, optimalCoins(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {494208, 722376, 731798, 809064, 920448, 1, 988416, 9152, 158,
 991014, 282720, 40132, 608, 143, 289755, 734, 579510, 828400,
 330338, 816, 460224, 27456, 675783, 331, 436, 82368, 729, 306,
 202266, 247104, 414200, 705}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 419088383; int Arr2[] = { 1,  0,  0,  0,  0,  142,  423,  2,  0,  0,  0,  0,  0,  63,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  2,  0,  0,  0,  1,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, optimalCoins(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChangePurse ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
