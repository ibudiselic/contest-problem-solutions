#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> makeCnt(const string &s) {
	vector<int> cnt(256, 0);
	for (int i=0; i<(int)s.size(); ++i)
		++cnt[s[i]];
	return cnt;
}
bool imp(const vector<int> &a, const vector<int> &b) {
	for (int i=0; i<(int)a.size(); ++i)
		if (b[i]>a[i] && i!=' ')
			return true;
	return false;
}
class Mailbox {
	public:
	int impossible(string collection, vector <string> address) {
		int sol = 0;
		vector<int> cnt = makeCnt(collection);
		for (int i=0; i<(int)address.size(); ++i)
			sol += imp(cnt, makeCnt(address[i]));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAAAABBCCCCCDDDEEE123456789"; string Arr1[] = {"123C","123A","123 ADA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, impossible(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJKLMNOPRSTUVWXYZ1234567890"; string Arr1[] = {"2 FIRST ST"," 31 QUINCE ST", "606 BAKER"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, impossible(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABCDAAST"; string Arr1[] = {"111 A ST", "A BAD ST", "B BAD ST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, impossible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Mailbox ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
