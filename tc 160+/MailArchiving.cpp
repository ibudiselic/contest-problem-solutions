#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector<string> dest;

int dp[50][50][51];
bool EQ[51][51];
int go(int l, int r, int last) {
	if (l > r)
		return 0;
	if (l == r)
		return !EQ[l][last];

	if (dp[l][r][last] != -1)
		return dp[l][r][last];

	int ret = 1234567890;
	for (int i=l; i<=r; ++i)
		ret = min(ret, !EQ[last][i] + go(l, i-1, dest.size()-1) + go(i+1, r, i));

	return dp[l][r][last] = ret;
}
class MailArchiving {
	public:
	int minSelections(vector <string> destFolder) {
		dest = destFolder;
		dest.push_back("@");
		memset(EQ, 0, sizeof EQ);
		for (int i=0; i<(int)dest.size(); ++i) {
			EQ[i][i] = 1;
			for (int j=i+1; j<(int)dest.size(); ++j)
				EQ[i][j] = EQ[j][i] = (dest[i]==dest[j]);
		}

		memset(dp, 0xff, sizeof dp);

		return go(0, dest.size()-2, dest.size()-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Deleted messages","Saved messages","Deleted messages"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minSelections(Arg0)); }
	void test_case_1() { string Arr0[] = {"Folder A","Folder B","Folder C","Folder D","Folder E","Folder F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minSelections(Arg0)); }
	void test_case_2() { string Arr0[] = {"FOLDER","folder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minSelections(Arg0)); }
	void test_case_3() { string Arr0[] = {"a","b","a","c","a","a","b","a","c","d","a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, minSelections(Arg0)); }
	void test_case_4() { string Arr0[] = {"a","b","b","c","d","e","d","e","d","e",
 "c","c","a","a","a","f","g","g","f","a",
 "h","h","i","j","i","j","a","a","k","k",
 "l","m","k","l","m","a","o","o","p","a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(4, Arg1, minSelections(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MailArchiving ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
