#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TheQuestionsAndAnswersDivTwo {
	public:
	int find(vector <string> Q) {
		sort(Q.begin(), Q.end());
        return 1<<(unique(Q.begin(), Q.end()) - Q.begin());
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"How_are_you_doing?", "How_do_you_like_our_country?", "How_are_you_doing?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"Whazzup?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"Are_you_ready?", "Are_you_ready?", "Are_you_ready?", "Are_you_ready?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"Do_you_like_my_story?", "Do_you_like_my_story", "DO_YOU_LIKE_MY_STORY?", "Do__you__like__my__story?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheQuestionsAndAnswersDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
