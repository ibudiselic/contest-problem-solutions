#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

vector<string> a;
string s(4, '0');
class Masterbrain {
	public:
	void fill_combs(int pos) {
		if (pos == 4) {
			a.push_back(s);
			return;
		}
		for (char i='1'; i<='7'; ++i) {
			s[pos] = i;
			fill_combs(pos+1);
		}
	}
	int possibleSecrets(vector <string> guesses, vector <string> results) {
		a.clear();
		fill_combs(0);

		int sol = 0;
		for (int i=0; i<(int)a.size(); ++i) {
			int lied = 0;
			for (int j=0; j<(int)guesses.size(); ++j) {
				vector<int> orig(8, 0), dest(8, 0);
				int b=0, w=0;
				for (int x=0; x<4; ++x)
					if (a[i][x] == guesses[j][x])
						++b;
					else {
						++orig[a[i][x]-'0'];
						++dest[guesses[j][x]-'0'];
					}
				for (int x=1; x<8; ++x)
					w += ::min(orig[x], dest[x]);
				assert(b+w<=4);
				ostringstream os;
				os << b << "b " << w << 'w';
				if (results[j] != os.str())
					++lied;
			}
			if (lied == 1)
				++sol;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1575"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4b 0w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2400; verify_case(0, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0b 4w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2392; verify_case(1, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"6172","6162","3617"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3b 0w","2b 1w","0b 3w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(2, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1513","5654","4564","1377","1671","1342"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1b 0w","0b 1w","1b 0w","1b 0w","0b 1w","0b 1w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"2611", "1371", "7417", "2647", "3735", "4272", "2442", "3443", "1252", "3353"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0b 2w","0b 2w","0b 1w","0b 2w","1b 0w","1b 0w","1b 0w","0b 1w","1b 1w","0b 1w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, possibleSecrets(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Masterbrain ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
