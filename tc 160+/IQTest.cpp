#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

class IQTest {
	public:
	bool ok(int a, int b, const vector<int> v) {
		for (int i=1; i<(int)v.size(); ++i)
			if (v[i-1]*a + b != v[i])
				return false;
		return true;
	}
	string nextNumber(vector <int> previous) {
		set<int> S;

		if (previous.size() < 2) {
			return "AMBIGUITY";
		} else {
			for (int a = -1000; a<=1000; ++a) {
				int sec = previous[0]*a;
				int b = previous[1] - sec;
				if (ok(a, b, previous))
					S.insert(a*previous.back() + b);
			}
		}
		if (S.size() > 1)
			return "AMBIGUITY";
		else if (S.size() == 0)
			return "BUG";
		ostringstream os;
		os << *S.begin();

		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "6"; verify_case(0, Arg1, nextNumber(Arg0)); }
	void test_case_1() { int Arr0[] = {3, 6, 12, 24, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "96"; verify_case(1, Arg1, nextNumber(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 4, 13, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "121"; verify_case(2, Arg1, nextNumber(Arg0)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUITY"; verify_case(3, Arg1, nextNumber(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUITY"; verify_case(4, Arg1, nextNumber(Arg0)); }
	void test_case_5() { int Arr0[] = {57, 57}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "57"; verify_case(5, Arg1, nextNumber(Arg0)); }
	void test_case_6() { int Arr0[] = {16, -8, 4, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BUG"; verify_case(6, Arg1, nextNumber(Arg0)); }
	void test_case_7() { int Arr0[] = {6, 5, 4, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BUG"; verify_case(7, Arg1, nextNumber(Arg0)); }
	void test_case_8() { int Arr0[] = {-12, 12, -36, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-132"; verify_case(8, Arg1, nextNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IQTest ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
