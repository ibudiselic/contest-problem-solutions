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

set< vector<int> > A, B;
void gen(vector<int> &a, set< vector<int> > &s) {
	sort(a.begin(), a.end());
	if (s.count(a) != 0)
		return;
	s.insert(a);
	for (int i=0; i<(int)a.size(); ++i)
		for (int j=0; j<i; ++j) {
			vector<int> b = a;
			b[i] += b[j];
			b.erase(b.begin()+j);
			gen(b, s);
		}
}
class SplitAndMergeGame {
	public:
	int minMoves(vector <int> startState, vector <int> finishState) {
		sort(startState.begin(), startState.end());
		sort(finishState.begin(), finishState.end());
		A.clear(); B.clear();
		gen(startState, A);
		gen(finishState, B);

		int common = -1;
		for (set< vector<int> >::const_iterator it=A.begin(); it!=A.end(); ++it)
			if ((int)(it->size()) > common  &&  B.count(*it))
				common = it->size();

		return common==-1 ? -1 : (int)startState.size() + (int)finishState.size() - 2*common;
	}



// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, minMoves(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SplitAndMergeGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
