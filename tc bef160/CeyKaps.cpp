#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CeyKaps {
	public:
	string decipher(string typed, vector <string> switches) {
		char a[26];
		int b[26];
		string sol;
		for (char c='A'; c<='Z'; ++c)
			a[c-'A'] = c;
		for (int i=0; i<26; ++i)
			b[i] = i;

		for (int i=0; i<(int)switches.size(); ++i) {
			char t = a[switches[i][0]-'A'];
			b[a[switches[i][0]-'A']-'A'] = switches[i][2]-'A';
			b[a[switches[i][2]-'A']-'A'] = switches[i][0]-'A';
			a[switches[i][0]-'A'] = a[switches[i][2]-'A'];
			a[switches[i][2]-'A'] = t;
		}
		for (int i=0; i<(int)typed.size(); ++i)
			sol.push_back(b[typed[i]-'A']+'A');

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAA"; string Arr1[] = {"A:B","B:C","A:D"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "CCCCC"; verify_case(0, Arg2, decipher(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDE"; string Arr1[] = {"A:B","B:C","C:D","D:E","E:A"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AEBCD"; verify_case(1, Arg2, decipher(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "IHWSIOTCHEDMYKEYCAPSARWUND"; string Arr1[] = {"W:O","W:I"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "WHOSWITCHEDMYKEYCAPSAROUND"; verify_case(2, Arg2, decipher(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CeyKaps ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
