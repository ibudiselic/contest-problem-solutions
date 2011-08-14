#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[30][31];
int dp2[30][31][50][50];
vector<string> R;
string S;
int mod = 1000000007;

int go(int, int);
int match(int l, int r, int res, int resPos) {
	if (S.substr(l, r-l) == R[res].substr(resPos))
		return 1;

	int &ret = dp2[l][r][res][resPos];
	if (ret != -1)
		return ret;

	ret = 0;
	int i = l;
	int j = resPos;

	while (i<r && j<(int)R[res].size()) {
		if (R[res][j] == '%') {
			if (j+2 == (int)R[res].size())
				return ret = go(i, r);
			else
				for (int k=1; i+k<r; ++k) {
					long long t = match(i+k, r, res, j+2);
					if (t > 0) {
						t = (t * go(i, i+k)) % mod;
						ret = (ret + t) % mod;
					}
				}

			break;
		}
		if (S[i++] != R[res][j++])
			return ret = 0;
	}

	return ret;
}
int go(int l, int r) { // [l, r>
	int &ret = dp[l][r];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int k=0; k<(int)R.size(); ++k)
		ret = (ret+match(l, r, k, 0))%mod;

	return ret;
}
class ReverseResources {
	public:
	int findDecompositions(string str, vector <string> resources) {
		R = resources;
		S = str;

		memset(dp, 0xff, sizeof dp);
		memset(dp2, 0xff, sizeof dp2);

		return go(0, str.size());
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Error in module foo, code 123."; string Arr1[] = {"foo", "123", "Error in module %s.", "%s, code %s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "The fox jumped over the dog."; string Arr1[] = {"The fox %s over the dog.",
 "lazy",
 "brown",
 "jump%s",
 "s",
 "ed",
 "The %s",
 "fox %s",
 "%s over %s",
 "the dog."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abcde"; string Arr1[] = {"%sc%s", "b", "de", "a%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcde"; string Arr1[] = {"%se", "a%s", "%sb%s", "%sc%s", "%sd%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaaa"; string Arr1[] = {"a","%s%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(4, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; string Arr1[] = {"a","aa","%s%s","%sa","a%s","aaa","aa%s","a%sa",
"a%s%s","%saa","%sa%s","%s%sa","%s%s%s","aaaa",
"aaa%s","aa%sa","aa%s%s","a%saa","a%sa%s","a%s%sa",
"a%s%s%s","%saaa","%saa%s","%sa%sa","%sa%s%s",
"%s%saa","%s%sa%s","%s%s%sa","%s%s%s%s","aaaaa",
"aaaa%s","aaa%sa","aaa%s%s","aa%saa","aa%sa%s",
"aa%s%sa","aa%s%s%s","a%saaa","a%saa%s","a%sa%sa",
"a%sa%s%s","a%s%saa","a%s%sa%s","a%s%s%sa",
"a%s%s%s%s","%saaaa","%saaa%s","%saa%sa","%saa%s%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 879704799; verify_case(5, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "aa"; string Arr1[] = {"a", "a", "%s%s", "%s%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(6, Arg2, findDecompositions(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ReverseResources ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
