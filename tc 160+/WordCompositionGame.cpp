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

int score(const string &s, const set<string> &a, const set<string> &b) {
	return 3 - a.count(s) - b.count(s);
}
string toStr(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
string f(const set<string> &a, const set<string> &b, const set<string> &c) {
	int ret = 0;
	for (set<string>::const_iterator it=a.begin(); it!=a.end(); ++it)
		ret += score(*it, b, c);

	return toStr(ret);
}
class WordCompositionGame {
	public:
	string score(vector <string> listA, vector <string> listB, vector <string> listC) {
		set<string> A(listA.begin(), listA.end());
		set<string> B(listB.begin(), listB.end());
		set<string> C(listC.begin(), listC.end());

		return f(A, B, C) + '/' + f(B, A, C) + '/' + f(C, A, B);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"cat", "dog", "pig", "mouse"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"cat", "pig"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"dog", "cat"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "8/3/3"; verify_case(0, Arg3, score(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"mouse"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"cat", "pig"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"dog", "cat"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "3/5/5"; verify_case(1, Arg3, score(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"dog", "mouse"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"dog", "pig"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"dog", "cat"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "4/4/4"; verify_case(2, Arg3, score(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"bcdbb","aaccd","dacbc","bcbda","cdedc","bbaaa","aecae"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bcdbb","ddacb","aaccd","adcab","edbee","aecae","bcbda"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"dcaab","aadbe","bbaaa","ebeec","eaecb","bcbba","aecae","adcab","bcbda"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "14/14/21"; verify_case(3, Arg3, score(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordCompositionGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
