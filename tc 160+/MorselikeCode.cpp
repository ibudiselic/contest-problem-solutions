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

class MorselikeCode {
	public:
	string decrypt(vector <string> library, string message) {
		map<string, char> M;
		for (int i=0; i<(int)library.size(); ++i)
			M[library[i].substr(2)] = library[i][0];

		string sol;
		istringstream is(message);
		string w;
		while (is >> w)
			if (M.count(w))
				sol += M[w];
			else
				sol += '?';

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"O ---",
 "S ..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "... --- ..."; string Arg2 = "SOS"; verify_case(0, Arg2, decrypt(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"O ---"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "... --- ..."; string Arg2 = "?O?"; verify_case(1, Arg2, decrypt(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"H -",
 "E .",
 "L --",
 "L ..",
 "O -."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "- . -- .. -."; string Arg2 = "HELLO"; verify_case(2, Arg2, decrypt(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"H -.-.-.-.-.-.-.-.-.-.",
 "I .-.-.-.-.-.-.-.-.-.-",
 "K -.-.-.-.-.",
 "E .-.-.-.-.-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-.-.-.-.-.-.-.-.-.-. .-.-.-.-.-.-.-.-.-.-"; string Arg2 = "HI"; verify_case(3, Arg2, decrypt(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"O ---",
 "S ...",
 "B -...",
 "T -",
 "R .-.",
 "E .",
 "N -.",
 "X -..-",
 "D -.." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-... --- ... - --- -. .-. . -.. ... --- -..-"; string Arg2 = "BOSTONREDSOX"; verify_case(4, Arg2, decrypt(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"B -...",
 "N -.",
 "H ....",
 "O --",
 "Z --..",
 "G ---",
 "I ..",
 "J .---" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "--- -- -... .- -. .- -. .-"; string Arg2 = "GOB?N?N?"; verify_case(5, Arg2, decrypt(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"A --",
 "B -.",
 "N ...-",
 "I --..",
 "F -.-.-."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-. -- -.-.-. -.-.-. --- --.. ...- .-..--."; string Arg2 = "BAFF?IN?"; verify_case(6, Arg2, decrypt(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MorselikeCode ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
