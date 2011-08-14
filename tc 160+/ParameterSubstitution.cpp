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

class ParameterSubstitution {
	public:
	string processParams(string code, vector <string> params) {
		int n = params.size();

		string sol;
		for (int i=0; i<(int)code.size(); ++i)
			if (code[i] != '$') {
				sol += code[i];
			} else {
				if (i+1==(int)code.size() || !isdigit(code[i+1]) || code[i+1]=='0') {
					sol += code[i];
					continue;
				}
				int j = i+1;
				int num = 0;
				while (j<(int)code.size() && isdigit(code[j]) && num<=n)
					num = num*10 + (code[j++]-'0');

				if (num > n) {
					--j;
					num /= 10;
				}

				if (num == 0) {
					sol += code[i];
				} else {
					sol += params[num-1];
					i = j-1;
				}
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "if ($1 == $2) $3;"; string Arr1[] = {"12", "12", "doWhatIWant()"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "if (12 == 12) doWhatIWant();"; verify_case(0, Arg2, processParams(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "$3+$1*$2-$7=$10"; string Arr1[] = {"myvar", "490jri", "e09jd9", "dlkjfoiej"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "e09jd9+myvar*490jri-$7=myvar0"; verify_case(1, Arg2, processParams(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "12342123$13231232$2123211242$a$dlkj$"; string Arr1[] = {"$2", "$1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "12342123$23231232$1123211242$a$dlkj$"; verify_case(2, Arg2, processParams(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "{[(+.*-,/\\:;<=>?@)]}_`~|$$1"; string Arr1[] = {"1{[(+.*-,/\\:;<=>?@)]}_`~|"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "{[(+.*-,/\\:;<=>?@)]}_`~|$1{[(+.*-,/\\:;<=>?@)]}_`~|"; verify_case(3, Arg2, processParams(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "$01"; string Arr1[] = {"abc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "$01"; verify_case(4, Arg2, processParams(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ParameterSubstitution ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
