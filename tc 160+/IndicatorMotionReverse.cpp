#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const char s[] = "|/-N";
int pos[128];
char buff[2500];
class IndicatorMotionReverse {
	public:
	string getMinProgram(vector <string> actions) {
		pos['|'] = 0;
		pos['/'] = 1;
		pos['-'] = 2;
		pos['N'] = 3;
		string a;
		for (int i=0; i<(int)actions.size(); ++i)
			a += actions[i];
		char state = pos[a[0]];

		for (int i=1; i<(int)a.size(); ++i) {
			if (a[i] == s[state])
				buff[i-1] = 'S';
			else if (a[i] == s[(state+1)%4])
				buff[i-1] = 'R';
			else if (a[i] == s[(state+4-1)%4])
				buff[i-1] = 'L';
			else
				buff[i-1] = 'F';
			state = pos[a[i]];
		}
		string sol(2500, ' ');
		int x = 0;
		for (int i=0; x<100 && i<(int)a.size()-1; ) {
			int j = i;
			while (buff[++j] == buff[i])
				;
			int cnt = j-i;
			if (cnt > 99) {
				int rem = cnt % 99;
				if (rem > 0) {
					sol[x++] = buff[i];
					sol[x++] = '0' + (rem/10);
					sol[x++] = '0' + (rem%10);
					cnt -= rem;
				}
			}
			while (cnt > 0) {
				int rem = min(cnt, 99);
				sol[x++] = buff[i];
				sol[x++] = '0' + (rem/10);
				sol[x++] = '0' + (rem%10);
				cnt -= rem;
			}
			i = j;
		}
		if (x >= 100)
			sol[97] = sol[98] = sol[99] = '.';
		return sol.substr(0, min(x, 100));
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-|-|/-/|//////-/"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "F03R02L02R01S05R01L01"; verify_case(0, Arg1, getMinProgram(Arg0)); }
	void test_case_1() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(1, Arg1, getMinProgram(Arg0)); }
	void test_case_2() { string Arr0[] = {"||||||||||||||||||||||||||||||||||||||||||||||||||",
 "||||||||||||||||||||||||||||||||||||||||||||||||||",
 "||||||||||||||||||||||||||||||||||||||||||||||||||"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "S50S99"; verify_case(2, Arg1, getMinProgram(Arg0)); }
	void test_case_3() { string Arr0[] = {"N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L..."; verify_case(3, Arg1, getMinProgram(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IndicatorMotionReverse ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
