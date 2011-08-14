#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool old[50][50][50][50], cur[50][50][50][50];
class ImageRepeat {
	public:
	int largestSize(vector <string> A, vector <string> B) {
		int mA = A.size();
		int nA = A[0].size();
		int mB = B.size();
		int nB = B[0].size();
		int largest = 0;

		memset(old, 0, sizeof old);
		for (int i=0; i<mA; ++i)
			for (int j=0; j<nA; ++j)
				for (int r=0; r<mB; ++r)
					for (int c=0; c<nB; ++c)
						if (A[i][j] == B[r][c]) {
							old[i][j][r][c] = 1;
							largest = 1;
						}

		for (int k=2; ; ++k) {
			memset(cur, 0, sizeof cur);
			for (int i=0; i+k<=mA; ++i)
				for (int j=0; j+k<=nA; ++j)
					for (int r=0; r+k<=mB; ++r)
						for (int c=0; c+k<=nB; ++c)
							if (old[i][j][r][c] && old[i+1][j][r+1][c] && old[i][j+1][r][c+1] && old[i+1][j+1][r+1][c+1]) {
								largest = k;
								cur[i][j][r][c] = 1;
							}
			if (largest < k)
				return largest;
			memcpy(old, cur, sizeof old);
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC",
 "BCD",
 "CDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABC",
 "BCD",
 "CDE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, largestSize(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ABC",
 "BCD",
 "CDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABCXX",
 "BCDXX",
 "CDFXX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, largestSize(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"CEBACBABBDCCCACCDCBD",
 "EBAEBCBEBBCCEABEECED",
 "CEAEAEEEADBDEDABDCCB",
 "EDCEACDABDBCBEECACBD",
 "CDCBCBCCBCCCADDCAEDC",
 "ACCBAABABDABEDEACABC",
 "DCCADCACAEBCBCCCEEEB",
 "ACDABCCCBAABBAEBCBDA",
 "BACEEADBBDBAABCCBDBE",
 "AACACCCEEEBEBDCEABAD",
 "CABACEAAEDDEDDAAEDCC",
 "DDCEAEEBBDBEDBACCCAE",
 "CDABEEEDBDEBCEBECEAB",
 "CDBBDDCDCEDBDEEBCEDD",
 "DBDDBCBAEBBCDAECEBDA",
 "DBBBECAECACADAACACEA",
 "BDADACDEECCBABADEDDC",
 "AEBCABCCABCBBCBABBEC",
 "DDCEAEDEDBCBBABBCCBC",
 "DBBEEAEDDCABCEAACBEC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CBEEADAEDCDDCEBEEADC",
 "BDBDABCBBDBACEACDACA",
 "ABAABDAADBCECDCEAACE",
 "DDBAAAACAAAAECBDAEDA",
 "EEAAABABCDABAEBEABAE",
 "CECADCCEABEBEDCAEABA",
 "DDECACDEECBBCBDDCDAE",
 "CAEAAEDBADEECAACDAAA",
 "EAECECBCDAAEBDECBBAB",
 "CBCDADDDBACEDBBABACC",
 "DCAEAADBEBEACDEDCCEC",
 "ACACCBEACEBBBBEEACEC",
 "DEDEBEEADCAECEBDDBEA",
 "ACACACEADCACEAACEDAD",
 "DCACBEEBCBDEDADACEEC",
 "EDDEDCDCCEDBCCDCABDC",
 "CABECBAEDCACABDDDADD",
 "CAEDAABCCCCDEDAEABDE",
 "CCDACADABADECDEACCED",
 "BEDADAADACAABAAEBADB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, largestSize(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ImageRepeat ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
