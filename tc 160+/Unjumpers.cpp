#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> calc(const string &s) {
	vector<int> ret(3, 0);
	for (int i=0; i<(int)s.size(); ++i) {
		ret[i%3] += (s[i]=='*');
	}
	return ret;
}
int par(int x) {
	return x&1;
}
class Unjumpers {
	public:
	int reachableTargets(string start, vector <string> targets) {
		vector<int> s = calc(start);
		int sol = 0;
		for (int i=0; i<(int)targets.size(); ++i) {
			vector<int> t = calc(targets[i]);
			if (s[0]==0 && s[1]==0 && s[2]==0
				||
				t[0]==0 && t[1]==0 && t[2]==0) {
				sol += (s==t);
			} else {
				for (int i=0; i<3; ++i) {
					t[i] = par(abs(s[i]-t[i]));
				}
				if (t[0]==t[1] && t[1]==t[2]) {
					++sol;
				}
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "**."; string Arr1[] = {
"..*",
"*.**",
".*.*"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, reachableTargets(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..***"; string Arr1[] = {
"..****..*",
"..***....",
"..****"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, reachableTargets(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "*..*"; string Arr1[] = {
"*..*......",
"*.....*...",
"...*.....*",
"...*..*...",
"*........*",
"*...***..*"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, reachableTargets(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "...***" ; string Arr1[] = {
"***...",
"..****",
"**....**",
".*.*.*"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, reachableTargets(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Unjumpers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
