#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool level[26];
class CountingCrowds {
	public:
	int minimalInterpretation(vector <string> sensorData) {
		int curLevel = -1;
		memset(level, 0, sizeof level);
		int sol = 0;

		string s;
		for (int i=0; i<(int)sensorData.size(); ++i)
			s += sensorData[i];

		cerr << s << '\n';

		for (int i=0; i<(int)s.size(); ++i) {
			if (s[i] == '.') {
				if (curLevel != -1) {
					curLevel = -1;
					memset(level, 0, sizeof level);
				}
			} else {
				if (s[i]-'A' > curLevel)
					curLevel = s[i]-'A';

				if (!level[s[i]-'A']) {
					level[s[i]-'A'] = 1;
					++sol;
				}
				memset(level, 0, s[i]-'A');
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..BBAABB.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalInterpretation(Arg0)); }
	void test_case_1() { string Arr0[] = {"..AAA","AA.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimalInterpretation(Arg0)); }
	void test_case_2() { string Arr0[] = {"CCB..ABC.ACDACD.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minimalInterpretation(Arg0)); }
	void test_case_3() { string Arr0[] = {"KHTXRJNHKPHNDWEGOQKGFSQWWFSBNZSHJJHTOZK","RRPPPEBOPFZXVMLHYDNIEIZNQWYAUYB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(3, Arg1, minimalInterpretation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CountingCrowds ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
