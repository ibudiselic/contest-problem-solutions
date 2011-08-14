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

enum States {
	INIT, IN_WORD, HYPHEN
};
class Hyphenated {
	public:
	double avgLength(vector <string> lines) {
		States state = INIT;

		int sum = 0;
		int cnt = 0;
		int cur = 0;

		for (int i=0; i<(int)lines.size(); ++i) {
			if (state==HYPHEN && isalpha(lines[i][0])) {
				state = IN_WORD;
			} else if (cur > 0) {
				sum += cur;
				++cnt;
				cur = 0;
				state = INIT;
			}

			for (int j=0; j<(int)lines[i].size(); ++j)
				switch (state) {
					case INIT:
						if (!isalpha(lines[i][j]))
							continue;
						cur = 1;
						state = IN_WORD;
						break;
					case IN_WORD:
						if (j==(int)lines[i].size()-1 && lines[i][j]=='-') {
							state = HYPHEN;
							continue;
						}
						if (!isalpha(lines[i][j])) {
							state = INIT;
							sum += cur;
							++cnt;
							cur = 0;
						} else {
							++cur;
						}
						break;
					default: assert(0); break;
				}
		}

		if (cur != 0) {
			sum += cur;
			++cnt;
		}

		return double(sum)/cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"  now is the ex-", "ample.  "} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.75; verify_case(0, Arg1, avgLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"  now is the ex-", " ample.  "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(1, Arg1, avgLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"inter-","national-","ization.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 20.0; verify_case(2, Arg1, avgLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"All the time I have well-defined  "," trouble."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.125; verify_case(3, Arg1, avgLength(Arg0)); }
	void test_case_4() { string Arr0[] = {"hello-","-","-","-","great"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.0; verify_case(4, Arg1, avgLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Hyphenated ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
