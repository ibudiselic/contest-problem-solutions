#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int a[3000][3000];
class Segments {
	public:
	string intersection(vector <int> s1, vector <int> s2) {
		memset(a, 0, sizeof a);
		for (int i=0; i<4; ++i) {
			s1[i] += 1000;
			s2[i] += 1000;
		}
		if (s1[0]==s1[2])
			for (int i=min(s1[1], s1[3]); i<=max(s1[1], s1[3]); ++i)
				a[s1[0]][i] = 1;
		else
			for (int i=min(s1[0], s1[2]); i<=max(s1[0], s1[2]); ++i)
				a[i][s1[1]] = 1;

		int cnt = 0;
		if (s2[0]==s2[2])
			for (int i=min(s2[1], s2[3]); i<=max(s2[1], s2[3]); ++i)
				cnt += a[s2[0]][i];
		else
			for (int i=min(s2[0], s2[2]); i<=max(s2[0], s2[2]); ++i)
				cnt += a[i][s2[1]];

		switch (cnt) {
			case 0: return "NO"; break;
			case 1: return "POINT"; break;
			default: return "SEGMENT"; break;
		}
		return "T_T";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0, 1}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(0, Arg2, intersection(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POINT"; verify_case(1, Arg2, intersection(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, -1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POINT"; verify_case(2, Arg2, intersection(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 0, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 10, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "SEGMENT"; verify_case(3, Arg2, intersection(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 6, 6, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(4, Arg2, intersection(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {10, 0, -10, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 0, -5, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "SEGMENT"; verify_case(5, Arg2, intersection(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Segments ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
