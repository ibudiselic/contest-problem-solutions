#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

bool allSame(const string &s, int i, char c) {
	while (i<(int)s.size()) {
		if (tolower(s[i]) != tolower(c))
			return false;
		++i;
	}
	return true;
}
bool wmatch(const string &w, const string &s) {
	int i=0, j=0;

	while (i<(int)w.size() && j<(int)s.size()) {
		if (tolower(w[i]) == tolower(s[j])) {
			++i;
			++j;
		} else if (j>0 && tolower(s[j])==tolower(s[j-1])) {
			++j;
		} else {
			return false;
		}
	}

	return i==(int)w.size() && (j==(int)s.size() || (j>0 && allSame(s, j, s[j-1])));
}
bool match(const string &w, const vector<string> &K) {
	for (int i=0; i<(int)K.size(); ++i)
		if (wmatch(K[i], w))
			return 1;

	return 0;
}
class SpamDetector {
	public:
	int countKeywords(string S, vector <string> K) {
		int sol = 0;

		istringstream is(S);
		string w;

		while (is >> w)
			sol += match(w, K);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LoooW INTEREST RATES available dont BE slow"; string Arr1[] = {"interest","rates","loan","available","LOW"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "Dear Richard Get Rich Quick            no risk"; string Arr1[] = {"rich","risk","Quicken","wealth","SAVE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "in debbtt againn and aAgain and AGAaiIN"; string Arr1[] = {"AGAIN","again","Again","again"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "PlAyy ThEE Lottto     get Loottoo feever"; string Arr1[] = {"play","lotto","lottery","looser"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "                                   "; string Arr1[] = {"empty","space","does","not","match"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, countKeywords(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SpamDetector ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
