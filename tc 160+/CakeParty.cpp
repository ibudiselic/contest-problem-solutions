#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CakeParty {
	public:
	int digcnt(int x) {
		int ret = 0;
		while (x > 0) {
			++ret;
			x /= 10;
		}

		return ret;
	}
	string to_str(int x) {
		ostringstream os;
		os << x;
		return os.str();
	}
	string lexmin(int a, int b) {
		assert(a <= b);
		int da = digcnt(a);
		int db = digcnt(b);

		if (da == db)
			return to_str(a);

		const string aa = to_str(a);
		const string bb = "1" + string(da, '0');

		return min(aa, bb);
	}
	string makeMove(vector <int> pieces) {
		int first = pieces[0], second = -1;

		for (int i=1; i<(int)pieces.size(); ++i)
			if (pieces[i] > first) {
				second = first;
				first = pieces[i];
			} else if (pieces[i] > second) {
				second = pieces[i];
			}

		int ind;
		int cnt1 = count(pieces.begin(), pieces.end(), first);
		int cnt2 = count(pieces.begin(), pieces.end(), second);
		for (ind=0; pieces[ind]!=first; ++ind)
			;

		for (int i=ind+1; i<(int)pieces.size(); ++i)
			if (pieces[i]==first && to_str(ind)>to_str(i))
				ind = i;

		ostringstream sol;
		sol << "CAKE " << ind << " PIECES ";

		if (cnt1%2 == 0) {
			sol << 1;
		} else if (cnt1 > 1) {
			sol << 1;
		} else {
			assert(cnt1 == 1);
			if (second == -1)
				sol << pieces[0];
			else if (cnt2%2 == 1)
				sol << first-second;
			else
				sol << lexmin(first-second+1, pieces[ind]);
		}

		return sol.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 47"; verify_case(0, Arg1, makeMove(Arg0)); }
	void test_case_1() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 1"; verify_case(1, Arg1, makeMove(Arg0)); }
	void test_case_2() { int Arr0[] = {3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 1 PIECES 2"; verify_case(2, Arg1, makeMove(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 1"; verify_case(3, Arg1, makeMove(Arg0)); }
	void test_case_4() { int Arr0[] = {3,3,112}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 2 PIECES 110"; verify_case(4, Arg1, makeMove(Arg0)); }
	void test_case_5() { int Arr0[] = {3,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 0 PIECES 1"; verify_case(5, Arg1, makeMove(Arg0)); }
	void test_case_6() { int Arr0[] = {4,7,4,7,4,7,4,7,47,47,47,47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAKE 10 PIECES 1"; verify_case(6, Arg1, makeMove(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CakeParty ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
