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

int getVal(char c) {
	if (isdigit(c))
		return c-'0';
	else
		switch (c) {
			case 'T': return 10;
			case 'J': return 11;
			case 'Q': return 12;
			case 'K': return 13;
			case 'A': return 14;
			default: assert(0); return -1;
		}
}
struct card {
	char suite;
	int val;
	card(const string &s) {
		assert(s.size() == 2);
		suite = s[0];
		val = getVal(s[1]);
	}
};
int winner(const vector<card> &v, int first) {
	int ret = first;
	for (int i=0; i<4; ++i)
		if (v[i].suite==v[ret].suite && v[i].val>v[ret].val)
			ret = i;

	return ret;
}
bool hasSuite(const vector<card> &v, int start, char suite) {
	while (start < (int)v.size())
		if (v[start++].suite == suite)
			return true;

	return false;
}
bool hasNonScore(const vector<card> &v, int start) {
	while (start < (int)v.size()) {
		if (v[start].suite!='H' && !(v[start].suite=='S' && v[start].val==getVal('Q')))
			return true;
		++start;
	}
	return false;
}
int cntHearts(const vector<card> &v) {
	int ret = 0;
	for (int i=0; i<(int)v.size(); ++i)
		ret += (v[i].suite=='H');
	return ret;
}
bool hasQS(const vector<card> &v) {
	for (int i=0; i<(int)v.size(); ++i)
		if (v[i].suite=='S' && v[i].val==getVal('Q'))
			return 1;
	return 0;
}
int calc(const vector<card> &v) {
	int cntH = cntHearts(v);
	bool has = hasQS(v);

	if (cntH==13 && has)
		return 123;
	else
		return cntH + has*13;
}
class HeartsGame {
	public:
	vector <string> score(vector <string> tricks) {
		vector<card> p[4];
		int turn = 0;
		for (int i=0; i<13; ++i) {
			istringstream is(tricks[i]);
			string s;
			for (int j=0; j<4; ++j) {
				is >> s;
				p[(turn+j)%4].push_back(card(s));
			}
			vector<card> cur;
			for (int j=0; j<4; ++j)
				cur.push_back(p[j].back());
			turn = winner(cur, turn);
		}

		bool heartsBroken = false;
		vector<int> score(4, 0);
		vector<card> have[4];
		turn = 0;

		for (int i=0; i<13; ++i) {
			char suite = p[turn][i].suite;
			if (suite=='H' && !heartsBroken && (hasSuite(p[turn], i, 'S') || hasSuite(p[turn], i, 'C') || hasSuite(p[turn], i, 'D')))
				score[turn] = -1;
			if (suite == 'H')
				heartsBroken = 1;

			for (int j=1; j<4; ++j) {
				if (p[(turn+j)%4][i].suite == 'H')
					heartsBroken = 1;
				if (p[(turn+j)%4][i].suite!=suite && hasSuite(p[(turn+j)%4], i, suite))
					score[(turn+j)%4] = -1;
				if (i==0 && (p[(turn+j)%4][i].suite=='H' || p[(turn+j)%4][i].suite=='S' && p[(turn+j)%4][i].val==getVal('Q')) && hasNonScore(p[(turn+j)%4], i))
					score[(turn+j)%4] = -1;
			}

			vector<card> cur;
			for (int j=0; j<4; ++j)
				cur.push_back(p[j][i]);
			turn = winner(cur, turn);
			copy(cur.begin(), cur.end(), back_inserter(have[turn]));
		}

		for (int i=0; i<4; ++i)
			if (score[i] != -1) {
				score[i] = calc(have[i]);
				if (score[i] == 123) {
					score[i] = 0;
					for (int j=0; j<4; ++j)
						if (i!=j && score[j]!=-1)
							score[j] = 26;
					goto KRAJ;
				}
			} else {
				if (calc(have[i]) == 123) {
					for (int j=0; j<4; ++j)
						if (score[j]!=-1)
							score[j] = 26;
					goto KRAJ;
				}
			}
		KRAJ:;

		vector<string> sol;
		for (int i=0; i<4; ++i) {
			if (score[i] == -1) {
				sol.push_back("CHEATER!");
			} else {
				ostringstream os;
				os << score[i];
				sol.push_back(os.str());
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"C2 CA DA C9",
 "S9 S8 S7 S5",
 "ST S6 S3 S4",
 "C6 HK C3 CK",
 "DQ HQ D9 D5",
 "D3 H7 D4 D2",
 "D6 SK DJ H8",
 "H5 H2 H6 H3",
 "H9 H4 HT CQ",
 "D8 CJ DT SA",
 "HJ C7 SQ CT",
 "HA C5 D7 C8",
 "S2 SJ DK C4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "6",  "0",  "20",  "0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, score(Arg0)); }
	void test_case_1() { string Arr0[] = {"C2 D2 S2 H2",
 "C3 D3 S3 H3",
 "C4 D4 S4 H4",
 "C5 D5 S5 H5",
 "C6 D6 S6 H6",
 "C7 D7 S7 H7",
 "C8 D8 S8 H8",
 "C9 D9 S9 H9",
 "CT DT ST HT",
 "CJ DJ SJ HJ",
 "CQ DQ SQ HQ",
 "CK DK SK HK",
 "CA DA SA HA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0",  "26",  "26",  "26" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, score(Arg0)); }
	void test_case_2() { string Arr0[] = {"C2 C3 CK SA",
 "DA DK DT D8",
 "SJ ST S3 SK",
 "S5 S6 S2 CQ",
 "C6 DQ CT HK",
 "H3 H6 H2 H4",
 "S4 S9 S8 HQ",
 "C4 HA CJ HT",
 "C7 HJ C5 H9",
 "C8 D9 C9 CA",
 "H5 H7 D7 H8",
 "D2 D6 D4 D5",
 "D3 S7 SQ DJ"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "CHEATER!",  "4",  "17",  "CHEATER!" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, score(Arg0)); }
	void test_case_3() { string Arr0[] = { "C2 C9 CA CT",
 "D4 D2 D3 DJ",
 "S9 S2 S7 SA",
 "C4 C7 D5 CJ",
 "D6 C6 DK DT",
 "CK H7 C8 CQ",
 "HA HJ H8 H6",
 "ST HK S3 S4",
 "SK H5 SJ S6",
 "S8 H9 D8 HQ",
 "SQ HT DA C3",
 "C5 D9 H2 H3",
 "S5 D7 DQ H4" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "26",  "0",  "26",  "26" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, score(Arg0)); }
	void test_case_4() { string Arr0[] = {"C2 CQ HK D7",
 "H9 H7 HJ H4",
 "S2 S8 S5 D2",
 "C9 DA CT CK",
 "DT C8 D9 D4",
 "DK S3 H6 C6",
 "CJ D6 C5 S9",
 "D8 SA H8 DJ",
 "S7 S6 ST CA",
 "HA H5 H3 D5",
 "DQ C7 SK D3",
 "HQ H2 SJ C3",
 "SQ C4 HT S4" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "CHEATER!",  "CHEATER!",  "CHEATER!",  "CHEATER!" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, score(Arg0)); }
	void test_case_5() { string Arr0[] = {"C2 CA HA CQ",
 "C3 HK C9 C5",
 "ST SJ SA SQ",
 "C4 HQ C6 CJ",
 "S9 DA HJ S7",
 "H2 DT HT SK",
 "H3 DQ H4 CK",
 "S4 CT H9 S6",
 "S5 S3 C8 H8",
 "D6 D4 D5 D3",
 "D8 DK D7 H7",
 "S2 C7 H6 DJ",
 "S8 D2 H5 D9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "7",  "14",  "CHEATER!",  "3" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, score(Arg0)); }
	void test_case_6() { string Arr0[] = {"C2 SQ C9 C8",
 "C6 CA CQ HA",
 "S4 SJ HK SK",
 "ST SA S9 HQ",
 "DA DK D7 DQ",
 "D2 D4 HJ DJ",
 "H4 DT H2 H3",
 "D9 D5 D3 HT",
 "S5 CK S8 H9",
 "CJ H8 D8 CT",
 "C5 H7 D6 C4",
 "S2 H6 S7 C7",
 "S6 C3 S3 H5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "3",  "CHEATER!",  "21",  "2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, score(Arg0)); }
	void test_case_7() { string Arr0[] = {"C2 CJ C6 DK",
 "H7 S2 DQ H6",
 "H2 S6 DJ CK",
 "H3 S8 D2 S4",
 "HK ST H5 CA",
 "H8 SA D3 C7",
 "DA D4 DT C8",
 "HQ S9 D8 C4",
 "HJ S7 D9 CT",
 "HT SK SQ S5",
 "H4 SJ D5 C9",
 "HA S3 D6 C5",
 "H9 CQ D7 C3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "26",  "CHEATER!",  "26",  "CHEATER!" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(7, Arg1, score(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HeartsGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
