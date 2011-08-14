#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}
template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

/*** real code starts here ***/

enum CARD_SUITE {
	SPADES, DIAMONDS, HEARTS, CLUBS
};
enum CARD_VAL {
	TEN = 10, JACK, QUEEN, KING, ACE
};
int get_val(char c)
{
	if (isdigit(c)) return c-'0';
	else
		switch (c) {
			case 'T': return TEN; break;
			case 'J': return JACK; break;
			case 'Q': return QUEEN; break;
			case 'K': return KING; break;
			case 'A': return ACE; break;
		}
	return -1;
}

class HeartsGame {
    public:
    vector <string> score(vector <string> tricks) {
        int has[4][4] = {0};
        int played[4][13];
        CARD_SUITE suite[4][13];
        bool cheater[4] = {0};
        bool hearts_broken = false;
        int score[4] = {0};
        int won[13];
        int queen = 0;
        int p = 0;
        int v = 0;
        
        for (int i=0; i<13; ++i) {
    		vector<string> t = tokenize<string>(tricks[i]);
    		int round_score = 0;
    		for (int j=0; j<4; ++j) {
    			p = (v+j)%4;
    			played[p][i] = get_val(t[j][1]);
    			switch (t[j][0]) {
    				case 'S':
    					suite[p][i] = SPADES;
    					++has[p][SPADES];
    					if (t[j][1]=='Q') {
    						round_score += 13;
    						queen = p;
    					}
    					break;
    				case 'D':
    					suite[p][i] = DIAMONDS;
    					++has[p][DIAMONDS];
    					break;
    				case 'H':
    					++round_score;
    					suite[p][i] = HEARTS;
    					++has[p][HEARTS];
    					break;
    				case 'C':
    					suite[p][i] = CLUBS;
    					++has[p][CLUBS];
    					break;
    			}
    		}
    		int winner = v;
    		for (int j=0; j<4; ++j)
    			if (suite[winner][i] == suite[j][i] && played[winner][i]<played[j][i])
    				winner = j;
    		won[i] = winner;
    		v = winner;
    		score[winner] += round_score;
    	}
    	for (int i=0; i<4; ++i)
    		if (score[i]==26) {
    			score[i] = 0;
    			for (int j=0; j<4; ++j)
    				if (j!=i) score[j] = 26;
    			break;
    		}
    	for (int i=0; i<4; ++i) {
    		if (suite[0][0]!=suite[i][0] && has[i][suite[0][0]])
    			cheater[i] = true;
    		if (suite[i][0]==HEARTS && (has[i][HEARTS]<13 && queen!=i || has[i][HEARTS]<12 && queen==i))
    			cheater[i] = true;
    		else if (queen==i && played[i][0]==QUEEN && suite[i][0]==SPADES && has[i][HEARTS]<12)
    			cheater[i] = true;
    		if (suite[i][0] == HEARTS) hearts_broken = true;
    		--has[i][suite[i][0]];
    	}
    	for (int i=1; i<13; ++i) {
    		v = won[i-1];
    		for (int j=0; j<4; ++j) {
    			p = (v+j)%4;
    			if (suite[p][i]!=suite[v][i] && has[p][suite[v][i]])
    				cheater[p] = true;
    			if (p==v && suite[p][i]==HEARTS && !hearts_broken && has[p][HEARTS] < 13-i)
    				cheater[p] = true;
    			if (suite[p][i] == HEARTS) hearts_broken = true;
    			--has[p][suite[p][i]];
    		}
    	}
    	vector<string> sol;
    	for (int i=0; i<4; ++i)
    		if (cheater[i]) sol.push_back("CHEATER!");
    		else sol.push_back(to_str<int>(score[i]));
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
