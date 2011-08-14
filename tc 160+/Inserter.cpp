#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string::size_type find_nth(const string &s, const string &what, int n) {
	string::size_type pos = s.find(what);
	if (--n == 0)
		return pos;
	while (pos<s.size()-1 && n) {
		pos = s.find(what, pos+1);
		--n;
	}
	return (n==0)?(pos):(string::npos);
}
string parse(const string &s) {
	string::size_type pos = s.find('#');
	assert(pos != string::npos);
	return s.substr(0, pos);
}
class Inserter {
	public:
	string insert(vector<string> cmd, string orig) {
		for (int i=0; i<(int)cmd.size(); ++i) {
			string put = parse(cmd[i].substr(1));
			string where = parse(cmd[i].substr(put.size()+4));
			int n = atoi(cmd[i].substr(where.size()+put.size()+6).c_str());
			string::size_type pos = find_nth(orig, where, n);
			if (pos != string::npos)
				orig = orig.substr(0, pos) + put + orig.substr(pos);
		}
		return orig;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#<B># #$# 2","#comes # #before this# 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "$100 before this $300"; string Arg2 = "$100 comes before this <B>$300"; verify_case(0, Arg2, insert(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"#,# # and# 1","#,# # and# 2","#,# # and# 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lions and tigers and bears"; string Arg2 = "lions, and tigers, and bears"; verify_case(1, Arg2, insert(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"#import java.util.*; # #public class # 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "public class Inserter"; string Arg2 = "import java.util.*; public class Inserter"; verify_case(2, Arg2, insert(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"# # # # 1","# # # # 2","# # # # 3","# # # # 4","# # # # 5","# # # # 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "add lots of spaces"; string Arg2 = "add       lots of spaces"; verify_case(3, Arg2, insert(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"# # # # 6","# # # # 5","# # # # 4","# # # # 3","# # # # 2","# # # # 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "order matters quite a bit"; string Arg2 = "order  matters  quite  a  bit"; verify_case(4, Arg2, insert(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"#A# #..# 2","#A# #..# 5","#A# #..# 123456789"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "...."; string Arg2 = ".A..."; verify_case(5, Arg2, insert(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Inserter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
